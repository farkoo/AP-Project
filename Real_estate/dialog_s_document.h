#ifndef DIALOG_S_DOCUMENT_H
#define DIALOG_S_DOCUMENT_H

#include <QDialog>
#include <QFormLayout>
#include "mainwindow.h"

class Dialog_s_document : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_s_document(QWidget *parent = nullptr,QVector<Customer>::iterator=nullptr);
    ~Dialog_s_document();
    void settext();

public slots:
    void previousslot();
    void nextslot();

private:
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;
    QLineEdit* lineedit1;
    QLineEdit* lineedit2;
    QLineEdit* lineedit3;
    QTextEdit* textedit;
    QPushButton* previous;
    QPushButton* next;
    QFormLayout* flay;
    QHBoxLayout* pushbuttons;
    QVBoxLayout* all;
    QVector<Sale>::iterator i;
    QVector<Customer>::iterator it;
};

#endif // DIALOG_S_DOCUMENT_H
