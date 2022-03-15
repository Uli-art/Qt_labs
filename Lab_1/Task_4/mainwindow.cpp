#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowforcombobox.h"
#include "addtaskdialog.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include "Task.h"

static const QString dateFormat = "dd.MM.yyyy";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->setEnabled(false);
    ui->actionAdd_task->setEnabled(false);
    ui->actionAppdate_task->setEnabled(false);
    ui->actionDelete_task->setEnabled(false);
    showAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.txt)"));
    if (filePath.isEmpty()){
        return;
    }

    if (!openTaskFile(filePath))
    {
        QMessageBox::critical(this, "Open Task File", "Failed to open task file");
        return;
    }

    m_currentFilePath = filePath;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    ui->comboBox->blockSignals(true);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox->blockSignals(false);

    ui->comboBox->setEnabled(true);
    ui->actionAdd_task->setEnabled(true);
    ui->actionAppdate_task->setEnabled(true);
    ui->actionDelete_task->setEnabled(true);
    showAll();
}

bool MainWindow::openTaskFile(QString const& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    int count = 0;
    int seven = 0;

    QTextStream fileStream(&file);

    QString testLine;
    testLine = fileStream.readLine();
    while(!testLine.isNull()) {
        if(seven < 7) {
            ++seven;
        } else {
            seven = 0;
            ++count;
        }

        if(seven % 7 == 3 || seven % 7 == 4){
            QStringList test = QObject::trUtf8(testLine.toStdString().c_str()).simplified().split(" ");
            if(test.size() != 3) {
                return false;
            }
        }
         if((seven % 7 == 5 || seven % 7 == 6 || seven % 7 == 0) && seven != 0){
                QDate testDate = testDate.fromString(testLine,dateFormat);
                if(!testDate.isValid())
                    return false;
          }
         if(seven == 0 && testLine != ""){
             return false;
         }

        testLine = fileStream.readLine();
    };

    ++count;


    fileStream.seek(0);
    file.seek(0);

    m_tasks.clear();
    for(int i = 0; i < count; ++i) {
        QDate date;
        QString progect = file.readLine().trimmed();
        QString task = file.readLine().trimmed();
        QString FIODev = file.readLine().trimmed();
        QString FIOManag = file.readLine().trimmed();
        QString AssignmentDate = file.readLine().trimmed();
        QString Deadline = file.readLine().trimmed();
        QString TaskComplitedDate = file.readLine().trimmed();

        m_tasks.append(Task(progect, task, FIODev, FIOManag, date.fromString(AssignmentDate, dateFormat), date.fromString(Deadline, dateFormat), date.fromString(TaskComplitedDate, dateFormat)));
        file.readLine();
    }

    return true;
}

bool MainWindow::saveTaskFile()
{
    QFile file(m_currentFilePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for(int i = 0; i < m_tasks.count(); ++i){
        out << m_tasks[i].NameOfProject << "\n" << m_tasks[i].TaskName << "\n" << m_tasks[i].FIOImplementer << "\n" << m_tasks[i].FIOManager << "\n" << m_tasks[i].AssignmentDate.toString(dateFormat) << "\n" <<
               m_tasks[i].Deadline.toString(dateFormat) << "\n" << m_tasks[i].TaskComplitedDate.toString(dateFormat) << "\n\n";
    }
    return true;
}

void MainWindow::showAll()
{
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Project" << "Task" << "Developer" << "Manager" << "Start Date" << "End Date" << "Complete Date");

    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < m_tasks.count(); ++i) {
        Task const& task = m_tasks[i];

        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << task.NameOfProject << task.TaskName << task.FIOImplementer << task.FIOManager << task.AssignmentDate.toString(dateFormat) <<
                                                    task.Deadline.toString(dateFormat) << task.TaskComplitedDate.toString(dateFormat));
        item->setData(0, Qt::UserRole, QVariant(i));
        items.append(item);
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}

void MainWindow::showDeveloperTasks(QString const& developer)
{
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Tasks");

    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < m_tasks.count(); ++i) {
        Task const& task = m_tasks[i];
        if(task.FIOImplementer == developer){
            items.append(new QTreeWidgetItem(QStringList() << task.TaskName));
        }
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}

void MainWindow::showDevelopersOfProjects(QString const& project){
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Developers");

    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < m_tasks.count(); ++i) {
        Task const& task = m_tasks[i];
        if(task.NameOfProject == project){
            items.append(new QTreeWidgetItem(QStringList() << task.FIOImplementer));
        }
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}

void MainWindow::showPrjectsOfManager(QString const& manager){
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Projects");

    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < m_tasks.count(); ++i) {
        Task const& task = m_tasks[i];
        if(task.FIOManager == manager){
            items.append(new QTreeWidgetItem(QStringList() << task.NameOfProject));
        }
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}

void MainWindow::showDevelopersWhoMissedDeadline(){
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Developers");

    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < m_tasks.count(); ++i) {
        Task const& task = m_tasks[i];
        if(task.Deadline < task.TaskComplitedDate){
            items.append(new QTreeWidgetItem(QStringList() << task.FIOImplementer));
        }
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}

void MainWindow::onAddTaskClicked()
{
    AddTaskDialog addTaskDialog(this);

    if (addTaskDialog.exec() == QDialog::Accepted)
    {
        m_tasks.append(addTaskDialog.getTask());
        saveTaskFile();
        on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
    }
}

void MainWindow::onDeleteTaskClicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        int const taskIndex = data.toInt();

        m_tasks.remove(taskIndex);
        on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
        saveTaskFile();
    }
}

void MainWindow::onAppdateTaskClicked(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        int const taskIndex = data.toInt();
        AddTaskDialog addTaskDialog(this);
        addTaskDialog.setCurrentTask(m_tasks[taskIndex]);
        if (addTaskDialog.exec() == QDialog::Accepted)
        {
            m_tasks[taskIndex] = addTaskDialog.getTask();
            on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
            showAll();
            saveTaskFile();
        }
    }

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
    {
        ui->actionAdd_task->setEnabled(true);
        ui->actionAppdate_task->setEnabled(true);
        ui->actionDelete_task->setEnabled(true);

        showAll();
    }
    else if(index == 1)
    {
        ui->actionAdd_task->setEnabled(false);
        ui->actionAppdate_task->setEnabled(false);
        ui->actionDelete_task->setEnabled(false);

        QStringList items;
        for(int i = 0;i < m_tasks.count(); ++i){
            items << tr(m_tasks[i].FIOImplementer.toStdString().c_str());
        }
        items.removeDuplicates();
           bool ok;
           QString item = QInputDialog::getItem(this, tr("Choose developer"),
                                                tr("Developer:"), items, 0, false, &ok);
        if (ok && !item.isEmpty())
            showDeveloperTasks(item);
    } else if(index == 2){
        ui->actionAdd_task->setEnabled(false);
        ui->actionAppdate_task->setEnabled(false);
        ui->actionDelete_task->setEnabled(false);

        QStringList items;
        for(int i = 0;i < m_tasks.count(); ++i){
            items << tr(m_tasks[i].NameOfProject.toStdString().c_str());
        }
        items.removeDuplicates();
           bool ok;
           QString item = QInputDialog::getItem(this, tr("Choose project"),
                                                tr("Project:"), items, 0, false, &ok);
        if (ok && !item.isEmpty())
            showDevelopersOfProjects(item);
    } else if(index == 3){
        ui->actionAdd_task->setEnabled(false);
        ui->actionAppdate_task->setEnabled(false);
        ui->actionDelete_task->setEnabled(false);

        QStringList items;
        for(int i = 0;i < m_tasks.count(); ++i){
            items << tr(m_tasks[i].FIOManager.toStdString().c_str());
        }
        items.removeDuplicates();
           bool ok;
           QString item = QInputDialog::getItem(this, tr("Choose manager"),
                                                tr("Manager:"), items, 0, false, &ok);
        if (ok && !item.isEmpty())
            showPrjectsOfManager(item);
    } else if(index == 4){
        ui->actionAdd_task->setEnabled(false);
        ui->actionAppdate_task->setEnabled(false);
        ui->actionDelete_task->setEnabled(false);

        showDevelopersWhoMissedDeadline();
    }
}

