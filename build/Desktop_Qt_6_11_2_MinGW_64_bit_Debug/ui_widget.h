/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");

        verticalLayout->addLayout(formLayout);

        label = new QLabel(Widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);

        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout->addWidget(lineEdit_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\255\270\350\231\237:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\217\255\347\264\232:", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\351\233\273\350\251\261:", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\226\260\345\242\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\214\257\345\207\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\214\257\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
