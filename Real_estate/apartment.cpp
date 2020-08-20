#include "apartment.h"

Apartment::Apartment()
{

}
Unit::Unit()
{
    A++;
    QString str="A";
    str=str+QString::number(A);
    ID=str;
}
