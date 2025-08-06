#include "canvas.h"

#include <QPainter>

#pragma region Constructor

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    connect(this, &Canvas::viewChanged, this, &Canvas::clampView);

    image = QImage(300, 300, QImage::Format_RGB32);
    image.fill(QColor("#ffffff"));

    zoom = 0.125;
    panning = false;
    offset = QPointF(0, 0);
    last_point = QPointF(0, 0);

    emit viewChanged();
}

#pragma endregion Constructor
#pragma region Public Slots

void Canvas::clampView(){
    const float w = width();
    const float h = height();
    const float zoomed_scale = zoom * scale();
    const float view_w = image.width() * zoomed_scale;
    const float view_h = image.height() * zoomed_scale;
    const float scaled_margins = margins * zoomed_scale;

    offset = QPointF((view_w < w) ? (w - view_w) / 2 : std::max(std::min(float(offset.x()), scaled_margins), w - view_w - scaled_margins), 
                     (view_h < h) ? (h - view_h) / 2 : std::max(std::min(float(offset.y()), scaled_margins), h - view_h - scaled_margins));
}

#pragma endregion Public Slots
#pragma region Private Functions

int Canvas::sizePrimary() const {
    if(image.isNull())
        return 0.0;

    return std::max(image.width(), image.height());
}

float Canvas::scale() const {
    if(image.isNull())
        return 0.0;

    float sx = static_cast<float>(width()) / image.width();
    float sy = static_cast<float>(height()) / image.height();

    return std::min(sx, sy);
}

#pragma endregion Private Functions
#pragma region Protected

void Canvas::paintEvent(QPaintEvent *) {
    if(image.isNull())
        return;

    QPainter painter(this);
    painter.translate(offset);
    painter.scale(zoom * scale(), zoom * scale());
    painter.drawPixmap(0, 0, QPixmap::fromImage(image));

    QPen pen(QColor("#ffffff80"));
    pen.setCosmetic(true);
    painter.setPen(pen);

    //Border and Grid
    const int w = image.width();
    const int h = image.height();

    //Border
    painter.drawLines(QList<QLine>{
        QLine(0, 0, 0, h),
        QLine(w, 0, w, h),
        QLine(0, 0, w, 0),
        QLine(0, h, w, h)
    });

    //Grid
    if(16 <= sizePrimary() / zoom)
        return;

    QList<QLine> lines;

    for (int x = 1; x < w; x++)
        lines.append(QLine(x, 0, x, h));
    for (int y = 1; y < h; y++)
        lines.append(QLine(0, y, w, y));

    painter.drawLines(lines);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::MiddleButton)
        return;
     
    panning = true;
    last_point = event->position();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() != Qt::MiddleButton)
        return;
     
    panning = false;
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if(!panning)
        return;

    offset += event->position() - last_point;
    last_point = event->position();

    emit viewChanged();
    update();
}

void Canvas::wheelEvent(QWheelEvent *event) {
    const float old_zoom = zoom;

    zoom *= event->angleDelta().y() > 0 ? 1.25 : 1 / 1.25;
    zoom = std::max(0.5f, std::min(zoom, float(sizePrimary()) / 10));

    offset = (offset - event->position()) * (zoom / old_zoom) + event->position();

    emit viewChanged();
    update();
}

#pragma endregion Protected