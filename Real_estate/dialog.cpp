#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    ok=new QPushButton("&Ok");
    cancel=new QPushButton("&Cancel");
    name_label=new QLabel("Name:");
    family_label=new QLabel("Family:");
    username_label=new QLabel("Username:");
    password_label=new QLabel("Password:");
    name_line=new QLineEdit;
    family_line=new QLineEdit;
    username_line=new QLineEdit;
    password_line=new QLineEdit;
    manager_status=new QCheckBox;
    customer_status=new QCheckBox;
    label_lay=new QVBoxLayout;
    lineedit_lay=new QVBoxLayout;
    label_lineedit=new QHBoxLayout;
    status_lay=new QHBoxLayout;
    pushbutton_lay=new QHBoxLayout;
    all=new QVBoxLayout;

    label_lay->addWidget(name_label);
    label_lay->addWidget(family_label);
    label_lay->addWidget(username_label);
    label_lay->addWidget(password_label);
    lineedit_lay->addWidget(name_line);
    lineedit_lay->addWidget(family_line);
    lineedit_lay->addWidget(username_line);
    lineedit_lay->addWidget(password_line);
    label_lineedit->addLayout(label_lay);
    label_lineedit->addLayout(lineedit_lay);
    status_lay->addWidget(manager_status);
    status_lay->addWidget(customer_status);
    pushbutton_lay->addWidget(ok);
    pushbutton_lay->addWidget(cancel);
    all->addLayout(label_lineedit);
    all->addLayout(status_lay);
    all->addLayout(pushbutton_lay);

    name_line->setPlaceholderText("Name");
    family_line->setPlaceholderText("Family");
    username_line->setPlaceholderText("Username");
    password_line->setPlaceholderText("Password");
    password_line->setEchoMode(QLineEdit::Password);
    manager_status->setText("Manager");
    customer_status->setText("Customer");
    this->setWindowTitle("Register");

    connect(manager_status,SIGNAL(stateChanged(int)),this,SLOT(managerslot(int)));
    connect(customer_status,SIGNAL(stateChanged(int)),this,SLOT(customerslot(int)));
    connect(cancel,SIGNAL(clicked()),this,SLOT(cancelslot()));
    connect(ok,SIGNAL(clicked()),SLOT(okslot()));

    setLayout(all);
}

Dialog::~Dialog()
{
}

void Dialog::managerslot(int state)
{
    if(state && customer_status->isChecked())
        customer_status->setCheckState(Qt::Unchecked);
}

void Dialog::customerslot(int state)
{
    if(state && manager_status->isChecked())
        manager_status->setCheckState(Qt::Unchecked);
}

void Dialog::cancelslot()
{
    this->close();
}

void Dialog::okslot()
{
    QString name,family,username,password;
    name=name_line->text();
    family=family_line->text();
    username=username_line->text();
    password=password_line->text();
    if(name=="")
        QMessageBox::information(this,"ERROR","You must enter name!!!");
    if(family=="")
        QMessageBox::information(this,"ERROR","You must enter family!!!");
    if(username=="")
        QMessageBox::information(this,"ERROR","You must enter username!!!");
    if(password=="")
        QMessageBox::information(this,"ERROR","You must enter password!!!");
    if(!manager_status->isChecked()&&!customer_status->isChecked())
        QMessageBox::information(this,"ERROR","You must choose between customer and manager!!!");
    if(customer_status->isChecked()){
        Customer t(name,family,"1",username,password,"0","","");
        emit oksignal(t);
        this->close();
    }
    else if (manager_status->isChecked()) {
        Manager t(name,family,"1",username,password,"0","","");
        emit oksignal(t);
        this->close();
    }
}
