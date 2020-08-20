#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QWidget>
#include<QVector>
#include<QMessageBox>
#include"user.h"
#include"dialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static QVector<Manager> managerusers;
    static QVector<Customer> customerusers;
    static QVector<North> northvillas;
    static QVector<South> southvillas;
    static QVector<Apartment> apartments;
    static QVector<Rent> rents;
    static QVector<Sale> sales;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QVector<Manager>::iterator get_managerusers();
    static QVector<Customer>::iterator get_customerusers();
    static QVector<North>::iterator get_northvillas();
    static QVector<South>::iterator get_southvillas();
    //static QVector<Apartment>::iterator get_apartments();
    static QVector<Rent>::iterator get_rents();
    static QVector<Sale>::iterator get_sales();
public slots:
    void cancelslot();
    void registerslot();
    void submitslot();
    void createmanager(Manager);
    void createcustomer(Customer);

private:
    QPushButton* Register;
    QPushButton* submit;
    QPushButton* cancel;
    QLabel* username_label;
    QLabel* password_label;
    QLineEdit* username_line;
    QLineEdit* password_line;
    QVBoxLayout* label_lay;
    QVBoxLayout* lineedit_lay;
    QHBoxLayout* label_lineedit;
    QHBoxLayout* pushbutton_lay;
    QVBoxLayout* all;
    QWidget* center;
    /*static QVector<Manager> managerusers;
    static QVector<Customer> customerusers;
    static QVector<North> northvillas;
    static QVector<South> southvillas;
    static QVector<Apartment> apartments;
    static QVector<Rent> rents;
    static QVector<Sale> sales;*/
};

#endif // MAINWINDOW_H
