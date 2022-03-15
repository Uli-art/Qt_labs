#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QDialog>
#include "Task.h"

namespace Ui {
class AddTaskDialog;
}

class AddTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskDialog(QWidget *parent = nullptr);
    void add(QString filePath);
    ~AddTaskDialog();

    void accept();
    Task getTask() const;
    void setCurrentTask(Task &task) const;
private:
    Ui::AddTaskDialog *ui;
};

#endif // ADDTASKDIALOG_H
