#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QImage>

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);

private:
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

signals:
    void viewChanged();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
};

#endif