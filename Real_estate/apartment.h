#ifndef APARTMENT_H
#define APARTMENT_H

#include<QString>
#include<QVector>
#include<QLabel>

static int A=0;
class Unit;
class Apartment
{
public:
    Apartment();
protected:
    QString total_space;
    QString base_price;
    QString elevetor;
    QString floor_number;
    QLabel image;
    QString address;
    QVector<Unit> units;
};

class Unit{
private:
    QString ID;
    QString floor;
    QLabel image;
    QString room_number;
    QString building_space;
public:
    Unit();
};

#endif // APARTMENT_H
