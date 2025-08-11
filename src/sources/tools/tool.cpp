#include "tool.h"

#pragma region Constructor

Tool::Tool(QObject *parent, Canvas *canvas, LayerManager *layerManager) : QObject(parent), canvas(canvas), layerManager(layerManager) {
    connect(canvas, &Canvas::mousePressed, this, &Tool::mousePressed);
    connect(canvas, &Canvas::mouseReleased, this, &Tool::mouseReleased);
    connect(canvas, &Canvas::mouseMoved, this, &Tool::mouseMoved);
}

#pragma endregion Constructor
#pragma region Private Slots

void Tool::mousePressed(QMouseEvent *event){

}

void Tool::mouseReleased(QMouseEvent *event){
    
}

void Tool::mouseMoved(QMouseEvent *event){
    
}

#pragma endregion Private Slots