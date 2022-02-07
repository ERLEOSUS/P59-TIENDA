#include "tienda.h"
#include "factura.h"
#include "QtDebug"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tienda w;
    w.show();

    return a.exec();
}
