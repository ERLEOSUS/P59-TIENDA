#ifndef TIENDA_H
#define TIENDA_H

#include <QMainWindow>
#include <QList>
#include <QDebug>
#include <QMessageBox>

#include "producto.h"
#include "factura.h"
#include "cliente.h"

#define IVA 12

QT_BEGIN_NAMESPACE
namespace Ui { class Tienda; }
QT_END_NAMESPACE

class Tienda : public QMainWindow
{
    Q_OBJECT

public:
    Tienda(QWidget *parent = nullptr);
    ~Tienda();

private slots:
    void on_inProducto_currentIndexChanged(int index);
    void on_btnAgregar_released();

    void on_btnFinalizar_released();

    void on_btnFinalizar_2_clicked();

private:

    Ui::Tienda *ui;
    QList<Producto*> m_productos;
    Cliente *m_cliente;

    void cargarProductos();
    float m_subtotal;

    void calcular(float stProducto);
    bool verificarCI(QString as);
    bool agregarDatos();
    bool validarUser();
    void limpiar();
};
#endif // TIENDA_H
