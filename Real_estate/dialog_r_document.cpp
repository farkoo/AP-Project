#include "dialog_r_document.h"

Dialog_r_document::Dialog_r_document(QWidget *parent,QVector<Customer>::iterator _it) :
    QDialog(parent)
{
    label1=new QLabel("ID:");
    label2=new QLabel("Commission:");
    label3=new QLabel("Final price:");
    label4=new QLabel("Mortgage:");
    label5=new QLabel("Lease rate:");
    label6=new QLabel("Lease duration:");
    lineedit1=new QLineEdit;
    lineedit2=new QLineEdit;
    lineedit3=new QLineEdit;
    lineedit4=new QLineEdit;
    lineedit5=new QLineEdit;
    lineedit6=new QLineEdit;
    previous=new QPushButton("Previous");
    next=new QPushButton("Next");
    flay=new QFormLayout;
    pushbuttons=new QHBoxLayout;
    all=new QVBoxLayout;

    flay->addRow(label1,lineedit1);
    flay->addRow(label2,lineedit2);
    flay->addRow(label3,lineedit3);
    flay->addRow(label4,lineedit4);
    flay->addRow(label5,lineedit5);
    flay->addRow(label6,lineedit6);
    pushbuttons->addWidget(previous);
    pushbuttons->addWidget(next);
    all->addLayout(flay);
    all->addLayout(pushbuttons);
    setLayout(all);

    lineedit1->setReadOnly(true);
    lineedit2->setReadOnly(true);
    lineedit3->setReadOnly(true);
    lineedit4->setReadOnly(true);
    lineedit5->setReadOnly(true);
    lineedit6->setReadOnly(true);

    it=_it;
    if(it->customer_rents.size()!=0)
        i=it->customer_rents.begin();

    connect(previous,SIGNAL(clicked()),this,SLOT(previousslot()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextslot()));

    if(it->customer_rents.size()<2){
        next->setEnabled(false);
        previous->setEnabled(false);

    }
    settext();
}

Dialog_r_document::~Dialog_r_document()
{

}

void Dialog_r_document::settext()
{
    if(it->customer_rents.size()!=0){
        lineedit1->setText(i->get_IDD());
        lineedit2->setText(i->get_Commission());
        lineedit3->setText(i->get_Final_price());
        lineedit4->setText(i->get_Mortgage());
        lineedit5->setText(i->get_Lease_rate());
        lineedit6->setText(i->get_Lease_duration());
    }
    else {
        lineedit1->setText("");
        lineedit2->setText("");
        lineedit3->setText("");
        lineedit4->setText("");
        lineedit5->setText("");
        lineedit6->setText("");
    }

}

void Dialog_r_document::previousslot()
{
    if(i==it->customer_rents.begin())
        i=it->customer_rents.end()-1;
    else
        i--;
    settext();
}

void Dialog_r_document::nextslot()
{
    i++;
    if(i==it->customer_rents.end())
        i=it->customer_rents.begin();
    settext();
}
