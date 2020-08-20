#include "mainwindow.h"

QVector<Manager> MainWindow::managerusers;
QVector<Customer> MainWindow::customerusers;
QVector<North> MainWindow::northvillas;
QVector<South> MainWindow::southvillas;
//QVector<Apartment> MainWindow::apartments;
QVector<Rent> MainWindow::rents;
QVector<Sale> MainWindow::sales;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    Register=new QPushButton("&Register");
    submit=new QPushButton("&Submit");
    cancel=new QPushButton("&Cancel");
    username_label=new QLabel("Username:");
    password_label=new QLabel("Password:");
    username_line=new QLineEdit;
    password_line=new QLineEdit;
    label_lay=new QVBoxLayout;
    lineedit_lay=new QVBoxLayout;
    label_lineedit=new QHBoxLayout;
    pushbutton_lay=new QHBoxLayout;
    all=new QVBoxLayout;
    center=new QWidget;

    label_lay->addWidget(username_label);
    label_lay->addWidget(password_label);
    lineedit_lay->addWidget(username_line);
    lineedit_lay->addWidget(password_line);
    label_lineedit->addLayout(label_lay);
    label_lineedit->addLayout(lineedit_lay);
    pushbutton_lay->addWidget(submit);
    pushbutton_lay->addWidget(Register);
    pushbutton_lay->addWidget(cancel);
    all->addLayout(label_lineedit);
    all->addLayout(pushbutton_lay);

    password_line->setEchoMode(QLineEdit::Password);
    username_line->setPlaceholderText("Username");
    password_line->setPlaceholderText("Password");
    this->setWindowTitle("Submit");

    connect(cancel,SIGNAL(clicked()),this,SLOT(cancelslot()));
    connect(Register,SIGNAL(clicked()),this,SLOT(registerslot()));
    connect(submit,SIGNAL(clicked()),this,SLOT(submitslot()));

    center->setLayout(all);
    setCentralWidget(center);
}

MainWindow::~MainWindow()
{
}

QVector<Manager>::iterator MainWindow::get_managerusers()
{
  return managerusers.begin();
}

QVector<Customer>::iterator MainWindow::get_customerusers()
{
    return customerusers.begin();
}

void MainWindow::cancelslot()
{
    this->close();
}

void MainWindow::registerslot()
{
    Dialog* registering=new Dialog(center);
    registering->show();
    connect(registering,SIGNAL(oksignal(Manager)),this,SLOT(createmanager(Manager)));
    connect(registering,SIGNAL(oksignal(Customer)),this,SLOT(createcustomer(Customer)));
}

void MainWindow::submitslot()
{
    QString username,password;
    username=username_line->text();
    password=password_line->text();
    if(username==""){
        QMessageBox::information(this,"ERROR","You must enter username!!!");
        return;
    }
    if(password==""){
        QMessageBox::information(this,"ERROR","You must enter password!!!");
        return;
    }
    for(auto i=managerusers.begin();i!=managerusers.end();i++)
        if(i->get_username()==username && i->get_password()==password){
            username_label->deleteLater();
            username_line->deleteLater();
            password_label->deleteLater();
            password_line->deleteLater();
            cancel->deleteLater();
            submit->deleteLater();
            Register->deleteLater();
            label_lay->destroyed();
            lineedit_lay->destroyed();
            label_lineedit->destroyed();
            pushbutton_lay->destroyed();
            all->destroyed();
            setWindowTitle("Manager");
            return;
        }
    for(auto i=customerusers.begin();i!=customerusers.end();i++)
        if(i->get_username()==username && i->get_password()==password){
            username_label->deleteLater();
            username_line->deleteLater();
            password_label->deleteLater();
            password_line->deleteLater();
            cancel->deleteLater();
            submit->deleteLater();
            Register->deleteLater();
            label_lay->destroyed();
            lineedit_lay->destroyed();
            label_lineedit->destroyed();
            pushbutton_lay->destroyed();
            all->destroyed();
            setWindowTitle("Customer");
            return;
        }
     QMessageBox::information(this,"ERROR","Username or password is wrong!!!");
}

void MainWindow::createmanager(Manager m)
{
    managerusers.push_back(m);
}

void MainWindow::createcustomer(Customer c)
{
    customerusers.push_back(c);
}

QVector<North>::iterator MainWindow::get_northvillas()
{
    return northvillas.begin();
}

QVector<South>::iterator MainWindow::get_southvillas()
{
    return southvillas.begin();
}

/*QVector<Apartment>::iterator MainWindow::get_apartments()
{
    return apartments.begin();
}*/

QVector<Rent>::iterator MainWindow::get_rents()
{
    return rents.begin();
}

QVector<Sale>::iterator MainWindow::get_sales()
{
    return sales.begin();
}
QVector<QString> search1(QString x, QString y)
{
    QVector<QString> vector;
    QVector<North>::iterator it;
    for(it=MainWindow::northvillas.begin();it!=MainWindow::northvillas.end();it++)
        if(it->get_Base_price().toDouble()<x.toDouble() && it->get_Building_area().toDouble()>y.toDouble())
            vector.push_back(it->get_ID());
    QVector<South>::iterator itt;
    for(itt=MainWindow::southvillas.begin();itt!=MainWindow::southvillas.end();itt++)
        if(itt->get_Base_price().toDouble()<x.toDouble() && itt->get_Building_area().toDouble()>y.toDouble())
            vector.push_back(itt->get_ID());
    //////////////////////??????????????????????apaaaaaaaaaartemaaaaaaaaaan
}
QVector<QString> search2(QString z)
{

}
