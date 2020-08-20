#ifndef DIALOG_MONEY_H
#define DIALOG_MONEY_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QMessageBox>

class Dialog_money : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_money(QWidget *parent = nullptr,QString="");
    ~Dialog_money();

public slots:
    void okslot();
    void cancelslot();

signals:
    void oksignal(QString);

private:
    QLabel* label1;
    QLabel* label2;
    QLineEdit* lineedit1;
    QLineEdit* lineedit2;
    QPushButton* ok;
    QPushButton* cancel;
    QVBoxLayout* labels;
    QVBoxLayout* lineedits;
    QHBoxLayout* total;
    QHBoxLayout* pushbuttons;
    QVBoxLayout* all;
};

#endif // DIALOG_MONEY_H
