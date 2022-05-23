#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QDebug>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CountOfVariables(){

    QRegularExpression rx("(?<type>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!(delete|return)\\b)(?>(?<buildInType>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<var>\\w+)\\s*(?<array>\\[\\w*\\])?\\s*((?<init>=\\s*(?<value>(?>\\d+\\.?\\d*)|(?>'.?')|(?>\".*\")|({.+})|(?<newArray>new\\s+\\w+(\\*+)?\\[\\w+\\])|([^;]+)))|(?<ctr>\\(.*\\)))?;");
    QRegularExpressionMatchIterator i = rx.globalMatch(ui->textOfCode->toPlainText());
    QMap<QString, int> countsOfTypes;
    QStringList words;
    int countOfObgects = 0;
    int countOfArrays = 0;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(0);
        ui->Result->append(word);
        if( match.captured("array") != "" || match.captured("newArray") != "") {
            ++countsOfTypes[match.captured("type") + "[]"];
            ++countOfArrays;
        }
        else {
            ++countsOfTypes[match.captured("type")];
            if(match.captured("buildInType") == ""){
                ++countOfObgects;
            }
        }
        words << word;
    }
    ui->Result-> append("\n");
    foreach (const QString &key, countsOfTypes.keys()) {
       ui->Result-> append(key + ": " + QString::number(countsOfTypes.value(key)));
    }
    ui->Result->append("Objects: " + QString::number(countOfObgects) + "\n" + "Arrays: " + QString::number(countOfArrays));
    //qDebug() << countsOfTypes;
}

void MainWindow::FindPrototype(){
    QStringList brackets;
    QString str = ui->textOfCode->toPlainText();
    int indexOfMain = 0;
    int indexOfBracket = 0;
    indexOfMain = str.indexOf("int main(");
    indexOfBracket = str.indexOf("{", indexOfMain);
    ++indexOfBracket;
    brackets << "{";
    while ((std::min(str.indexOf("{", indexOfBracket),str.indexOf("}", indexOfBracket))) != -1 && !brackets.empty()) {
        indexOfBracket = std::min(str.indexOf("{", indexOfBracket),str.indexOf("}", indexOfBracket));
        if(indexOfBracket == str.indexOf("{", indexOfBracket)){
            brackets << "{";
        } else {
            brackets.pop_back();
        }
        ++indexOfBracket;
    }
    QRegularExpression rx("(?<type>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!delete\\b)(?>(?<intType>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<var>\\w+)\\s*(\\(((?<Valuetype>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!delete\\b)(?>(?<intTypeValue>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<varValue>\\w+)?\\s*,?\\s*){0,}\\))");
    QRegularExpressionMatchIterator i = rx.globalMatch(ui->textOfCode->toPlainText());
    QStringList words;
    int offset = 0;
    int newPosition = 0;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(0);
        offset = match.capturedStart() - newPosition;
        if(!words.contains(word) && (indexOfMain >= offset || indexOfBracket < offset || indexOfMain != -1)) {
            words << word;
            indexOfBracket -= (offset + match.capturedLength());
            indexOfMain -= (offset + match.capturedLength());
            newPosition += offset + match.capturedLength();
        }
    }
    foreach (const QString &word, words) {
       ui->Result_2-> append(word);
    }
}

void MainWindow::ChangeVariables(){
    QRegularExpression rx("(\\s*(?<type>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!(delete|return)\\b)(?>(?<buildInType>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)?\\s*(?<var>\\w+)\\s*(?<array>\\[\\w*\\])?\\s*(?<init>.?=)\\s*(((?<value>(?>\\d+\\.?\\d*)|(?>'.?')|(?>\".*\")|({.+})|(?<newArray>new\\s+\\w+(\\*+)?\\[\\w+\\])|([^;]+)))|(?<ctr>\\(.*\\)));)|(\\s*((?>(\\+\\+|--))(?<varr>\\w+)\\s*(?<arrayy>\\[\\w*\\])?|(?<varrr>\\w+)\\s*(?<arrayyy>\\[\\w*\\])?(?>(\\+\\+|--)))\\s*(?<initt>.?=\\s*((?<valuee>(?>\\d+\\.?\\d*)|(?>'.?')|(?>\".*\")|({.+})|(?<newArrayy>new\\s+\\w+(\\*+)?\\[\\w+\\])|([^;]+)))|(?<ctrr>\\(.*\\)))?;)");
    QString allText = ui->textOfCode->toPlainText();
    QStringList strList = allText.split('\n');
    for(int i = 0; i < strList.size(); ++i){
        QRegularExpressionMatchIterator it = rx.globalMatch(strList[i]);
        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            if(match.captured("type") == ""){
                QString word = match.captured(0);
                ui->Result_3->append(word + " // " + QString::number(i + 1));
            }
        }
    }
}

void MainWindow::CountOfLocalVariables(){
    QRegularExpression rxBrackets("[{}]");
    QRegularExpression rxLine("\\n");
    QRegularExpression rx("(?<type>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!(delete|return)\\b)(?>(?<buildInType>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<var>\\w+)\\s*(?<array>\\[\\w*\\])?\\s*((?<init>=\\s*(?<value>(?>\\d+\\.?\\d*)|(?>'.?')|(?>\".*\")|({.+})|(?<newArray>new\\s+\\w+(\\*+)?\\[\\w+\\])|([^;]+)))|(?<ctr>\\(.*\\)))?;");
    QRegularExpressionMatchIterator i = rx.globalMatch(ui->textOfCode->toPlainText());
    QString allText = ui->textOfCode->toPlainText();
    int countOfVariables = 0;
    int countOfOpenBracket = 0;
    int countOfCloseBracket = 0;
    int start = 0;
    int offset = 0;
    int numberOfLines = 0;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(0);
        offset = match.capturedStart() - start;
        QString partOfText = allText.mid(start,offset);
        QRegularExpressionMatchIterator it = rxBrackets.globalMatch(partOfText);
         while (it.hasNext()){
             QRegularExpressionMatch match = it.next();
             if( match.captured(0) == "{")
                 ++countOfOpenBracket;
             else
                 ++countOfCloseBracket;
         }
        if(countOfOpenBracket != countOfCloseBracket){
            QRegularExpressionMatchIterator iter = rxLine.globalMatch(partOfText);
            while (iter.hasNext()) {
                QRegularExpressionMatch match = iter.next();
                ++numberOfLines;
            }
            ui->Result_4->append(word + " // " + QString::number(numberOfLines));
            ++countOfVariables;
        }
        start += offset + match.capturedLength();
    }
    ui->Result_4->append("Count of local variables: "+ QString::number(countOfVariables + 1));
}

void MainWindow::CountOfOverloading(){
    QStringList brackets;
    QString str = ui->textOfCode->toPlainText();
    int indexOfMain = 0;
    int indexOfBracket = 0;
    int numberOfLines = 0;
    indexOfMain = str.indexOf("int main(");
    if(indexOfMain != -1){
        indexOfBracket = str.indexOf("{", indexOfMain);
        ++indexOfBracket;
        brackets << "{";
        while ((std::min(str.indexOf("{", indexOfBracket),str.indexOf("}", indexOfBracket))) != -1 && !brackets.empty()) {
            indexOfBracket = std::min(str.indexOf("{", indexOfBracket),str.indexOf("}", indexOfBracket));
            if(indexOfBracket == str.indexOf("{", indexOfBracket)){
                brackets << "{";
            } else {
                brackets.pop_back();
            }
            ++indexOfBracket;
        }
    }
    QRegularExpression rxLine("\\n");
    QRegularExpression rx("(?<type>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!delete\\b)(?>(?<intType>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<var>\\w+)\\s*(\\(((?<Valuetype>(?>(const)\\s+)?(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!delete\\b)(?>(?<intTypeValue>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<varValue>\\w+)?\\s*,?\\s*){0,}\\))");
    QRegularExpressionMatchIterator i = rx.globalMatch(ui->textOfCode->toPlainText());
    QMap<QString, QPair<QStringList,int>> words;
    int offset = 0;
    int newPosition = 0;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        offset = match.capturedStart() - newPosition;
        if(indexOfMain == -1 || indexOfMain >= offset || indexOfBracket < offset) {
           //ui->Result->append(word);
            words[match.captured("type") + " " + match.captured("var")];
            if(!words[match.captured("type") + " " + match.captured("var")].first.contains(match.captured(9))){
                words[match.captured("type") + " " + match.captured("var")].first.append(match.captured(9));
                ++words[match.captured("type") + " " + match.captured("var")].second;
            }
            indexOfBracket -= (offset + match.capturedLength());
            indexOfMain -= (offset + match.capturedLength());
            newPosition += offset + match.capturedLength();
        }
    }
    int countOfOverloading = 0;
    QStringList keys = words.keys();
    for (int i = 0;i < words.size(); ++i) {
       if(words.value(keys[i]).second > 1){
           for(int j = 0; j < words.value(keys[i]).second; ++j){
               int indexOfFunction = str.indexOf(keys[i] + words.value(keys[i]).first[j]);
               QString partOfText = str.mid(0,indexOfFunction);
               QRegularExpressionMatchIterator iter = rxLine.globalMatch(partOfText);
               while (iter.hasNext()) {
                   QRegularExpressionMatch match = iter.next();
                   ++numberOfLines;
               }
               ui->Result_5-> append(keys[i] + words.value(keys[i]).first[j] + " // " + QString::number(numberOfLines + 1));
               numberOfLines = 0;
           }
            ++countOfOverloading;
       }
    }
    ui->Result_5-> append("Count of overload functions: " + QString::number(countOfOverloading));
}


void MainWindow::BranchingDepth(){
     //QRegularExpression rxIf("if\\([^\\)].+\\)(?<else>else)(?<NextIF>if\\([^\\)].+\\))?");
     //QRegularExpression rxElse("else(?<NextIF>if\\([^\\)].+\\))?");
     //QRegularExpression rx("if\\([^)].+\\)\\{([^}].+\\n){1,}\\}\\s*(?<else>else)?(?<NextIF>if\\([^)].+\\))?");
     QRegularExpression rxIfElse("(\\s*(?<if>if)\\s*\\(|(?<else>else)|(?<brackets>[{}]))");
     QStringList structure;
     QRegularExpressionMatchIterator it = rxIfElse.globalMatch(ui->textOfCode->toPlainText());
     int openBrackets = 0;
     while (it.hasNext()) {
         QRegularExpressionMatch match = it.next();
         if(match.captured("if") != ""){
             structure.append("if");
         } else if(match.captured("else") != ""){
             structure.append("else");
         }
         else {
             structure.append(match.captured("brackets"));
         }
     }
     int maxCount = 0;
     int currCount = 0;
     for(int i = 0; i < structure.size();++i){
         if(structure[i] == "if"){
             ++currCount;
         } else if(structure[i] == "{"){
             ++openBrackets;
         }
         else if(structure[i] == "}"){
             --openBrackets;
             if(i != structure.size() - 1 && structure[i + 1] != "else" && currCount != 0){
                maxCount = qMax(maxCount,currCount);
                 --currCount;
                if(openBrackets == 0 && i != structure.size() - 1 && structure[i + 1] != "else"){
                     ui->Result_6->append(QString::number(maxCount) + " ");
                     maxCount = 0;
                     currCount = 0;
                 }
             }
         }
         if(i < structure.size() - 2 && structure[i + 1] == "else" && structure[i + 2] == "if"){
                currCount = 1;
         }
     }
     ui->Result_6->append(QString::number(maxCount) + " ");
}

void MainWindow::LogicErrors(){
    QRegularExpression rxTrueFalse("(while|if)\\s*\\(\\s*(true|false|\\d+|[^=)!]+\\s*=\\s*[^=)]+\\s*)\\)");
    QRegularExpression rxConst("(while|if)\\s*\\(\\s*((?<var>[^=)]+)\\s*=?\\s*(?>[^)]+)?)\\s*\\)");
    QRegularExpressionMatchIterator i = rxTrueFalse.globalMatch(ui->textOfCode->toPlainText());
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        ui->Result_7->append(match.captured(0));
    }
    QStringList constValuebles;
    QRegularExpression rxFindConst("(?<type>(?>(const)\\s+)(?>(signed|unsigned)\\s+)?(?>(short|long)\\s+)?\\b(?!(delete|return)\\b)(?>(?<buildInType>int|float|double|bool|char|size_t|void|wchar_t|char16_t|char32_t)|(\\w+)\\s*)(\\*+|&)?)\\s*(?<var>\\w+)\\s*(?<array>\\[\\w*\\])?\\s*((?<init>=\\s*(?<value>(?>\\d+\\.?\\d*)|(?>'.?')|(?>\".*\")|({.+})|(?<newArray>new\\s+\\w+(\\*+)?\\[\\w+\\])|([^;]+)))|(?<ctr>\\(.*\\)))?;");
    QRegularExpressionMatchIterator it = rxFindConst.globalMatch(ui->textOfCode->toPlainText());
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        constValuebles.append(match.captured("var"));
    }
    QRegularExpressionMatchIterator iter = rxConst.globalMatch(ui->textOfCode->toPlainText());
    while (iter.hasNext()) {
        QRegularExpressionMatch match = iter.next();
        if(constValuebles.contains(match.captured("var"))){
            ui->Result_7->append(match.captured(0));
        }
    }
    QRegularExpression rxFor("for\\((;;)\\)");
    QRegularExpressionMatchIterator iterat = rxFor.globalMatch(ui->textOfCode->toPlainText());
    while (iterat.hasNext()) {
        QRegularExpressionMatch match = iterat.next();
        ui->Result_7->append(match.captured(0));
    }
}

void MainWindow::clearAll(){
    ui->Result->clear();
    ui->Result_2->clear();
    ui->Result_3->clear();
    ui->Result_4->clear();
    ui->Result_5->clear();
    ui->Result_6->clear();
    ui->Result_7->clear();
}

void MainWindow::Check(){
    clearAll();
    FindPrototype();
    CountOfVariables();
    ChangeVariables();
    CountOfLocalVariables();
    CountOfOverloading();
    BranchingDepth();
    LogicErrors();
}
void MainWindow::on_pushButtonCheck_clicked()
{
   Check();
}


void MainWindow::onOpenFile_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open cpp file"), QDir::currentPath(), tr("Document files (*.cpp)"));
    if (filePath.isEmpty()){
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QString textFromFile = file.readAll();
    file.close();
    ui->textOfCode->setText(textFromFile);
}
