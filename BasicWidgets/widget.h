#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    ~Widget();
private slots:
    void itemClicked(QListWidgetItem* item);
    void updateItem();
private:
    QPoint m_lastPos;
    QListWidget *m_widget;
    QLineEdit *m_edit;
    QPushButton *m_button;

};

#endif // WIDGET_H
