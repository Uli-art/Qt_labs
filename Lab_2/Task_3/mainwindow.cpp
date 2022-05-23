#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"
#include "adddialog.h"
#include "data.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setExpressions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::convertToPost(QString infForm){
    Stack sing;
    QString result;
    for(int i = 0; i < infForm.size(); ++i){
        if(isItNumber(QString(infForm[i]))){
            result += infForm[i];
        } else{
            if( sing.getSize() == 0 || sing.getValue() == "(" || QString(infForm[i]) == "(" || (priorety(sing.getValue()) < priorety(QString(infForm[i]))) ){
                sing.push(QString(infForm[i]));
            } else{
                if(QString(infForm[i]) == ")"){
                    while(sing.getValue() != "("){
                        result += sing.pop();
                    }
                    sing.pop();
                } else{
                    while(sing.getSize() != 0 && (priorety(sing.getValue()) >= priorety(QString(infForm[i])) || sing.getValue() != "(")){
                        result += sing.pop();
                    }
                    sing.push(QString(infForm[i]));
                }
            }
        }

    }
    while(sing.getSize() != 0){
        result += sing.pop();
    }
    return result;
}

double MainWindow::calculate(QString postForm, Data &data){

    QStringList convExp = decoding(postForm, data);
    Stack numbers;
    for(int i = 0; i < convExp.size(); ++i){
        if(convExp[i].toDouble() != 0.0){
            numbers.push(QString(convExp[i]));
        } else{
            QString secNum = numbers.pop();
            QString firNum = numbers.pop();
            if(QString(convExp[i]) == "+"){
                numbers.push(QString::number(firNum.toDouble() + secNum.toDouble()));
            }else if(QString(convExp[i]) == "-"){
                numbers.push(QString::number(firNum.toDouble() - secNum.toDouble()));
            }else if(QString(convExp[i]) == "*"){
                numbers.push(QString::number(firNum.toDouble() * secNum.toDouble()));
            }else if(QString(convExp[i]) == "/"){
                numbers.push(QString::number(firNum.toDouble() / secNum.toDouble()));
            }
        }
    }
    return numbers.pop().toDouble();
}

bool MainWindow::isItNumber(QString element){
    QRegExp reg("[a-e]");
    return reg.indexIn(element) != -1;
}

int MainWindow::priorety(QString sing){
    if(sing == "+" || sing == "-")
        return 1;
    if(sing == "*" || sing == "/")
        return 2;
    return 0;
}
void MainWindow::showAll(){
    ui->treeWidget->clear();

    QList<QTreeWidgetItem *> items;
    for(int i = 0;i < expressions.size(); ++i){
        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << expressions[i].expression  << QString::number(expressions[i].a) << QString::number(expressions[i].b) << QString::number(expressions[i].c) << QString::number(expressions[i].d) << QString::number(expressions[i].e) << expressions[i].converted << QString::number(expressions[i].result));
        item->setData(0, Qt::UserRole, QVariant(i));
        items.append(item);}
    ui->treeWidget->insertTopLevelItems(0, items);

}
void MainWindow::onAdd_clicked(){
    AddDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        Data newData = dialog.getData();
        newData.converted = convertToPost(newData.expression);
        newData.result = calculate(newData.converted, newData);
        expressions.append(newData);
    }
    showAll();
}

double MainWindow::decodingLetters(double array[], QString element){
    if(element == "a"){
        return array[0];
    } else if(element == "b"){
        return array[1];
    } else if(element == "c"){
        return array[2];
    } else if(element == "d"){
        return array[3];
    } else if(element == "e"){
        return array[4];
    }
    return 1;
}

QStringList MainWindow::decoding(QString postForm, Data &data){
    QStringList convExp;
    double array[5] = {data.a, data.b, data.c, data.d, data.e};
    for(int i = 0; i < postForm.size(); ++i){
        if(isItNumber(QString(postForm[i]))){
            convExp.append(QString::number(decodingLetters(array,QString(postForm[i]))));
        } else{
            convExp.append(QString(postForm[i]));
        }
    }
    return convExp;
}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
 /*   QTreeWidgetItem* thisItem = ui->treeWidget->currentItem();
    if (thisItem == nullptr)
    {
        return;
    }*/

    QVariant data = item->data(0, Qt::UserRole);
    int index = data.toInt();
    AddDialog dialog(this);
    dialog.setData(expressions[index]);
    if (dialog.exec() == QDialog::Accepted)
    {
        Data newData = dialog.getData();
        newData.converted = convertToPost(newData.expression);
        newData.result = calculate(newData.converted, newData);
        expressions[index] = newData;
    }
    showAll();
}



void MainWindow::setExpressions(){
    Data newData("a/(b-c)*(d+e)", 8.6, 2.4,5.1,0.3,7.9);
    newData.converted = convertToPost(newData.expression);
    newData.result = calculate(newData.converted, newData);
    expressions.append(newData);

    Data newData1("(a+b)*(c-d)/e", 7.4, 3.6,2.8,9.5,0.9);
    newData1.converted = convertToPost(newData1.expression);
    newData1.result = calculate(newData1.converted, newData1);
    expressions.append(newData1);

    Data newData2("a-(b+c*d)/e", 3.1, 5.4,0.2,9.6,7.8);
    newData2.converted = convertToPost(newData2.expression);
    newData2.result = calculate(newData2.converted, newData2);
    expressions.append(newData2);

    Data newData3("a/b-((c+d)*e)", 1.2, 0.7, 9.3, 6.5, 8.4);
    newData3.converted = convertToPost(newData3.expression);
    newData3.result = calculate(newData3.converted, newData3);
    expressions.append(newData3);

    Data newData4("a*(b-c+d)/e", 9.7, 8.2, 3.6, 4.1, 0.5);
    newData4.converted = convertToPost(newData4.expression);
    newData4.result = calculate(newData4.converted, newData4);
    expressions.append(newData4);

    Data newData5("(a+b)*(c-d)/e", 0.8, 4.1, 7.9, 6.2, 3.5);
    newData5.converted = convertToPost(newData5.expression);
    newData5.result = calculate(newData5.converted, newData5);
    expressions.append(newData5);

    Data newData6("a*(b-c)/(d+e)", 1.6, 4.9, 5.7, 0.8, 2.3);
    newData6.converted = convertToPost(newData6.expression);
    newData6.result = calculate(newData6.converted, newData6);
    expressions.append(newData6);

    Data newData7("a/(b*(c+d))-e", 8.5, 0.3, 2.4, 7.9, 1.6);
    newData7.converted = convertToPost(newData7.expression);
    newData7.result = calculate(newData7.converted, newData7);
    expressions.append(newData7);

    Data newData8("(a+(b/c-d))*e", 5.6, 7.4, 8.9, 3.1, 0.2);
    newData8.converted = convertToPost(newData8.expression);
    newData8.result = calculate(newData8.converted, newData8);
    expressions.append(newData8);

    Data newData9("a*(b+c)/(d-e)", 0.4, 2.3, 6.7, 5.8, 9.1);
    newData9.converted = convertToPost(newData9.expression);
    newData9.result = calculate(newData9.converted, newData9);
    expressions.append(newData9);

    showAll();
}
