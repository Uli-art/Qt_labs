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
    QAction *actionshared_ptr;
    QAction *actionweak_ptr;
    QAction *actionunique_ptr;
    QAction *actionDelete;
    QAction *actionReset;
    QAction *actionCopy_From;
    QAction *actionSwap;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QMenu *menuEdit;
    QMenu *menuAdd;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionshared_ptr = new QAction(MainWindow);
        actionshared_ptr->setObjectName(QStringLiteral("actionshared_ptr"));
        actionweak_ptr = new QAction(MainWindow);
        actionweak_ptr->setObjectName(QStringLiteral("actionweak_ptr"));
        actionunique_ptr = new QAction(MainWindow);
        actionunique_ptr->setObjectName(QStringLiteral("actionunique_ptr"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionCopy_From = new QAction(MainWindow);
        actionCopy_From->setObjectName(QStringLiteral("actionCopy_From"));
        actionSwap = new QAction(MainWindow);
        actionSwap->setObjectName(QStringLiteral("actionSwap"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAdd = new QMenu(menuEdit);
        menuAdd->setObjectName(QStringLiteral("menuAdd"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEdit->menuAction());
        menuEdit->addAction(menuAdd->menuAction());
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionReset);
        menuEdit->addAction(actionCopy_From);
        menuEdit->addAction(actionSwap);
        menuAdd->addAction(actionshared_ptr);
        menuAdd->addAction(actionweak_ptr);
        menuAdd->addAction(actionunique_ptr);

        retranslateUi(MainWindow);
        QObject::connect(actionshared_ptr, SIGNAL(triggered()), MainWindow, SLOT(on_Addshared_clicked()));
        QObject::connect(actionunique_ptr, SIGNAL(triggered()), MainWindow, SLOT(on_Addunique_clicked()));
        QObject::connect(actionweak_ptr, SIGNAL(triggered()), MainWindow, SLOT(on_Addweak_clicked()));
        QObject::connect(actionDelete, SIGNAL(triggered()), MainWindow, SLOT(on_Delete_clicked()));
        QObject::connect(actionReset, SIGNAL(triggered()), MainWindow, SLOT(on_Reset_clicked()));
        QObject::connect(actionCopy_From, SIGNAL(triggered()), MainWindow, SLOT(on_CopyFrom_clicked()));
        QObject::connect(actionSwap, SIGNAL(triggered()), MainWindow, SLOT(on_Swap_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionshared_ptr->setText(QApplication::translate("MainWindow", "shared_ptr", Q_NULLPTR));
        actionweak_ptr->setText(QApplication::translate("MainWindow", "weak_ptr", Q_NULLPTR));
        actionunique_ptr->setText(QApplication::translate("MainWindow", "unique_ptr", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        actionCopy_From->setText(QApplication::translate("MainWindow", "Copy From", Q_NULLPTR));
        actionSwap->setText(QApplication::translate("MainWindow", "Swap", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "Count", Q_NULLPTR));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Use Count", Q_NULLPTR));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Pointer", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuAdd->setTitle(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
