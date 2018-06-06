#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent):QSvgWidget(parent)
{
    render = renderer();
}

//void SvgWidget::wheelEvent(QWheelEvent *e) {
//    if(e->delta()>0) {
//        QDebug>>"zoom in";
//    } else {
//        QDebug>>"zoom out"
//    }
//}
