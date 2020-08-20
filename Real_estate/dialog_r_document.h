#ifndef DIALOG_R_DOCUMENT_H
#define DIALOG_R_DOCUMENT_H

#include <QDialog>
#include <QFormLayout>
#include<mainwindow.h>

class Dialog_r_document : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_r_document(QWidget *parent = nullptr,QVector<Customer>::iterator=nullptr);
    ~Dialog_r_document();
    void settext();

public slots:
    void previousslot();
    void nextslot();

private:
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;
    QLabel* label5;
    QLabel* label6;
    QLineEdit* lineedit1;
    QLineEdit* lineedit2;
    QLineEdit* lineedit3;
    QLineEdit* lineedit4;
    QLineEdit* lineedit5;
    QLineEdit* lineedit6;
    QPushButton* previous;
    QPushButton* next;
    QFormLayout* flay;
    QHBoxLayout* pushbuttons;
    QVBoxLayout* all;
    QVector<Rent>::iterator i;
    QVector<Customer>::iterator it;
private:

};

#endif // DIALOG_R_DOCUMENT_H
