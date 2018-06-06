#include <QCoreApplication>
#include <QString>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString s1("Paris");
    QString s2("London");
    // string concatenation
    QString s = s1 + " " + s2 + "!";
    qDebug() << s ;

    QList<QString> list;
    list<<s1<<s2<<s1<<s2<<s1<<s2;

    QListIterator<QString> iter(list);
    while(iter.hasNext()) {
        qDebug() << iter.next();
        if(iter.hasNext()) {
            qDebug() << "-->";
        }
    }

    s = list.join("<-->") + "!";
    qDebug()<<s;
    return a.exec();
}
