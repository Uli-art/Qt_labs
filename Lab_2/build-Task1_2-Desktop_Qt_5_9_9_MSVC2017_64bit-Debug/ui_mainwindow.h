/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionShow_All;
    QAction *actionTelephone_Number;
    QAction *actionCity;
    QAction *actionDelete_Phone_Number;
    QAction *actionChange_Call;
    QAction *actionAdd_Call;
    QAction *actionSort;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFind_By;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionShow_All = new QAction(MainWindow);
        actionShow_All->setObjectName(QStringLiteral("actionShow_All"));
        actionTelephone_Number = new QAction(MainWindow);
        actionTelephone_Number->setObjectName(QStringLiteral("actionTelephone_Number"));
        actionCity = new QAction(MainWindow);
        actionCity->setObjectName(QStringLiteral("actionCity"));
        actionDelete_Phone_Number = new QAction(MainWindow);
        actionDelete_Phone_Number->setObjectName(QStringLiteral("actionDelete_Phone_Number"));
        actionChange_Call = new QAction(MainWindow);
        actionChange_Call->setObjectName(QStringLiteral("actionChange_Call"));
        actionAdd_Call = new QAction(MainWindow);
        actionAdd_Call->setObjectName(QStringLiteral("actionAdd_Call"));
        actionSort = new QAction(MainWindow);
        actionSort->setObjectName(QStringLiteral("actionSort"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setLineWidth(0);
        treeWidget->setAllColumnsShowFocus(true);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuFind_By = new QMenu(menuEdit);
        menuFind_By->setObjectName(QStringLiteral("menuFind_By"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionShow_All);
        menuEdit->addAction(menuFind_By->menuAction());
        menuEdit->addAction(actionDelete_Phone_Number);
        menuEdit->addAction(actionChange_Call);
        menuEdit->addAction(actionAdd_Call);
        menuEdit->addAction(actionSort);
        menuFind_By->addAction(actionTelephone_Number);
        menuFind_By->addAction(actionCity);

        retranslateUi(MainWindow);
        QObject::connect(actionCity, SIGNAL(triggered()), MainWindow, SLOT(onFindBy_City_clicked()));
        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionDelete_Phone_Number, SIGNAL(triggered()), MainWindow, SLOT(onDelete_Number_clicked()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(onOpen_clicked()));
        QObject::connect(actionShow_All, SIGNAL(triggered()), MainWindow, SLOT(onShow_All_clicked()));
        QObject::connect(actionTelephone_Number, SIGNAL(triggered()), MainWindow, SLOT(onFindBy_Telephone_Number_clicked()));
        QObject::connect(actionAdd_Call, SIGNAL(triggered()), MainWindow, SLOT(onAddCall_clicked()));
        QObject::connect(actionChange_Call, SIGNAL(triggered()), MainWindow, SLOT(onChangeCall_clicked()));
        QObject::connect(actionSort, SIGNAL(triggered()), MainWindow, SLOT(onSort_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionShow_All->setText(QApplication::translate("MainWindow", "Show All", Q_NULLPTR));
        actionTelephone_Number->setText(QApplication::translate("MainWindow", "Telephone Number", Q_NULLPTR));
        actionCity->setText(QApplication::translate("MainWindow", "City", Q_NULLPTR));
        actionDelete_Phone_Number->setText(QApplication::translate("MainWindow", "Delete Phone Number", Q_NULLPTR));
        actionChange_Call->setText(QApplication::translate("MainWindow", "Change Call", Q_NULLPTR));
        actionAdd_Call->setText(QApplication::translate("MainWindow", "Add Call", Q_NULLPTR));
        actionSort->setText(QApplication::translate("MainWindow", "Sort ", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuFind_By->setTitle(QApplication::translate("MainWindow", "Find By...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
