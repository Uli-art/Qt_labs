/********************************************************************************
** Form generated from reading UI file 'addcall.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCALL_H
#define UI_ADDCALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddCall
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Code;
    QLabel *label;
    QLineEdit *CityNum;
    QLineEdit *Rate;
    QLineEdit *City;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDateEdit *Date;
    QTimeEdit *Time;
    QLineEdit *SubNum;

    void setupUi(QDialog *AddCall)
    {
        if (AddCall->objectName().isEmpty())
            AddCall->setObjectName(QStringLiteral("AddCall"));
        AddCall->resize(400, 300);
        gridLayout_2 = new QGridLayout(AddCall);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonBox = new QDialogButtonBox(AddCall);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(AddCall);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(AddCall);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        Code = new QLineEdit(AddCall);
        Code->setObjectName(QStringLiteral("Code"));

        gridLayout->addWidget(Code, 1, 1, 1, 1);

        label = new QLabel(AddCall);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        CityNum = new QLineEdit(AddCall);
        CityNum->setObjectName(QStringLiteral("CityNum"));

        gridLayout->addWidget(CityNum, 5, 1, 1, 1);

        Rate = new QLineEdit(AddCall);
        Rate->setObjectName(QStringLiteral("Rate"));

        gridLayout->addWidget(Rate, 4, 1, 1, 1);

        City = new QLineEdit(AddCall);
        City->setObjectName(QStringLiteral("City"));

        gridLayout->addWidget(City, 2, 1, 1, 1);

        label_2 = new QLabel(AddCall);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_5 = new QLabel(AddCall);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(AddCall);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(AddCall);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        Date = new QDateEdit(AddCall);
        Date->setObjectName(QStringLiteral("Date"));

        gridLayout->addWidget(Date, 0, 1, 1, 1);

        Time = new QTimeEdit(AddCall);
        Time->setObjectName(QStringLiteral("Time"));
        Time->setTime(QTime(0, 0, 0));

        gridLayout->addWidget(Time, 3, 1, 1, 1);

        SubNum = new QLineEdit(AddCall);
        SubNum->setObjectName(QStringLiteral("SubNum"));

        gridLayout->addWidget(SubNum, 6, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(AddCall);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddCall, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddCall, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddCall);
    } // setupUi

    void retranslateUi(QDialog *AddCall)
    {
        AddCall->setWindowTitle(QApplication::translate("AddCall", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddCall", "City", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddCall", "Time", Q_NULLPTR));
        Code->setPlaceholderText(QString());
        label->setText(QApplication::translate("AddCall", "Date Of Call", Q_NULLPTR));
        CityNum->setInputMask(QApplication::translate("AddCall", "+999(99)999-99-99", Q_NULLPTR));
        CityNum->setPlaceholderText(QString());
        City->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("AddCall", "Code Of City", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddCall", "Rate", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddCall", "City's Phone Number", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddCall", "Subscriber's Phone Number", Q_NULLPTR));
        SubNum->setInputMask(QApplication::translate("AddCall", "+999(99)999-99-99", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddCall: public Ui_AddCall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCALL_H
