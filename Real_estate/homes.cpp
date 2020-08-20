#include<QString>
#include<homes.h>

Villa::Villa()
{

}
void Villa::set_Building_area(QString a)
{
    Building_area=a;
}
void Villa::set_Total_area(QString a)
{
    Total_area=a;
}
void Villa::set_N_room(QString a)
{
    N_room=a;
}
void Villa::set_Image(QString a)
{
    Image=a;//////////  :)  image <-----> QString (:
}
void Villa::set_Base_price(QString a)
{
    Base_price=a;
}
void Villa::set_Address(QString a)
{
    Address=a;
}
/*void Villa::set_Total_price(QString a)
{
    Total_price=a;
}*/

QString Villa::get_Building_area(void)
{
    return Building_area;
}
QString Villa::get_Total_area(void)
{
    return Total_area;
}
QString Villa::get_N_room(void)
{
    return N_room;
}
QString Villa::get_Image(void)
{
    return Image;
}
QString Villa::get_Base_price(void)
{
    return Base_price;
}
QString Villa::get_Address(void)
{
    return Address;
}
QString Villa::get_Total_price(void)
{
    return Total_price;
}
QString Villa::get_ID(void)
{
    return ID;
}

North::North():Villa()
{
    N++;
    QString str="N";
    str=str+QString::number(N);
    ID=str;
}
void North::set_Front_yard(QString a)
{
    Front_yard=a;
}
void North::set_Back_yard(QString a)
{
    Back_yard=a;
}
void North::set_Total_price(void)
{
    //Total_price=a;
    Total_price=QString::number(this->get_Base_price().toDouble()*this->get_Building_area().toDouble()+this->get_Base_price().toDouble()*this->get_Front_yard().toDouble()*(3/10)+this->get_Base_price().toDouble()*get_Back_yard().toDouble()*(15/100));
}

QString North::get_Front_yard(void)
{
    return Front_yard;
}
QString North::get_Back_yard(void)
{
    return Back_yard;
}
//QString North::get_Total_price(void)
//{
//    return Total_price;
//}

South::South():Villa()
{
    S++;
    QString str="S";
    str=str+QString::number(S);
    ID=str;
}
void South::set_Yard_area(QString a)
{
    Yard_area=a;
}
void South::set_Parking_area(QString a)
{
    Parking_area=a;
}
void South::set_Total_price(void)
{
    //Total_price=a;
    Total_price=QString::number(this->get_Base_price().toDouble()*this->get_Building_area().toDouble()+this->get_Base_price().toDouble()*this->get_Yard_area().toDouble()*(3/10)+this->get_Base_price().toDouble()*get_Parking_area().toDouble()*(15/100));
}

QString South::get_Yard_area(void)
{
    return Yard_area;
}
QString South::get_Parking_area(void)
{
    return Parking_area;
}
//QString South::get_Total_price(void)
//{
//    return Total_price;
//}
