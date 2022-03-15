#include "Task.h"

Task::Task()
{

}

Task::Task(QString NameOfProject,
             QString TaskName,
             QString FIOImplementer,
             QString FIOManager,
             QDate AssignmentDate,
             QDate Deadline,
             QDate TaskComplitedDate) {
    this->NameOfProject = NameOfProject;
    this->TaskName = TaskName;
    this->FIOImplementer = FIOImplementer;
    this->FIOManager = FIOManager;
    this->AssignmentDate = AssignmentDate;
    this->Deadline = Deadline;
    this->TaskComplitedDate = TaskComplitedDate;
}
