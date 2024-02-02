/********************************************************************************
** Form generated from reading UI file 'creditview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITVIEW_H
#define UI_CREDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditView
{
public:
    QFrame *input_layout;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *amount_val;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *period_val;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *interest_rate;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *annuity;
    QRadioButton *diff;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_7;
    QPushButton *calc_btn;
    QFrame *frame;
    QWidget *layoutWidget6;
    QVBoxLayout *overpayment;
    QLabel *label_6;
    QLabel *overpayment_val;
    QWidget *layoutWidget_2;
    QVBoxLayout *total_payments;
    QLabel *label_8;
    QLabel *total_payment_val;
    QWidget *layoutWidget;
    QVBoxLayout *monthly_payments;
    QLabel *label_5;
    QLabel *monthly_payment_val;

    void setupUi(QWidget *CreditView)
    {
        if (CreditView->objectName().isEmpty())
            CreditView->setObjectName(QString::fromUtf8("CreditView"));
        CreditView->resize(467, 359);
        input_layout = new QFrame(CreditView);
        input_layout->setObjectName(QString::fromUtf8("input_layout"));
        input_layout->setGeometry(QRect(0, 0, 231, 361));
        input_layout->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 209, 246); color: black;\n"
"    "));
        input_layout->setFrameShape(QFrame::StyledPanel);
        input_layout->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(input_layout);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 60, 211, 49));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        amount_val = new QLineEdit(layoutWidget1);
        amount_val->setObjectName(QString::fromUtf8("amount_val"));
        amount_val->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        verticalLayout_2->addWidget(amount_val);

        layoutWidget2 = new QWidget(input_layout);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 120, 211, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        period_val = new QLineEdit(layoutWidget2);
        period_val->setObjectName(QString::fromUtf8("period_val"));
        period_val->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));

        horizontalLayout_2->addWidget(period_val);

        layoutWidget4 = new QWidget(input_layout);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(40, 180, 131, 47));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        interest_rate = new QLineEdit(layoutWidget4);
        interest_rate->setObjectName(QString::fromUtf8("interest_rate"));
        interest_rate->setStyleSheet(QString::fromUtf8("background-color: white; text-align: right;\n"
"        "));

        verticalLayout->addWidget(interest_rate);

        layoutWidget5 = new QWidget(input_layout);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 260, 186, 23));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        annuity = new QRadioButton(layoutWidget5);
        annuity->setObjectName(QString::fromUtf8("annuity"));

        horizontalLayout_4->addWidget(annuity);

        diff = new QRadioButton(layoutWidget5);
        diff->setObjectName(QString::fromUtf8("diff"));

        horizontalLayout_4->addWidget(diff);

        label_4 = new QLabel(input_layout);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 191, 31));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        line = new QFrame(input_layout);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 40, 121, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(input_layout);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 210, 16, 16));
        calc_btn = new QPushButton(input_layout);
        calc_btn->setObjectName(QString::fromUtf8("calc_btn"));
        calc_btn->setGeometry(QRect(60, 300, 100, 32));
        calc_btn->setStyleSheet(QString::fromUtf8("QPushButton { color: #000; border-bottom: 1px solid black; border-radius:  5px; background-color: rgb(150, 167, 255); }\n"
"        QPushButton::pressed {\n"
"        background-color: grey;}\n"
"     "));
        frame = new QFrame(CreditView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 0, 241, 361));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 172, 255); color: black;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget6 = new QWidget(frame);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(50, 130, 151, 51));
        overpayment = new QVBoxLayout(layoutWidget6);
        overpayment->setObjectName(QString::fromUtf8("overpayment"));
        overpayment->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("qproperty-alignment: AlignCenter;"));

        overpayment->addWidget(label_6);

        overpayment_val = new QLabel(layoutWidget6);
        overpayment_val->setObjectName(QString::fromUtf8("overpayment_val"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        overpayment_val->setFont(font);
        overpayment_val->setStyleSheet(QString::fromUtf8("QLabel { qproperty-alignment: AlignCenter;}\n"
"        "));

        overpayment->addWidget(overpayment_val);

        layoutWidget_2 = new QWidget(frame);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 210, 151, 51));
        total_payments = new QVBoxLayout(layoutWidget_2);
        total_payments->setObjectName(QString::fromUtf8("total_payments"));
        total_payments->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("qproperty-alignment: AlignCenter;"));

        total_payments->addWidget(label_8);

        total_payment_val = new QLabel(layoutWidget_2);
        total_payment_val->setObjectName(QString::fromUtf8("total_payment_val"));
        total_payment_val->setFont(font);
        total_payment_val->setStyleSheet(QString::fromUtf8("QLabel { qproperty-alignment: AlignCenter;}\n"
"        "));

        total_payments->addWidget(total_payment_val);

        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 151, 51));
        monthly_payments = new QVBoxLayout(layoutWidget);
        monthly_payments->setObjectName(QString::fromUtf8("monthly_payments"));
        monthly_payments->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("qproperty-alignment: AlignCenter;"));

        monthly_payments->addWidget(label_5);

        monthly_payment_val = new QLabel(layoutWidget);
        monthly_payment_val->setObjectName(QString::fromUtf8("monthly_payment_val"));
        monthly_payment_val->setFont(font);
        monthly_payment_val->setStyleSheet(QString::fromUtf8("QLabel { qproperty-alignment: AlignCenter; }\n"
"        "));

        monthly_payments->addWidget(monthly_payment_val);


        retranslateUi(CreditView);

        QMetaObject::connectSlotsByName(CreditView);
    } // setupUi

    void retranslateUi(QWidget *CreditView)
    {
        CreditView->setWindowTitle(QCoreApplication::translate("CreditView", "Credit", nullptr));
        label->setText(QCoreApplication::translate("CreditView", "Loan amount:", nullptr));
        label_2->setText(QCoreApplication::translate("CreditView", "Period", nullptr));
        label_3->setText(QCoreApplication::translate("CreditView", "Interest rate per year", nullptr));
        annuity->setText(QCoreApplication::translate("CreditView", "annuity", nullptr));
        diff->setText(QCoreApplication::translate("CreditView", "differentiated", nullptr));
        label_4->setText(QCoreApplication::translate("CreditView", "Loan calculator", nullptr));
        label_7->setText(QCoreApplication::translate("CreditView", "%", nullptr));
        calc_btn->setText(QCoreApplication::translate("CreditView", "Calculate", nullptr));
        label_6->setText(QCoreApplication::translate("CreditView", "Overpayment on credit", nullptr));
        overpayment_val->setText(QCoreApplication::translate("CreditView", "00.00", nullptr));
        label_8->setText(QCoreApplication::translate("CreditView", "Total payment", nullptr));
        total_payment_val->setText(QCoreApplication::translate("CreditView", "00.00", nullptr));
        label_5->setText(QCoreApplication::translate("CreditView", "Monthly payments", nullptr));
        monthly_payment_val->setText(QCoreApplication::translate("CreditView", "00.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditView: public Ui_CreditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITVIEW_H
