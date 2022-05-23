#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void actionOpen();
    void actionAddBook();
    void actionShowAll();
    void actionDeleteBook();
    void actionFindRegistNum();
    void actionFindAuthor();
    void actionFindTitleYear();
    void actionChangeBook();
    void actionSort();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void showAll();
    bool openTaskFile(QString const& filePath);
    void saveToFile();
    QString* getAllRegistrationNumber();
    void setEnabled(bool setEnbled);
    void setAddDelete(bool Enabled);
private:
    Ui::MainWindow *ui;
    QString currentFilePath;
    List Books;
};
#endif // MAINWINDOW_H
