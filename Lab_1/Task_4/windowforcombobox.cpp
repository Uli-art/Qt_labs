#include "windowforcombobox.h"
#include "ui_windowforcombobox.h"

WindowForComboBox::WindowForComboBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowForComboBox)
{
    ui->setupUi(this);
}

WindowForComboBox::~WindowForComboBox()
{
    delete ui;
}
int activeIndex = 0;
void WindowForComboBox::setText(QString text){
    ui->label->setText(text);
}

int WindowForComboBox::on_NewWinComboBox_activated(int index){
    activeIndex = index;
    return activeIndex;
}

void WindowForComboBox::setComboBox(QStringList employeeList){
     ui->NewWinComboBox->clear();
    for(int i = 0; i < employeeList.size(); ++i){
         ui->NewWinComboBox->addItem(employeeList[i]);
    }
}

void WindowForComboBox::on_pushButton_clicked()
{
    emit returnActiveIndex(activeIndex);
}

