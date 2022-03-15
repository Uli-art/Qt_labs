#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "Task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onOpenClicked();
    void onAddTaskClicked();
    void onDeleteTaskClicked();
    void onAppdateTaskClicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    bool openTaskFile(QString const& filePath);
    bool saveTaskFile();

    void showAll();
    void showDeveloperTasks(QString const& developer);
    void showDevelopersOfProjects(QString const& project);
    void showPrjectsOfManager(QString const& manager);
    void showDevelopersWhoMissedDeadline();
private:
    Ui::MainWindow *ui;
    QVector<Task> m_tasks;
    QString m_currentFilePath;
};
#endif // MAINWINDOW_H
