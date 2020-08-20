#ifndef HOMES_H
#define HOMES_H
#include<QString>
using namespace std;
static int N=0,S=0;
class Villa
{
protected:
    QString ID;
    QString Building_area;
    QString Total_area;
    QString N_room;
    QString Image;
    QString Base_price;
    QString Address;
    QString Total_price;
public:
    Villa();
    void set_Building_area(QString);
    void set_Total_area(QString);
    void set_N_room(QString);
    void set_Image(QString);
    void set_Base_price(QString);
    void set_Address(QString);
    //void set_Total_price(QString);

    QString get_Building_area(void);
    QString get_Total_area(void);
    QString get_N_room(void);
    QString get_Image(void);
    QString get_Base_price(void);
    QString get_Address(void);
    QString get_Total_price(void);
    QString get_ID(void);
};
class North:public Villa
{
private:
    QString Front_yard;
    QString Back_yard;
    //QString Total_price;
public:
    North();
    void set_Front_yard(QString);
    void set_Back_yard(QString);
    void set_Total_price(void);

    QString get_Front_yard(void);
    QString get_Back_yard(void);
    //QString get_Total_price(void);
};
class South:public Villa
{
private:
    QString Yard_area;
    QString Parking_area;
    //QString Total_price;
public:
    South();
    void set_Yard_area(QString);
    void set_Parking_area(QString);
    void set_Total_price(void);

    QString get_Yard_area(void);
    QString get_Parking_area(void);
    //QString get_Total_price(void);
};

#endif // HOMES_H
