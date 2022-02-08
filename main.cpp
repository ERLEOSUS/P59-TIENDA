#include "tienda.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QLocale>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale location;
    QString text = location.languageToString(location.language());

    QTranslator traducion;

    if(text == "Russian"){

        traducion.load(":/tienda_ruso.qm");
    } else{
         traducion.load(":/tienda_en.qm");
    }

    if((text != "Russian") && (text != "Spanish")&& (text != "English")){
        QMessageBox::warning(NULL,"Advertencia","No se encontro el idioma de su sistema operativo dentro de la base de datos, se cargara el idioma por defecto");
    }
    if(text != QLocale::Spanish){
        a.installTranslator(&traducion);
    }


        Tienda w;
        w.show();
    return a.exec();
}
