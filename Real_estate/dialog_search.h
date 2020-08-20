#ifndef DIALOG_SEARCH_H
#define DIALOG_SEARCH_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

class Dialog_search : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_search(QWidget *parent = nullptr,int=0);
    ~Dialog_search();

    QPushButton *getCancel() const;
    void setCancel(QPushButton *value);

signals:
    void search_signal(QString);
    void search_signal(QString,QString);

public slots:
    void ok_slot();
    void cancel_slot();
private:
    int s;
    QLabel* hint;
    QLabel* label1;
    QLabel* label2;
    QLineEdit* lineedit1;
    QLineEdit* lineedit2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;
    QHBoxLayout* pushbuttons;
    QVBoxLayout* all;
    QPushButton* ok;
    QPushButton* cancel;
};

#endif // DIALOG_SEARCH_H
