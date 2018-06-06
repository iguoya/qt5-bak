#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent):QScrollArea(parent)
{
    svgWidget = new SvgWidget;
    setWidget(svgWidget);
}

void SvgWindow::setFile(QString fileName) {
    svgWidget->load(fileName);
    QSvgRenderer *render = svgWidget->renderer();
    svgWidget->resize(render->defaultSize());
}
