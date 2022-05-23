#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QDialog>
#include "book.h"

namespace Ui {
class AddTaskDialog;
}

class AddTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskDialog(QWidget *parent = nullptr);
    ~AddTaskDialog();
    Book getBook() const;

    bool accept(QString* booksRegistrNumber, int size);
    void accept();
    bool accept(QString* booksRegistrNumber, int size, int index);
    void setCurrentTask(Book& changeBook) const;
private:
    Ui::AddTaskDialog *ui;
};

#endif // ADDTASKDIALOG_H
