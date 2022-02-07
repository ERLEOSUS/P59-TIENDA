#ifndef FACTURA_H
#define FACTURA_H

#include <QMainWindow>
#include "tienda.h"
#include "cliente.h"

namespace Ui {
class Factura;
}

class Factura : public QMainWindow
{
    Q_OBJECT

public:
    explicit Factura(QWidget *parent = nullptr);
    ~Factura();

    void imprimirFactura();


    void setCliente(Cliente *newCliente);

private:
    Ui::Factura *ui;

    Cliente *m_cliente;

};

#endif // FACTURA_H
