#include "dialog_request.h"

Dialog_request::Dialog_request(QWidget *parent) :
    QDialog(parent)
{
    label1=new QLabel;
    accept=new QPushButton("Accept");
    reject=new QPushButton("Reject");
    next=new QPushButton("Next");
    previous=new QPushButton("Previous");
    lay1=new QHBoxLayout;
    lay2=new QHBoxLayout;
    all=new QVBoxLayout;

    lay1->addWidget(label1);
    lay1->addWidget(accept);
    lay1->addWidget(reject);
    lay2->addWidget(previous);
    lay2->addWidget(next);
    all->addLayout(lay1);
    all->addLayout(lay2);

    setLayout(all);

    connect(accept,SIGNAL(clicked()),this,SLOT(acceptslot()));
    connect(reject,SIGNAL(clicked()),this,SLOT(rejectslot()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextslot()));
    connect(previous,SIGNAL(clicked()),this,SLOT(previousslot()));

    for(auto i=MainWindow::r_request.begin();i!=MainWindow::r_request.end();i++)
        r_s_requests.push_back(*i);
    for(auto i=MainWindow::s_request.begin();i!=MainWindow::s_request.end();i++)
        r_s_requests.push_back(*i);

    if(r_s_requests.size()<2){
        next->setEnabled(false);
        previous->setEnabled(false);
    }

    it=r_s_requests.begin();
    set_text();
}

Dialog_request::~Dialog_request()
{

}

void Dialog_request::set_text()
{
    QString text;
    text.append("User with username ");
    text.append(it->first);
    text.append(" requested to ");
    for(auto i=MainWindow::r_request.begin();i!=MainWindow::r_request.end();i++)
        if(*i==*it)
            text.append("rent");
    for(auto i=MainWindow::s_request.begin();i!=MainWindow::s_request.end();i++)
        if(*i==*it)
            text.append("sale");
    text.append(" house with ID ");
    text.append(it->second);
    label1->setText(text);
}

void Dialog_request::rejectslot()
{
    int x=0;
    for(auto i=MainWindow::r_request.begin();i!=MainWindow::r_request.end();i++)
        if(*i==*it){
            MainWindow::r_request.erase(i);
            x=1;
            break;
        }
    for(auto i=MainWindow::s_request.begin();i!=MainWindow::s_request.end();i++)
        if(*i==*it){
            MainWindow::s_request.erase(i);
            x=2;
            break;
        }
    if(x==1){
        for(auto i=MainWindow::rents.begin();i!=MainWindow::rents.end();i++)
            if(i->get_IDD()==it->second)
                for(auto j=MainWindow::customerusers.begin();j!=MainWindow::customerusers.end();j++)
                    if(j->get_username()==it->first)
                        j->set_money(QString::number(j->get_money().toDouble()+i->get_Final_price().toDouble()));
    }
    else if(x==2){
        for(auto i=MainWindow::sales.begin();i!=MainWindow::sales.end();i++)
            if(i->get_IDD()==it->second)
                for(auto j=MainWindow::customerusers.begin();j!=MainWindow::customerusers.end();j++)
                    if(j->get_username()==it->first)
                        j->set_money(QString::number(j->get_money().toDouble()+i->get_Final_price().toDouble()));
    }

    r_s_requests.erase(it);
    it=r_s_requests.begin();

    if(r_s_requests.size()<2){
        next->setEnabled(false);
        previous->setEnabled(false);
    }
    if(r_s_requests.size()==0){
        QMessageBox::information(this,"Message","Requests finished");
        this->close();
    }

    set_text();
}

void Dialog_request::acceptslot()
{
    QString commission;
    for(auto i=MainWindow::r_request.begin();i!=MainWindow::r_request.end();i++)
        if(*i==*it){
            for(auto j=MainWindow::customerusers.begin();j!=MainWindow::customerusers.end();j++)
                if(j->get_username()==i->first){
                    for(auto k=MainWindow::rents.begin();k!=MainWindow::rents.end();k++)
                        if(k->get_IDD()==i->second){
                            commission=k->get_Commission();
                            j->customer_rents.push_back(*k);
                            MainWindow::rents.erase(k);
                            break;
                        }
                    break;
                }
            MainWindow::r_request.erase(i);
            break;
        }
    for(auto i=MainWindow::s_request.begin();i!=MainWindow::s_request.end();i++)
        if(*i==*it){
            for(auto j=MainWindow::customerusers.begin();j!=MainWindow::customerusers.end();j++)
                if(j->get_username()==i->first){
                    for(auto k=MainWindow::sales.begin();k!=MainWindow::sales.end();k++)
                        if(k->get_IDD()==i->second){
                            commission=k->get_Commission();
                            j->customer_sales.push_back(*k);
                            MainWindow::sales.erase(k);
                            break;
                        }
                    break;
                }
            for(auto i=MainWindow::managerusers.begin();i!=MainWindow::managerusers.end();i++)
                i->set_money(QString::number(i->get_money().toDouble()+commission.toDouble()));
                MainWindow::s_request.erase(i);
                break;
        }

    if(it->second[0]=='N'){
        for(auto i=MainWindow::northvillas.begin();i!=MainWindow::northvillas.end();i++)
            if(i->get_ID()==it->second){
                MainWindow::northvillas.erase(i);
                break;
            }
    }
    else if(it->second[0]=='S'){
        for(auto i=MainWindow::southvillas.begin();i!=MainWindow::southvillas.end();i++)
            if(i->get_ID()==it->second){
                MainWindow::southvillas.erase(i);
                break;
            }
    }
    else if(it->second[0]=='A'){
        for(auto i=MainWindow::apartments.begin();i!=MainWindow::apartments.end();i++)
            if(i->get_ID()==it->second){
                MainWindow::apartments.erase(i);
                break;
            }
    }
    else if(it->second[0]=='U'){
        for(auto i=MainWindow::units.begin();i!=MainWindow::units.end();i++)
            if(i->get_ID()==it->second){
                MainWindow::units.erase(i);
                break;
            }
    }

    r_s_requests.erase(it);
    it=r_s_requests.begin();

    if(r_s_requests.size()<2){
        next->setEnabled(false);
        previous->setEnabled(false);
    }
    if(r_s_requests.size()==0){
        QMessageBox::information(this,"Message","Requests finished");
        this->close();
    }

    set_text();
}

void Dialog_request::nextslot()
{
    it++;
    if(it==r_s_requests.end())
        it=r_s_requests.begin();
    set_text();
}

void Dialog_request::previousslot()
{
    if(it==r_s_requests.begin())
        it=r_s_requests.end()-1;
    else
        it--;
    set_text();
}

