#ifndef CLIENTE_H
#define CLIENTE_H

#include <QObject>

class Cliente : public QObject
{
    Q_OBJECT
public:
    explicit Cliente(QObject *parent = nullptr);
    Cliente(const QString &cedula, const QString &name, const QString &telefono, const QString &email, const QString &direccion, QObject *parent = nullptr);

    const QString &cedula() const;
    void setCedula(const QString &newCedula);


    const QString &name() const;
    const QString &telefono() const;
    const QString &email() const;
    const QString &direccion() const;

signals:

private:
    QString m_cedula;
    QString m_name;
    QString m_telefono;
    QString m_email;
    QString m_direccion;
};

#endif // CLIENTE_H
