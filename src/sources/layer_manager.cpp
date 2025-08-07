#include "layer_manager.h"

#pragma region Constructor

LayerManager::LayerManager(QObject *parent, MainWindow *mainWindow) : QObject(parent), mainWindow(mainWindow) {
    
}

#pragma endregion Constructor
#pragma region Public Functions

#pragma endregion Public Functions
#pragma region Public Slots

void LayerManager::addLayer() {
    QImage newLayer(100, 100, QImage::Format_ARGB32);
    newLayer.fill(mainWindow->getSecondaryColor());

    layers.append(newLayer);
}

void LayerManager::removeLayer() {

}

void LayerManager::moveLayerUp() {

}

void LayerManager::moveLayerDown() {

}

#pragma endregion Public Slots
#pragma region Private Slots

#pragma endregion Private Slots