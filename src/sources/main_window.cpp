#include "main_window.h"

#include <QVBoxLayout>
#include <QShortcut>
#include <QMimeData>
#include <QKeySequence>
#include <QFileInfo>
#include <QSettings>
#include <QFileDialog>

#pragma region Constructor

// Called when the main window is created
MainWindow::MainWindow(QWidget *parent, int argc, char *argv[]) : QMainWindow(parent) {
    // Window setup
    setFocusPolicy(Qt::ClickFocus);
    setWindowFlags(Qt::Window);
    setAcceptDrops(true);
    setWindowTitle(tr("2Paint"));
    
    // Window contents setup
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(centralWidget);
    centralLayout->setContentsMargins(12, 12, 12, 12);

    canvas = new Canvas(centralWidget);
    centralLayout->addWidget(canvas);

    infoToolbar = new InfoToolbar(centralWidget);
    centralLayout->addWidget(infoToolbar);

    setCentralWidget(centralWidget);

    // Signal & Slot binding
    connect(this, &MainWindow::pathLoaded, this, &MainWindow::loadImage);

    // Argument parsing, and loading provided files
    if (argc > 1)
        loadImage(QString::fromLocal8Bit(argv[1]));
}

#pragma endregion Constructor
#pragma region Public Slots

// This will take a raw image path, and load it into an QImage
void MainWindow::loadImage(const QString &path) {
    if (!QFileInfo::exists(path))
        return;
    
    QImage image(path);
    if (image.isNull())
        return;

    // Convert the image to a consistent format, and then emit the signal
    emit imageLoaded(image.convertToFormat(QImage::Format_ARGB32));
}

#pragma endregion Public Slots
#pragma region Protected

// Called when a file is dragged into the window
void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls() || event->mimeData()->hasImage())
        event->acceptProposedAction();
}

// Called when a file is dropped into the window, and accepted by the dragEnterEvent
void MainWindow::dropEvent(QDropEvent *event) {
    // Add returns to prevent loading an image multiple times. (Not sure if its neccesary, but idc)

    const QImage image = qvariant_cast<QImage>(event->mimeData()->imageData());
    if (!image.isNull()){
        emit imageLoaded(image.convertToFormat(QImage::Format_ARGB32));
        return;
    }

    const QList<QUrl> urls = event->mimeData()->urls();
    if(!urls.isEmpty())
        loadImage(urls.first().toLocalFile());
}

#pragma endregion Protected