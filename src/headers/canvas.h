#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QImage>

#include <layer_manager.h>

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr, LayerManager *layerManager = nullptr);

private:
    LayerManager *layerManager;
    QImage image;

    float zoom;
    bool panning;
    QPointF offset;
    QPointF last_point;

    int sizePrimary() const;
    float scale() const;

    static const int margins = 16;

public slots:
    void clampView();
    void setImage(const QImage &image) { this->image = image; };

signals:
    void requestImage();
    void viewChanged();
    void mousePressed(QMouseEvent *event);
    void mouseReleased(QMouseEvent *event);
    void mouseMoved(QMouseEvent *event);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
};

#endif