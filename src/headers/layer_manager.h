#ifndef LAYER_MANAGER_H
#define LAYER_MANAGER_H

#include <QObject>
#include <QImage>

class Layer_Manager : public QObject {
    Q_OBJECT

public:
    Layer_Manager(QObject *parent = nullptr);

    QImage getCurrentLayer() const { return layers[layer_index]; };

private:
    int layer_index;
    QList<QImage> layers;

public slots:
    void clampView();

private slots:
    void updateImage();
};

#endif