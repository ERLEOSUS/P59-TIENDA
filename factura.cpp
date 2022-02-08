#include "factura.h"
#include "ui_factura.h"

Factura::Factura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Factura)
{
    ui->setupUi(this);
    m_cliente=new Cliente();
}

Factura::~Factura()
{
    delete ui;
}



void Factura::imprimirFactura()
{
    QString str="";
    str.append("\tTIENDA ABARROTES UPS\n");
    for(int i=0;i<70;i++){
        str.append("-");
    }

    str.append("\nRUC/C.I: "+m_cliente->cedula()+ "\n");
    str.append("Nombre: "+m_cliente->name()+ "\n");
    str.append("Telefono: "+m_cliente->telefono()+ "\n");
    str.append("Correo electronico: "+m_cliente->email()+ "\n");
    str.append("Direccion: "+m_cliente->direccion()+ "\n");
    for(int i=0;i<70;i++){
        str.append("-");
    }
    str.append("\nCant\tProducto\tPrecio.U\tSubtotal\n");
    str.append(m_cliente->m_productos);
    ui->outFactura->setPlainText(str);
}

void Factura::setCliente(Cliente *newCliente)
{
    m_cliente = newCliente;
}

void Factura::on_btnGuardar_clicked()
{
    QDir direc;
     qDebug()<<direc.home().mkdir("Documents/Tienda");

     if(direc.home().mkdir("Documents/Tienda")){
         guardar();

     }else{
         guardar();
     }
}

void Factura::guardar()
{

    QDateTime c = QDateTime::currentDateTime();
    QString nameFormat = c.toString("ddMMyyyy_hhmmss");
    //Crear un archivo
    QFile archivo(QDir::homePath() + "/Documents/Tienda/" + nameFormat + ".txt");

    //Arbirlo para escritura
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        //Crear un stream de texto
        QTextStream salida(&archivo);
        salida << ui->outFactura->toPlainText();

        QMessageBox::information(this,tr("Informacion"),tr("El archivo fue guardado con exito"));
    }else{
        //Mensaje si no se pudo guardar
        QMessageBox::warning(this,
                             tr("Guardar datos"),
                             tr("No se pudo guardar el archivo"));
    }

    //Cerrar el archivo
    archivo.close();
}

