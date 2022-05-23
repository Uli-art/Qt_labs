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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionpush_front;
    QAction *actionpush_back;
    QAction *actionpop_back;
    QAction *actionpop_front;
    QAction *actionclear;
    QAction *actionresize;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(347, 263);
        actionpush_front = new QAction(MainWindow);
        actionpush_front->setObjectName(QStringLiteral("actionpush_front"));
        actionpush_back = new QAction(MainWindow);
        actionpush_back->setObjectName(QStringLiteral("actionpush_back"));
        actionpop_back = new QAction(MainWindow);
        actionpop_back->setObjectName(QStringLiteral("actionpop_back"));
        actionpop_front = new QAction(MainWindow);
        actionpop_front->setObjectName(QStringLiteral("actionpop_front"));
        actionclear = new QAction(MainWindow);
        actionclear->setObjectName(QStringLiteral("actionclear"));
        actionresize = new QAction(MainWindow);
        actionresize->setObjectName(QStringLiteral("actionresize"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 347, 26));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionpush_front);
        menuEdit->addAction(actionpush_back);
        menuEdit->addAction(actionpop_back);
        menuEdit->addAction(actionpop_front);
        menuEdit->addAction(actionclear);
        menuEdit->addAction(actionresize);

        retranslateUi(MainWindow);
        QObject::connect(actionpop_back, SIGNAL(triggered()), MainWindow, SLOT(onPop_back_clicked()));
        QObject::connect(actionresize, SIGNAL(triggered()), MainWindow, SLOT(onResize_clicked()));
        QObject::connect(actionpush_front, SIGNAL(triggered()), MainWindow, SLOT(onPush_front_clicked()));
        QObject::connect(actionpush_back, SIGNAL(triggered()), MainWindow, SLOT(onPush_back_clicked()));
        QObject::connect(actionpop_front, SIGNAL(triggered()), MainWindow, SLOT(onPop_front_clicked()));
        QObject::connect(actionclear, SIGNAL(triggered()), MainWindow, SLOT(onClear_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionpush_front->setText(QApplication::translate("MainWindow", "push_front", Q_NULLPTR));
        actionpush_back->setText(QApplication::translate("MainWindow", "push_back", Q_NULLPTR));
        actionpop_back->setText(QApplication::translate("MainWindow", "pop_back", Q_NULLPTR));
        actionpop_front->setText(QApplication::translate("MainWindow", "pop_front", Q_NULLPTR));
        actionclear->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        actionresize->setText(QApplication::translate("MainWindow", "resize", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
