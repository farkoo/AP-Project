#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QCheckBox>
#include<QMessageBox>
#include"user.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void managerslot(int);
    void customerslot(int);
    void cancelslot();
    void okslot();
signals:
    void oksignal(Manager);
    void oksignal(Customer);
private:
    QPushButton* ok;
    QPushButton* cancel;
    QLabel* name_label;
    QLabel* family_label;
    QLabel* username_label;
    QLabel* password_label;
    QLineEdit* name_line;
    QLineEdit* family_line;
    QLineEdit* username_line;
    QLineEdit* password_line;
    QCheckBox* manager_status;
    QCheckBox* customer_status;
    QVBoxLayout* label_lay;
    QVBoxLayout* lineedit_lay;
    QHBoxLayout* label_lineedit;
    QHBoxLayout* status_lay;
    QHBoxLayout* pushbutton_lay;
    QVBoxLayout* all;
};

#endif // DIALOG_H
