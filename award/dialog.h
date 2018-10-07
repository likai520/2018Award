#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QStringList>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void on_clicked();
    void on_timer();
private:
    QLabel *label1;
    QPushButton *btn1;
    QTimer *tm;
    QStringList strlist;
};


#endif // DIALOG_H
