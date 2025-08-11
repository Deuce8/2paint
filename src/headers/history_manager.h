#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

#include <QObject>

#include "main_window.h"

struct AppState {
    QList<QImage> layers;
    int layerIndex;
    QSize dimensions;
};

class HistoryManager : public QObject {
    Q_OBJECT

public:
    HistoryManager(QObject *parent = nullptr, MainWindow *mainWindow = nullptr);

private:
    MainWindow *mainWindow;
    QList<AppState> snapshots;

public slots:
    void undo();
    void redo();

    void takeSnapshot();
};

#endif