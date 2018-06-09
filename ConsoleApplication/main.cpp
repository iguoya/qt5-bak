//#include <QCoreApplication>
#include <QtCore>

// text stream is text-codec aware
QTextStream cout(stdout, QIODevice::WriteOnly);

int main(int argc, char *argv[])
{
    // avoid compiler warnings
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    QString s1("Paris");
    QString s2("London");
    // string concatenation
    QString s = s1 + " " + s2 + "!";
    cout << s << endl;


    QString s3("Hello");
    QString s4("Qt");
    QList<QString> list;
    // stream into containers
    list <<  s3 << s4;
    // Java and STL like iterators
    QListIterator<QString> iter(list);
    while(iter.hasNext()) {
        cout << iter.next();
        if(iter.hasNext()) {
            cout << "   ";
        }
    }
    cout << "!" << endl;

    QStringList slist;
    slist <<  s3 << s4;
    // join strings
    QString ss = slist.join(" -- ") + "!";
    cout << ss << endl;
}
