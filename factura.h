#ifndef FACTURA_H
#define FACTURA_H

#include <QDialog>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QDir>

#include "tienda.h"
#include "cliente.h"

using namespace std;

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



private slots:
    void on_btnGuardar_clicked();

private:
    Ui::Factura *ui;
    Cliente *m_cliente;
    void guardar();

};

#endif // FACTURA_H
