#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("SVG Viewer"));
    createMenu();
    svgWindow = new SvgWindow;
    setCentralWidget(svgWindow);
}

void MainWindow::createMenu() {
    QMenu *fileMenu = menuBar()->addMenu(tr("Open SVG File"));
    QAction *openAct = new QAction(tr("Open File"), this);
    connect(openAct, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
    fileMenu->addAction(openAct);
}
void MainWindow::slotOpenFile() {
    QString name=QFileDialog::getOpenFileName(this, "Open My Svg File", "/", "svg files(*.svg)");
    svgWindow->setFile(name);
}
MainWindow::~MainWindow()
{

}
