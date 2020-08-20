#include "dialog_s_document.h"
#include"mainwindow.h"

Dialog_s_document::Dialog_s_document(QWidget *parent,QVector<Customer>::iterator _it) :
    QDialog(parent)
{

    label1=new QLabel("ID:");
    label2=new QLabel("Commission:");
    label3=new QLabel("Final price:");
    label4=new QLabel("Term of sale:");
    lineedit1=new QLineEdit;
    lineedit2=new QLineEdit;
    lineedit3=new QLineEdit;
    textedit=new QTextEdit;
    previous=new QPushButton("Previous");
    next=new QPushButton("Next");
    flay=new QFormLayout;
    pushbuttons=new QHBoxLayout;
    all=new QVBoxLayout;

    flay->addRow(label1,lineedit1);
    flay->addRow(label2,lineedit2);
    flay->addRow(label3,lineedit3);
    flay->addRow(label4,textedit);
    pushbuttons->addWidget(previous);
    pushbuttons->addWidget(next);
    all->addLayout(flay);
    all->addLayout(pushbuttons);
    setLayout(all);

    lineedit1->setReadOnly(true);
    lineedit2->setReadOnly(true);
    lineedit3->setReadOnly(true);
    textedit->setReadOnly(true);

    it=_it;
    if(it->customer_sales.size()!=0)
        i=it->customer_sales.begin();

    connect(previous,SIGNAL(clicked()),this,SLOT(previousslot()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextslot()));

    if(it->customer_sales.size()<2){
        next->setEnabled(false);
        previous->setEnabled(false);

    }
    settext();
}

Dialog_s_document::~Dialog_s_document()
{

}

void Dialog_s_document::settext()
{
    if(it->customer_sales.size()!=0){
        lineedit1->setText(i->get_IDD());
        lineedit2->setText(i->get_Commission());
        lineedit3->setText(i->get_Final_price());
        textedit->setText(i->get_Terms_of_sale());
    }
    else {
        lineedit1->setText("");
        lineedit2->setText("");
        lineedit3->setText("");
        textedit->setText("");
    }

}

void Dialog_s_document::previousslot()
{
    if(i==it->customer_sales.begin())
        i=it->customer_sales.end()-1;
    else
        i--;
    settext();
}

void Dialog_s_document::nextslot()
{
    i++;
    if(i==it->customer_sales.end())
        i=it->customer_sales.begin();
    settext();
}
