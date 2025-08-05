#include "info_toolbar.h"

#include <QHBoxLayout>
#include <QShortcut>
#include <QKeySequence>

#pragma region Constructor

// Called when the info toolbar is created
InfoToolbar::InfoToolbar(QWidget *parent, Canvas *canvas) : QToolBar(parent) {
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setOrientation(Qt::Horizontal);
    setStyleSheet("QToolBar{spacing:0px;}");
}

#pragma endregion Constructor