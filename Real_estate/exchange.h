#ifndef EXCHANGE_H
#define EXCHANGE_H
#include<QString>
//template<class T>
class Exchange
{
protected:
    //T Home;
    QString IDD;
    QString Commission;
    QString Final_price;/////???????
public:
    //void set_Home(T);
    void set_Commission(QString);
    //T get_Home(void);
    QString get_Commission(void);
    void set_IDD(QString);
};
class Sale:public Exchange
{
private:
    QString Terms_of_sale;
    //QString Final_price;
public:

    void set_Terms_of_sale(QString);
    void set_Final_price(void);

    QString get_Terms_of_sale(void);
    QString get_Final_price(void);
};
class Rent:public Exchange
{
private:
    QString Mortage;
    QString Lease_rate;
    QString Lease_duration;
    //QString Final_price;
public:
    void set_Mortage(QString);
    void set_Lease_rate(QString);
    void set_Lease_duration(QString);
    void set_Final_price(void);

    QString get_Mortage(void);
    QString get_Lease_rate(void);
    QString get_Lease_duration(void);
    QString get_Final_price(void);
};

#endif // EXCHANGE_H
