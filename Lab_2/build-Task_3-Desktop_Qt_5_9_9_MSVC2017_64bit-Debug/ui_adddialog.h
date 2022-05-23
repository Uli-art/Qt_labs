/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *e;
    QDoubleSpinBox *b;
    QLabel *label_3;
    QDoubleSpinBox *a;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QDoubleSpinBox *d;
    QLabel *label_4;
    QDoubleSpinBox *c;
    QSpacerItem *horizontalSpacer;
    QLineEdit *InfForm;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QStringLiteral("AddDialog"));
        AddDialog->resize(307, 239);
        gridLayout_2 = new QGridLayout(AddDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(AddDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(AddDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 5, 1, 1);

        e = new QDoubleSpinBox(AddDialog);
        e->setObjectName(QStringLiteral("e"));
        e->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        e->setMaximum(200);

        gridLayout->addWidget(e, 1, 4, 1, 1);

        b = new QDoubleSpinBox(AddDialog);
        b->setObjectName(QStringLiteral("b"));

        gridLayout->addWidget(b, 1, 1, 1, 1);

        label_3 = new QLabel(AddDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        a = new QDoubleSpinBox(AddDialog);
        a->setObjectName(QStringLiteral("a"));

        gridLayout->addWidget(a, 0, 1, 1, 1);

        label = new QLabel(AddDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(AddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        label_5 = new QLabel(AddDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        d = new QDoubleSpinBox(AddDialog);
        d->setObjectName(QStringLiteral("d"));

        gridLayout->addWidget(d, 0, 4, 1, 1);

        label_4 = new QLabel(AddDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        c = new QDoubleSpinBox(AddDialog);
        c->setObjectName(QStringLiteral("c"));

        gridLayout->addWidget(c, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 1);

        InfForm = new QLineEdit(AddDialog);
        InfForm->setObjectName(QStringLiteral("InfForm"));
        InfForm->setMaxLength(255);

        gridLayout_2->addWidget(InfForm, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);


        retranslateUi(AddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QApplication::translate("AddDialog", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddDialog", "Infix Form", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddDialog", "Values:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddDialog", "d =", Q_NULLPTR));
        label->setText(QApplication::translate("AddDialog", "a =", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddDialog", "e =", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddDialog", "b =", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddDialog", "c =", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
