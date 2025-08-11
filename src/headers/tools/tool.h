#ifndef TOOL_H
#define TOOL_H

#include <QObject>

#include <layer_manager.h>
#include <canvas.h>

class Tool : public QObject {
    Q_OBJECT

public:
    Tool(QObject *parent = nullptr, Canvas *canvas = nullptr, LayerManager *layerManager = nullptr);

private:
    Canvas *canvas;
    LayerManager *layerManager;

private slots:
    void mousePressed(QMouseEvent *event);
    void mouseReleased(QMouseEvent *event);
    void mouseMoved(QMouseEvent *event);
};

#endif