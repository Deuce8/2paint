#include "history_manager.h"

#pragma region Constructor

HistoryManager::HistoryManager(QObject *parent, MainWindow *mainWindow) : QObject(parent), mainWindow(mainWindow) {
    
}

#pragma endregion Constructor
#pragma region Public Slots

void HistoryManager::undo(){

}

void HistoryManager::redo(){
    
}

void HistoryManager::takeSnapshot(){
    
}

#pragma endregion Public Slots