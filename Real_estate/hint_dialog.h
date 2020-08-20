#ifndef HINT_DIALOG_H
#define HINT_DIALOG_H

#include <QDialog>


class Hint_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Hint_Dialog(QWidget *parent = nullptr);
    ~Hint_Dialog();

private:

};

#endif // HINT_DIALOG_H
