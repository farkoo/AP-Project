#include "user.h"
#include"mainwindow.h"

User::User(QString _name,QString _family,QString _status,QString _username,QString _password,QString _money,
           QString _entertime,QString _exittime)
{
    name=_name;
    family=_family;
    status=_status;
    username=_username;
    password=_password;
    money=_money;
    entertime=_entertime;
    exittime=_exittime;
}

User::User()
{

}

QString User::get_name()
{
    return name;
}

QString User::get_family()
{
    return family;
}

QString User::get_status()
{
    return status;
}

QString User::get_username()
{
    return username;
}

QString User::get_password()
{
    return password;
}

QString User::get_money()
{
    return money;
}

QString User::get_entertime()
{
    return entertime;
}

QString User::get_exittime()
{
    return exittime;
}

Manager::Manager(QString _name,QString _family,QString _status,QString _username,QString _password,QString _money,
                 QString _entertime,QString _exittime):User(_name, _family, _status, _username, _password, _money,
                                                            _entertime, _exittime)
{
    it_northvillas=MainWindow::get_northvillas();
    it_southvillas=MainWindow::get_southvillas();
    //it_apartments=MainWindow::get_apartments();
    it_rents=MainWindow::get_rents();
    it_sales=MainWindow::get_sales();
}

Manager::Manager():User()
{

}

Customer::Customer(QString _name,QString _family,QString _status,QString _username,QString _password,QString _money,
                   QString _entertime,QString _exittime):User(_name, _family, _status, _username, _password, _money,
                                                              _entertime, _exittime)
{

}

Customer::Customer():User()
{

}
