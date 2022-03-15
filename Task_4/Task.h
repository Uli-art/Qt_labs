#ifndef TASK_H
#define TASK_H
#include <QString>
#include <QDate>

struct Task
{
    Task();
    Task(QString NameOfProject,
         QString TaskName,
         QString FIOImplementer,
         QString FIOManager,
         QDate AssignmentDate,
         QDate Deadline,
         QDate TaskComplitedDate);

    QString NameOfProject;
    QString TaskName;
    QString FIOImplementer;
    QString FIOManager;
    QDate AssignmentDate;
    QDate Deadline;
    QDate TaskComplitedDate;
};

#endif // TASK_H
