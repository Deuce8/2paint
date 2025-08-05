#ifndef INFO_TOOLBAR_H
#define INFO_TOOLBAR_H

#include <QToolBar>
#include <QShowEvent>
#include <QLineEdit>
#include <QAction>

#include "canvas.h"

class InfoToolbar : public QToolBar {
    Q_OBJECT

public:
    InfoToolbar(QWidget *parent = nullptr, Canvas *canvas = nullptr);
};

#endif