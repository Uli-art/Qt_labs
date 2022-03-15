#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QString>
AddTaskDialog::AddTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTaskDialog)
{
    ui->setupUi(this);
}

AddTaskDialog::~AddTaskDialog()
{
    delete ui;
}

void AddTaskDialog::accept()
{
    if(ui->Name->text() == "" || ui->Task->text() == "" || ui->FIOImplem->text() == "" || ui->FIOManeger->text() ==""){
        QMessageBox::warning(this,"title","Fill in all the fields");
        return;
    }
    if((ui->DateAssig->date() > ui->DateDeadline->date()) || (ui->DateAssig->date() > ui->DateTaskCompl->date())){
        QMessageBox::warning(this,"title","Incorrect date input");
        return;
    }
    QStringList test1 = QObject::trUtf8(ui->FIOImplem->text().toStdString().c_str()).simplified().split(" ");
    QStringList test2 = QObject::trUtf8(ui->FIOManeger->text().toStdString().c_str()).simplified().split(" ");
    if(test1.size() != 3 || test2.size() != 3){
        QMessageBox::warning(this,"title","Write correct FIO");
        return;
    }

    QDialog::accept();
}

Task AddTaskDialog::getTask() const
{
    return Task( ui->Name->text(), ui->Task->text(), ui->FIOImplem->text(), ui->FIOManeger->text(), ui->DateAssig->date(), ui->DateDeadline->date(), ui->DateTaskCompl->date());
}

void AddTaskDialog::setCurrentTask(Task &task) const
{
    ui->Name->setText(task.NameOfProject);
    ui->Task->setText(task.TaskName);
    ui->FIOImplem->setText(task.FIOImplementer);
    ui->FIOManeger->setText(task.FIOManager);
    ui->DateAssig->setDate(task.AssignmentDate);
    ui->DateDeadline->setDate(task.Deadline);
    ui->DateTaskCompl->setDate(task.TaskComplitedDate);
}
