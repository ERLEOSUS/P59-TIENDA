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
    str.append("\tTIENDA ABARROTES UPS \n");
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
