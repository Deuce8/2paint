#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QImage>

#include "info_toolbar.h"
#include "canvas.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int argc = 1, char *argv[] = nullptr);

public slots:
    void loadImage(const QString &path);

signals:
    void imageLoaded(const QImage &image);
    void pathLoaded(const QString &path);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    InfoToolbar *infoToolbar;
    Canvas *canvas;
};

#endif