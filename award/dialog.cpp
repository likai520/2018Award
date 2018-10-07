#include "dialog.h"
#include <QVBoxLayout>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("幸运大抽奖"));//设置窗口标题
    label1 = new QLabel;
    label1->setText(tr("开始幸运大抽奖"));
    QFont font;
    font.setBold(true);//设置字体为粗体
    font.setPointSize(10);//设置字号
    label1->setFont(font);

    btn1 = new QPushButton;
    btn1->setText(tr("开始"));

    QVBoxLayout *layout1 = new QVBoxLayout(this);
    layout1->addWidget(label1, 0, Qt::AlignCenter);//加入label1标签，并且居中显示
    layout1->addWidget(btn1);
   // layout1->setSizeConstraint(QLayout::SetFixedSize);//设置layout大小和控件尺寸一致,使窗口不能更改大小

    QFile file("../data.txt");
    if (file.open(QFile::ReadOnly))//以只读的方式打开student.txt文件
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            strlist.append(stream.readLine());//将文件内容放到strlist中
        }
        file.close();
    }else
    {
        //如果打开data.txt文件失败,程序退出
        QMessageBox::critical(this, tr("错误"), file.errorString());
        exit(0);
    }
    tm = new QTimer(this);
    connect(tm, SIGNAL(timeout()), this, SLOT(on_timer()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

Dialog::~Dialog()
{

}

void Dialog::on_clicked()
{
    static bool status = true;
    if (status)
    {
        btn1->setText("停止");//如果isok为true,设置按钮标题为“停止”
        tm->start(50);//启动计时器,没0.05秒执行一次on_timer函数
        status = false;
    }else
    {
        btn1->setText("开始");//如果isok为false,设置按钮标题为“开始”
        tm->stop();//停止计时器
        status = true;
    }
}

void Dialog::on_timer()
{
    if (strlist.count() == 0)
    {
        return ;//如果strlist中没有内容，函数返回
    }

    static int i = 0;
    label1->setText(strlist[i]);//从0到strlist.count(),循环显示strlist中每一项的内容
    i++;
    if (i >= strlist.count())
    {
        i = 0;
    }
}

