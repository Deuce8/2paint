#ifndef LAYER_MANAGER_H
#define LAYER_MANAGER_H

#include <QObject>
#include <QImage>

#include "main_window.h"

class LayerManager : public QObject {
    Q_OBJECT

public:
    LayerManager(QObject *parent = nullptr, MainWindow *mainWindow = nullptr);

    QImage getCurrentLayer() const { return layers[layer_index]; };

private:
    MainWindow *mainWindow;

    int layer_index;
    QSize dimensions;
    QList<QImage> layers;

public slots:
    void addLayer();
    void removeLayer();
    void moveLayerUp();
    void moveLayerDown();

    void clampView();

private slots:
    void updateImage();
};

#endif