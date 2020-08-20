#include "dialog_money.h"

Dialog_money::Dialog_money(QWidget *parent,QString balance) :
    QDialog(parent)
{
    label1=new QLabel("Your balance:");
    label2=new QLabel("Your new balance:");
    lineedit1=new QLineEdit;
    lineedit2=new QLineEdit;
    ok=new QPushButton("Ok");
    cancel=new QPushButton("Cancel");
    labels=new QVBoxLayout;
    lineedits=new QVBoxLayout;
    total=new QHBoxLayout;
    pushbuttons=new QHBoxLayout;
    all=new QVBoxLayout;

    labels->addWidget(label1);
    labels->addWidget(label2);
    lineedits->addWidget(lineedit1);
    lineedits->addWidget(lineedit2);
    total->addLayout(labels);
    total->addLayout(lineedits);
    pushbuttons->addWidget(ok);
    pushbuttons->addWidget(cancel);
    all->addLayout(total);
    all->addLayout(pushbuttons);

    setLayout(all);

    lineedit1->setReadOnly(true);
    lineedit1->setText(balance);
    connect(ok,SIGNAL(clicked()),this,SLOT(okslot()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(cancelslot()));
}

Dialog_money::~Dialog_money()
{

}

void Dialog_money::okslot()
{
    if(lineedit2->text()==""){
        QMessageBox::information(this,"ERROR","You should fill this field!!!");
        return;
    }
    QMessageBox::information(this,"Increase","Balance changed successfully");
    emit oksignal(lineedit2->text());
    this->close();
}

void Dialog_money::cancelslot()
{
    this->close();
}
