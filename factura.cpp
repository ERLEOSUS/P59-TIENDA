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
    str.append("TIENDA ABARROTES \n");
    str.append("RUC/C.I: "+m_cliente->cedula());
    str.append("Nombre: "+m_cliente->name());
    str.append("Telefono: "+m_cliente->telefono());
    str.append("Correo electronico: "+m_cliente->email());
    str.append("Direccion: "+m_cliente->direccion());
    ui->outFactura->setPlainText(str);
}

void Factura::setCliente(Cliente *newCliente)
{
    m_cliente = newCliente;
}
