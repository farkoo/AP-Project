#include "hint_dialog.h"
#include<QLineEdit>
#include<QVBoxLayout>
#include<QWidget>
#include<QDesktopWidget>

Hint_Dialog::Hint_Dialog(QWidget *parent) :
    QDialog(parent)
{
    QDesktopWidget dw;
    int x=dw.width()*0.4;
    int y=dw.height()*0.3;
    setFixedSize(x,y);

    QLineEdit *line1=new QLineEdit("Search1: View Homes with a base price of less than x and a building area of more than y.");
    QLineEdit *line2=new QLineEdit("Search2: See the housings located in the z range.");
    QLineEdit *line3=new QLineEdit("Search3: View apartments with more than N houses.");
    QLineEdit *line4=new QLineEdit("Search4: View apartments with at least an empty house with an area of X.");
    QLineEdit *line5=new QLineEdit("Search5: Find apartments with at least a vacant house with room R.");
    QLineEdit *line6=new QLineEdit("Search6: View housing prices in whole order.");

    line1->setReadOnly(true);
    line2->setReadOnly(true);
    line3->setReadOnly(true);
    line4->setReadOnly(true);
    line5->setReadOnly(true);
    line6->setReadOnly(true);

    QVBoxLayout *lay=new QVBoxLayout();
    lay->addWidget(line1);
    lay->addWidget(line2);
    lay->addWidget(line3);
    lay->addWidget(line4);
    lay->addWidget(line5);
    lay->addWidget(line6);

    setLayout(lay);
}

Hint_Dialog::~Hint_Dialog()
{

}
