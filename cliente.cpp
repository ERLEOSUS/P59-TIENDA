#include "cliente.h"

Cliente::Cliente(QObject *parent) : QObject(parent)
{

}

const QString &Cliente::cedula() const
{
    return m_cedula;
}

void Cliente::setCedula(const QString &newCedula)
{
    m_cedula = newCedula;
}


const QString &Cliente::name() const
{
    return m_name;
}



const QString &Cliente::telefono() const
{
    return m_telefono;
}



const QString &Cliente::email() const
{
    return m_email;
}


const QString &Cliente::direccion() const
{
    return m_direccion;
}


Cliente::Cliente(const QString &cedula, const QString &name, const QString &telefono, const QString &email, const QString &direccion,QObject *parent) : QObject(parent),
    m_cedula(cedula),
    m_name(name),
    m_telefono(telefono),
    m_email(email),
    m_direccion(direccion)
{}
