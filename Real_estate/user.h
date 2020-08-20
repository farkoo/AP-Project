#ifndef USER_H
#define USER_H

#include<QString>
#include<QVector>
#include"homes.h"
#include"apartment.h"
#include"exchange.h"


class User
{
protected:
    QString name;
    QString family;
    QString status;
    QString username;
    QString password;
    QString money;
    QString entertime;
    QString exittime;
public:
    User(QString, QString, QString, QString, QString, QString, QString, QString);
    User();
    QString get_name();
    QString get_family();
    QString get_status();
    QString get_username();
    QString get_password();
    QString get_money();
    QString get_entertime();
    QString get_exittime();
};

class Manager:public User{
private:
    QVector<North>::iterator it_northvillas;
    QVector<South>::iterator it_southvillas;
    QVector<Apartment>::iterator it_apartments;
   // template<class T>
    QVector<Rent>::iterator it_rents;
    QVector<Sale>::iterator it_sales;
public:
    Manager(QString, QString, QString, QString, QString, QString, QString, QString);
    Manager();
};

class Customer:public User{
    QVector<Manager>::iterator a;
public:
    Customer(QString, QString, QString, QString, QString, QString, QString, QString);
    Customer();
};

#endif // USER_H
