#include "dialog.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/cn.qm");
    a.installTranslator(&translator);
    Dialog w;
    w.show();

    return a.exec();
}
