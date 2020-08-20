#ifndef DIALOG_REQUEST_H
#define DIALOG_REQUEST_H

#include <QDialog>
#include "mainwindow.h"

class Dialog_request : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_request(QWidget *parent = nullptr);
    ~Dialog_request();

    void set_text();

    QVector<pair<QString,QString>> r_s_requests;
    QVector<pair<QString,QString>>::iterator it;

public slots:
    void rejectslot();
    void acceptslot();
    void nextslot();
    void previousslot();

private:
    QLabel* label1;
    QPushButton* accept;
    QPushButton* reject;
    QPushButton* next;
    QPushButton* previous;
    QHBoxLayout* lay1;
    QHBoxLayout* lay2;
    QVBoxLayout* all;
};

#endif // DIALOG_REQUEST_H
