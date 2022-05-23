#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtaskdialog.h"
#include "findbytitleyeardialog.h"
#include <QTreeWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QStringList>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setEnabled(false);
    showAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAll(){
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Registration Number" << "Author" << "Title" << "Year of publication" << "Publisher" << "Pages");
    QList<QTreeWidgetItem *> items;
    Node *newNode = Books.getHead();
    for (int i = 0; i < Books.getSize(); ++i) {
        Book book = newNode->data;
        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << book.getRegistrationNumber() << book.getAuthor() << book.getTitle() << QString::number(book.getYear()) << book.getPublisher() << QString::number(book.getPages()) );
        item->setData(0, Qt::UserRole, QVariant(i));
        items.append(item);
        newNode = newNode->next;
    }
    ui->treeWidget->insertTopLevelItems(0, items);
    ui->treeWidget->setColumnWidth(0,200);
    ui->treeWidget->setColumnWidth(1,200);
    ui->treeWidget->setColumnWidth(2,200);
    ui->treeWidget->setColumnWidth(3,200);
    ui->treeWidget->setColumnWidth(4,200);
    ui->treeWidget->setColumnWidth(5,200);
}

void MainWindow::actionOpen(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.txt)"));
    if (filePath.isEmpty()){
        return;
    }

    if (!openTaskFile(filePath))
    {
        QMessageBox::critical(this, "Open Task File", "Failed to open task file");
        return;
    }

    currentFilePath = filePath;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    setEnabled(true);
    showAll();
}

bool MainWindow::openTaskFile(QString const& filePath){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream fileStream(&file);

    QString testLine;
    testLine = fileStream.readLine();
    int count = 0;
    int six = 0;
    while(!testLine.isNull()) {
        if(six < 6) {
            ++six;
        } else {
            six = 0;
            ++count;
        }
        if(six % 6 ==1){
            QStringList testRegNumber = testLine.split("-");
            if(testRegNumber.size() != 3){
                return false;
            }
            if(!(testLine.split("-")[0].toInt()) || !(testLine.split("-")[1].toInt()) || !(testLine.split("-")[2].toInt())){
                return false;
            }
        }

        if((six % 6 == 4 || six % 6 == 0) && six != 0){
            if(!testLine.toInt()){
                return false;
            }
        }

        if(six == 0 && testLine != ""){
             return false;
         }

        testLine = fileStream.readLine();
    }
    //++count;


    fileStream.seek(0);
    file.seek(0);
    Books.clear();
    for(int i = 0; i < count; ++i){
        QString registrationNumber = file.readLine().trimmed();
        QString author = file.readLine().trimmed();
        QString title = file.readLine().trimmed();
        QString year= file.readLine().trimmed();
        QString publisher= file.readLine().trimmed();
        QString pages = file.readLine().trimmed();
        Book newBook( registrationNumber,
              author,
              title,
              year.toInt(),
              publisher,
              pages.toInt());
        Books.addNode(newBook);
        file.readLine();
    }
    return true;
}

void MainWindow::actionShowAll(){
    setAddDelete(true);
    showAll();
}

void MainWindow::saveToFile(){
    QFile file(currentFilePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    Node *read = Books.getHead();
    for(int i = 0; i < Books.getSize(); ++i){
        out << read->data.getRegistrationNumber() << "\n" << read->data.getAuthor() << "\n" << read->data.getTitle() << "\n" <<  read->data.getYear() << "\n" << read->data.getPublisher() << "\n" << read->data.getPages() << "\n\n";
        read = read->next;
    }
}

void MainWindow::actionAddBook(){
    AddTaskDialog addtaskDialog(this);
    if (addtaskDialog.exec() == QDialog::Accepted)
    {
        if(addtaskDialog.accept(getAllRegistrationNumber(), Books.getSize())){
        Books.addNode(addtaskDialog.getBook());
        saveToFile();}
    }
    showAll();
}

void MainWindow::actionDeleteBook(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        int const bookIndex = data.toInt();
        Books.deleteNode(bookIndex);
        saveToFile();
    }
    showAll();
}

void MainWindow::actionChangeBook(){
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
        addTaskDialog.setCurrentTask(Books.find(taskIndex)->data);
        if (addTaskDialog.exec() == QDialog::Accepted)
        {
            if(addTaskDialog.accept(getAllRegistrationNumber(), Books.getSize(), taskIndex)){
                Books.find(taskIndex)->data = addTaskDialog.getBook();
                showAll();
                saveToFile();
            }
        }
    }
}

QString* MainWindow::getAllRegistrationNumber(){
    QString* booksRegistrNumber = new QString[Books.getSize()];
    Node *current = Books.getHead();
    for(int i =0; i < Books.getSize(); ++i){
        booksRegistrNumber[i] = current->data.getRegistrationNumber();
        current = current->next;
    }
    return booksRegistrNumber;
}

void MainWindow::actionFindRegistNum(){

    bool ok;
        QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("User name:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);

       // QString text = QString::number(textInt);
        if (ok && !text.isEmpty()){
            setAddDelete(false);
            int index;
            Node *current = Books.getHead();
            for(index = 0; index< Books.getSize(); ++index){
                if(current->data.getRegistrationNumber() == text){
                    break;
                }
                current = current->next;
            }
            ui->treeWidget->clear();
            ui->treeWidget->setColumnCount(0);
            ui->treeWidget->setHeaderLabels(QStringList() << "Registration Number" << "Author" << "Title" << "Year of publication" << "Publisher" << "Pages");
            QList<QTreeWidgetItem *> items;
            QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << current->data.getRegistrationNumber() << current->data.getAuthor() << current->data.getTitle() << QString::number(current->data.getYear()) << current->data.getPublisher() << QString::number(current->data.getPages()) );
            item->setData(0, Qt::UserRole, QVariant(0));
            items.append(item);
            ui->treeWidget->insertTopLevelItems(0, items);
        }

}
void MainWindow::actionFindAuthor(){
    List BooksOfAuthor;
    bool ok;
        QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("User name:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
       // QString text = QString::number(textInt);
        if (ok && !text.isEmpty()){
            setAddDelete(false);
            ui->treeWidget->clear();
            ui->treeWidget->setColumnCount(0);
            ui->treeWidget->setHeaderLabels(QStringList() << "Registration Number" << "Author" << "Title" << "Year of publication" << "Publisher" << "Pages");
            QList<QTreeWidgetItem *> items;
            int count = 0;
            Node *current = Books.getHead();
            for(int index = 0; index< Books.getSize(); ++index){
                if(current->data.getAuthor() == text){
                    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << current->data.getRegistrationNumber() << current->data.getAuthor() << current->data.getTitle() << QString::number(current->data.getYear()) << current->data.getPublisher() << QString::number(current->data.getPages()) );
                    item->setData(0, Qt::UserRole, QVariant(count));
                    items.append(item);
                    ++count;
                }
                current = current->next;
            }
            ui->treeWidget->insertTopLevelItems(0, items);
        }
}
void MainWindow::actionFindTitleYear(){
    FindByTitleYearDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        setAddDelete(false);
        ui->treeWidget->clear();
        ui->treeWidget->setColumnCount(0);
        ui->treeWidget->setHeaderLabels(QStringList() << "Registration Number" << "Author" << "Title" << "Year of publication" << "Publisher" << "Pages");
        QList<QTreeWidgetItem *> items;
        int count = 0;
        Node *current = Books.getHead();
        for(int index = 0; index< Books.getSize(); ++index){
            if(current->data.getTitle() == dialog.getTitle() && current->data.getYear() == dialog.getYear()){
                QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << current->data.getRegistrationNumber() << current->data.getAuthor() << current->data.getTitle() << QString::number(current->data.getYear()) << current->data.getPublisher() << QString::number(current->data.getPages()) );
                item->setData(0, Qt::UserRole, QVariant(count));
                items.append(item);
                ++count;
            }
            current = current->next;
        }
         ui->treeWidget->insertTopLevelItems(0, items);
    }
}

void MainWindow::actionSort(){
    if(Books.getSize() == 0 || Books.getSize() == 1){
        return;
    }
    Node * newNode = Books.getHead();
    for(int i = 0; i < Books.getSize() - 1; ++i){
        for(int j = 0; j < Books.getSize() - i - 1; ++j){
            if(newNode->data.getAuthor() > newNode->next->data.getAuthor()){
                Book tempBook;
                tempBook = newNode->data;
                newNode->data = newNode->next->data;
                newNode->next->data = tempBook;
                if(newNode == Books.getHead()){
                    Books.setHead(newNode);
                }
            }
            newNode = newNode->next;
        }
        newNode = Books.getHead();
    }
    showAll();
    saveToFile();
}

void MainWindow::setEnabled(bool setEnbled){
    ui->actionAddBook->setEnabled(setEnbled);
    ui->actionDeleteBook->setEnabled(setEnbled);
    ui->actionAuthor->setEnabled(setEnbled);
    ui->actionRegistration_numder->setEnabled(setEnbled);
    ui->actionShow_All->setEnabled(setEnbled);
    ui->actionTitle_and_Year_of_publication->setEnabled(setEnbled);
    ui->actionChange->setEnabled(setEnbled);
}

void MainWindow::setAddDelete(bool Enabled){
    ui->actionAddBook->setEnabled(Enabled);
    ui->actionDeleteBook->setEnabled(Enabled);
    ui->actionChange->setEnabled(Enabled);
}
