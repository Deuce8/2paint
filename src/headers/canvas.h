#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDragEnterEvent>

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);
};

#endif