#include "dialog_search.h"
#include<QDesktopWidget>

Dialog_search::Dialog_search(QWidget *parent,int x) :
    QDialog(parent)
{
    QDesktopWidget dw;
    int xx=dw.width()*0.2;
    int y=dw.height()*0.2;
    setFixedSize(xx,y);

    s=x;
    hint=new QLabel;
    label1=new QLabel;
    label2=new QLabel;
    lineedit1=new QLineEdit;
    lineedit2=new QLineEdit;
    layout1=new QVBoxLayout;
    layout2=new QVBoxLayout;
    layout3=new QHBoxLayout;
    pushbuttons=new QHBoxLayout;
    ok=new QPushButton("Ok");
    cancel=new QPushButton("Cancel");
    all=new QVBoxLayout;

    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout2->addWidget(lineedit1);
    layout2->addWidget(lineedit2);
    layout3->addLayout(layout1);
    layout3->addLayout(layout2);
    pushbuttons->addWidget(ok);
    pushbuttons->addWidget(cancel);
    all->addWidget(hint);
    all->addLayout(layout3);
    all->addLayout(pushbuttons);

    setLayout(all);

    if(s==1){
        label1->setText("X");
        label2->setText("Y");
        hint->setText("Finding a painkiller with a base price of less than X\n and a building area of ​​more than Y.");
    }
    else if(s==2){
        label1->setText("Z");
        label2->hide();
        lineedit2->hide();
        hint->setText("See Housing in the vicinity of Z Street.");
    }
    else if(s==3){
        label1->setText("N");
        label2->hide();
        lineedit2->hide();
        hint->setText("View apartments that have more than 𝑁 houses.");
    }
    else if(s==4){
        label1->setText("X");
        label2->hide();
        lineedit2->hide();
        hint->setText("View apartments with at least a vacant house with an area of ​​𝑋.");
    }
    else if(s==5){
        label1->setText("R");
        label2->hide();
        lineedit2->hide();
        hint->setText("View apartments with at least an empty house\nwith room.");
    }
    connect(ok,SIGNAL(clicked()),this,SLOT(ok_slot()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(cancel_slot()));
}

Dialog_search::~Dialog_search()
{
}

void Dialog_search::ok_slot()
{
    if(s==1){
        if(lineedit1->text()==""||lineedit2->text()==""){
            QMessageBox::information(this,"ERROR","You should fill all fields!!!");
            return;
        }
        emit search_signal(lineedit1->text(),lineedit2->text());
    }
    else {
        if(lineedit1->text()==""){
            QMessageBox::information(this,"ERROR","You should fill this field!!!");
            return;
        }
        emit search_signal(lineedit1->text());
    }
    this->close();
}

void Dialog_search::cancel_slot()
{
    this->close();
}

