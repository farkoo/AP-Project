#include<Exchange.h>
#include<homes.h>
#include<QVector>
#include<mainwindow.h>

/*void Exchange::set_Home(T a)
{
    Home=a;
}*/
void Exchange::set_Commission(QString a)
{
    Commission=a;
}
/*T Exchange::get_Home(void)
{
    return Home;
}*/
QString Exchange::get_Commission(void)
{
    return Commission;
}
void Exchange::set_IDD(QString a)
{
    IDD=a;
}
void Sale::set_Terms_of_sale(QString a)
{
    Terms_of_sale=a;
}
void Sale::set_Final_price(void)
{
    //Final_price=a;
    //Final_price=QString::number(this->Home.get_Total_price().toDouble()+this->get_Commission().toDouble()*this->Home.get_Total_price().toDouble());
    if(this->IDD[0]=='N')
    {
        QVector<North>::iterator it;
        for(it=MainWindow::northvillas.begin();MainWindow::northvillas.end()!=it;it++)
            if(IDD==it->get_ID())
            {
                Final_price=QString::number(it->get_Total_price().toDouble()+this->get_Commission().toDouble()*it->get_Total_price().toDouble());
            }
    }
    else if(this->IDD[0]=='S')
    {
        QVector<South>::iterator it;
        for(it=MainWindow::southvillas.begin();MainWindow::southvillas.end()!=it;it++)
            if(IDD==it->get_ID())
            {
                Final_price=QString::number(it->get_Total_price().toDouble()+this->get_Commission().toDouble()*it->get_Total_price().toDouble());
            }
    }
}
QString Sale::get_Terms_of_sale(void)
{
    return Terms_of_sale;
}
QString Sale::get_Final_price(void)
{
    return Final_price;
}
void Rent::set_Mortage(QString a)
{
    Mortage=a;
}
void Rent::set_Lease_rate(QString a)
{
    Lease_rate=a;
}
void Rent::set_Lease_duration(QString a)
{
    Lease_duration=a;
}
void Rent::set_Final_price(void)
{
    if(this->IDD[0]=='N')
    {
        QVector<North>::iterator it;
        for(it=MainWindow::northvillas.begin();MainWindow::northvillas.end()!=it;it++)
            if(IDD==it->get_ID())
            {
                Final_price=QString::number(it->get_Total_price().toDouble()*(1/100)*this->get_Lease_duration().toDouble()+it->get_Total_price().toDouble()*(5/100)+it->get_Total_price().toDouble()*(5/100)*this->get_Commission().toDouble());
            }
    }
    else if(this->IDD[0]=='S')
    {
        QVector<South>::iterator it;
        for(it=MainWindow::southvillas.begin();MainWindow::southvillas.end()!=it;it++)
            if(IDD==it->get_ID())
            {
                Final_price=QString::number(it->get_Total_price().toDouble()*(1/100)*this->get_Lease_duration().toDouble()+it->get_Total_price().toDouble()*(5/100)+it->get_Total_price().toDouble()*(5/100)*this->get_Commission().toDouble());
            }
    }
}

QString Rent::get_Mortage(void)
{
    return Mortage;
}
QString Rent::get_Lease_rate(void)
{
    return Lease_rate;
}
QString Rent::get_Lease_duration(void)
{
    return Lease_duration;
}
QString Rent::get_Final_price(void)
{
    return Final_price;
}
