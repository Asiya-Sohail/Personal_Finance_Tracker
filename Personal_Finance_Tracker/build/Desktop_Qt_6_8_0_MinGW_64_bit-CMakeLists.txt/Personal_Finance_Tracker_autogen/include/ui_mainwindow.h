/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *ContinueButton;
    QLabel *Title;
    QWidget *page_3;
    QPushButton *SigninButton;
    QLabel *Title_3;
    QLabel *Title_4;
    QPushButton *LoginButton;
    QWidget *page_2;
    QLabel *Title_5;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *Enter;
    QLabel *label_11;
    QLineEdit *incomeInput;
    QPushButton *Back_11;
    QWidget *page_4;
    QLabel *Title_6;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *Enter_2;
    QPushButton *Back_10;
    QWidget *page_5;
    QLabel *label_6;
    QPushButton *SetGoals;
    QPushButton *CurrencyConverter;
    QPushButton *AddCategories;
    QPushButton *ViewCategoryButton;
    QPushButton *ExpenseChart;
    QPushButton *viewMonthlyTransactionsButton;
    QPushButton *exit;
    QPushButton *LogoutButton;
    QPushButton *AllocateFunds;
    QPushButton *Spend;
    QPushButton *ViewGoals;
    QPushButton *AdvanceDay;
    QPushButton *AdvanceMonth;
    QLabel *dateLabel;
    QWidget *page_6;
    QLabel *Title_7;
    QLabel *label_2;
    QLineEdit *amount;
    QComboBox *ConvertFrom;
    QComboBox *ConvertTo;
    QLabel *label_7;
    QLabel *label_8;
    QFrame *line;
    QPushButton *ConvertButton;
    QPushButton *ShowRatesButton;
    QLabel *resultLabel;
    QPushButton *Back;
    QListWidget *DisplayRates;
    QWidget *page_7;
    QLabel *Title_8;
    QLineEdit *categoryNameInput;
    QLabel *label_9;
    QPushButton *addCategoryButton;
    QPushButton *Back_2;
    QLabel *label_10;
    QLineEdit *categoryBalanceInput;
    QWidget *page_8;
    QLabel *Title_9;
    QTableWidget *categoriesTable;
    QPushButton *Back_3;
    QWidget *page_9;
    QLabel *Title_10;
    QPushButton *Back_4;
    QLabel *label_12;
    QLineEdit *goalAmountInput;
    QLabel *label_13;
    QLineEdit *goalMonthsInput;
    QPushButton *SetGoalButton;
    QWidget *page_10;
    QLabel *Title_11;
    QProgressBar *goalProgressBar;
    QLabel *goalDetailsLabel;
    QPushButton *Back_5;
    QWidget *page_11;
    QGridLayout *gridLayout;
    QScrollArea *allocationScrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QWidget *allocationScrollAreaWidgetContents;
    QPushButton *Back_6;
    QLabel *Title_12;
    QWidget *page_12;
    QGridLayout *gridLayout_4;
    QPushButton *Back_7;
    QScrollArea *spendScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_5;
    QWidget *spendScrollAreaWidgetContents;
    QLabel *Title_13;
    QLabel *spendStatusLabel;
    QWidget *page_13;
    QLabel *Title_14;
    QLabel *Title_15;
    QLineEdit *incomeLineEdit;
    QPushButton *Back_8;
    QPushButton *advanceMonthButton;
    QLabel *TaxDeduct;
    QLabel *NewIncome;
    QWidget *page_14;
    QLabel *Title_16;
    QTableWidget *monthlyTransactionsTableWidget;
    QPushButton *Back_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"color : rgb(170, 170, 255);\n"
"}"));
        page = new QWidget();
        page->setObjectName("page");
        ContinueButton = new QPushButton(page);
        ContinueButton->setObjectName("ContinueButton");
        ContinueButton->setGeometry(QRect(320, 230, 171, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(14);
        ContinueButton->setFont(font);
        ContinueButton->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Title = new QLabel(page);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(260, 150, 371, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Impact")});
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        Title->setFont(font1);
        Title->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 20pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        SigninButton = new QPushButton(page_3);
        SigninButton->setObjectName("SigninButton");
        SigninButton->setGeometry(QRect(500, 160, 81, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Modern No. 20")});
        font2.setPointSize(12);
        SigninButton->setFont(font2);
        SigninButton->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Title_3 = new QLabel(page_3);
        Title_3->setObjectName("Title_3");
        Title_3->setGeometry(QRect(140, 160, 261, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Modern No. 20")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        Title_3->setFont(font3);
        Title_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Title_4 = new QLabel(page_3);
        Title_4->setObjectName("Title_4");
        Title_4->setGeometry(QRect(130, 250, 321, 51));
        Title_4->setFont(font3);
        Title_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        LoginButton = new QPushButton(page_3);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(500, 260, 81, 31));
        LoginButton->setFont(font2);
        LoginButton->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        Title_5 = new QLabel(page_2);
        Title_5->setObjectName("Title_5");
        Title_5->setGeometry(QRect(290, 40, 241, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Impact")});
        Title_5->setFont(font4);
        Title_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(0, 0, 127);\n"
"font-size: 20px;\n"
"}"));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 90, 131, 31));
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 140, 151, 31));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        usernameInput = new QLineEdit(page_2);
        usernameInput->setObjectName("usernameInput");
        usernameInput->setGeometry(QRect(390, 100, 171, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("MV Boli")});
        font5.setPointSize(14);
        usernameInput->setFont(font5);
        passwordInput = new QLineEdit(page_2);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setGeometry(QRect(390, 150, 171, 20));
        passwordInput->setFont(font5);
        Enter = new QPushButton(page_2);
        Enter->setObjectName("Enter");
        Enter->setGeometry(QRect(40, 470, 81, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Modern No. 20")});
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setItalic(false);
        Enter->setFont(font6);
        Enter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";"));
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(210, 190, 151, 31));
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}\n"
""));
        incomeInput = new QLineEdit(page_2);
        incomeInput->setObjectName("incomeInput");
        incomeInput->setGeometry(QRect(390, 200, 171, 21));
        incomeInput->setFont(font5);
        Back_11 = new QPushButton(page_2);
        Back_11->setObjectName("Back_11");
        Back_11->setGeometry(QRect(660, 470, 81, 31));
        Back_11->setFont(font6);
        Back_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";"));
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        Title_6 = new QLabel(page_4);
        Title_6->setObjectName("Title_6");
        Title_6->setGeometry(QRect(280, 50, 231, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Impact")});
        font7.setPointSize(13);
        font7.setBold(false);
        font7.setItalic(false);
        Title_6->setFont(font7);
        Title_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        label_4 = new QLabel(page_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 140, 131, 31));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        label_5 = new QLabel(page_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 200, 151, 31));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        lineEdit_4 = new QLineEdit(page_4);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(380, 140, 171, 20));
        lineEdit_4->setFont(font5);
        lineEdit_5 = new QLineEdit(page_4);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(380, 200, 171, 20));
        lineEdit_5->setFont(font5);
        Enter_2 = new QPushButton(page_4);
        Enter_2->setObjectName("Enter_2");
        Enter_2->setGeometry(QRect(40, 470, 71, 31));
        Enter_2->setFont(font6);
        Enter_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";\n"
"\n"
""));
        Back_10 = new QPushButton(page_4);
        Back_10->setObjectName("Back_10");
        Back_10->setGeometry(QRect(660, 470, 81, 31));
        Back_10->setFont(font6);
        Back_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";\n"
""));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_6 = new QLabel(page_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 70, 311, 31));
        label_6->setFont(font7);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        SetGoals = new QPushButton(page_5);
        SetGoals->setObjectName("SetGoals");
        SetGoals->setGeometry(QRect(80, 130, 91, 31));
        SetGoals->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        CurrencyConverter = new QPushButton(page_5);
        CurrencyConverter->setObjectName("CurrencyConverter");
        CurrencyConverter->setGeometry(QRect(80, 370, 161, 31));
        CurrencyConverter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        AddCategories = new QPushButton(page_5);
        AddCategories->setObjectName("AddCategories");
        AddCategories->setGeometry(QRect(470, 130, 171, 31));
        AddCategories->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        ViewCategoryButton = new QPushButton(page_5);
        ViewCategoryButton->setObjectName("ViewCategoryButton");
        ViewCategoryButton->setGeometry(QRect(470, 170, 211, 31));
        ViewCategoryButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        ExpenseChart = new QPushButton(page_5);
        ExpenseChart->setObjectName("ExpenseChart");
        ExpenseChart->setGeometry(QRect(470, 210, 231, 31));
        ExpenseChart->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        viewMonthlyTransactionsButton = new QPushButton(page_5);
        viewMonthlyTransactionsButton->setObjectName("viewMonthlyTransactionsButton");
        viewMonthlyTransactionsButton->setGeometry(QRect(470, 250, 271, 31));
        viewMonthlyTransactionsButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        exit = new QPushButton(page_5);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(650, 470, 91, 31));
        exit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";\n"
""));
        LogoutButton = new QPushButton(page_5);
        LogoutButton->setObjectName("LogoutButton");
        LogoutButton->setGeometry(QRect(650, 30, 81, 31));
        LogoutButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";\n"
""));
        AllocateFunds = new QPushButton(page_5);
        AllocateFunds->setObjectName("AllocateFunds");
        AllocateFunds->setGeometry(QRect(80, 290, 121, 31));
        AllocateFunds->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        Spend = new QPushButton(page_5);
        Spend->setObjectName("Spend");
        Spend->setGeometry(QRect(80, 250, 101, 31));
        Spend->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        ViewGoals = new QPushButton(page_5);
        ViewGoals->setObjectName("ViewGoals");
        ViewGoals->setGeometry(QRect(80, 170, 91, 31));
        ViewGoals->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        AdvanceDay = new QPushButton(page_5);
        AdvanceDay->setObjectName("AdvanceDay");
        AdvanceDay->setGeometry(QRect(80, 210, 101, 31));
        AdvanceDay->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        AdvanceMonth = new QPushButton(page_5);
        AdvanceMonth->setObjectName("AdvanceMonth");
        AdvanceMonth->setGeometry(QRect(80, 330, 121, 31));
        AdvanceMonth->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: 11pt \"Modern No. 20\";\n"
""));
        dateLabel = new QLabel(page_5);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setGeometry(QRect(470, 300, 211, 71));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Modern No. 20")});
        font8.setPointSize(10);
        dateLabel->setFont(font8);
        dateLabel->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"color: rgb(0, 0, 127);\n"
"font: 10pt \"Modern No. 20\";\n"
"}\n"
""));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        Title_7 = new QLabel(page_6);
        Title_7->setObjectName("Title_7");
        Title_7->setGeometry(QRect(290, 20, 191, 31));
        Title_7->setFont(font7);
        Title_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        label_2 = new QLabel(page_6);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 90, 141, 41));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        amount = new QLineEdit(page_6);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(200, 90, 91, 31));
        amount->setFont(font5);
        ConvertFrom = new QComboBox(page_6);
        ConvertFrom->addItem(QString());
        ConvertFrom->addItem(QString());
        ConvertFrom->addItem(QString());
        ConvertFrom->setObjectName("ConvertFrom");
        ConvertFrom->setGeometry(QRect(70, 150, 53, 22));
        ConvertFrom->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        ConvertTo = new QComboBox(page_6);
        ConvertTo->addItem(QString());
        ConvertTo->addItem(QString());
        ConvertTo->addItem(QString());
        ConvertTo->setObjectName("ConvertTo");
        ConvertTo->setGeometry(QRect(210, 150, 53, 22));
        ConvertTo->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        label_7 = new QLabel(page_6);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(80, 180, 41, 31));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Modern No. 20")});
        font9.setPointSize(11);
        font9.setBold(false);
        font9.setItalic(false);
        font9.setUnderline(true);
        label_7->setFont(font9);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        label_8 = new QLabel(page_6);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(230, 180, 21, 31));
        label_8->setFont(font9);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        line = new QFrame(page_6);
        line->setObjectName("line");
        line->setGeometry(QRect(390, 80, 20, 311));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        ConvertButton = new QPushButton(page_6);
        ConvertButton->setObjectName("ConvertButton");
        ConvertButton->setGeometry(QRect(40, 330, 101, 31));
        ConvertButton->setFont(font6);
        ConvertButton->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        ShowRatesButton = new QPushButton(page_6);
        ShowRatesButton->setObjectName("ShowRatesButton");
        ShowRatesButton->setGeometry(QRect(200, 330, 101, 31));
        ShowRatesButton->setFont(font6);
        ShowRatesButton->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        resultLabel = new QLabel(page_6);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(60, 220, 221, 71));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("MV Boli")});
        resultLabel->setFont(font10);
        resultLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"font-size: 12px;\n"
"}"));
        Back = new QPushButton(page_6);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(640, 470, 101, 31));
        Back->setFont(font6);
        Back->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"\n"
""));
        DisplayRates = new QListWidget(page_6);
        DisplayRates->setObjectName("DisplayRates");
        DisplayRates->setGeometry(QRect(440, 80, 261, 311));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        Title_8 = new QLabel(page_7);
        Title_8->setObjectName("Title_8");
        Title_8->setGeometry(QRect(270, 30, 201, 31));
        Title_8->setFont(font7);
        Title_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        categoryNameInput = new QLineEdit(page_7);
        categoryNameInput->setObjectName("categoryNameInput");
        categoryNameInput->setGeometry(QRect(310, 110, 231, 21));
        categoryNameInput->setFont(font5);
        label_9 = new QLabel(page_7);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(150, 110, 161, 31));
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        addCategoryButton = new QPushButton(page_7);
        addCategoryButton->setObjectName("addCategoryButton");
        addCategoryButton->setGeometry(QRect(280, 240, 161, 31));
        addCategoryButton->setFont(font6);
        addCategoryButton->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        Back_2 = new QPushButton(page_7);
        Back_2->setObjectName("Back_2");
        Back_2->setGeometry(QRect(640, 470, 101, 31));
        Back_2->setFont(font3);
        Back_2->setStyleSheet(QString::fromUtf8("\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        label_10 = new QLabel(page_7);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(150, 170, 151, 31));
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        categoryBalanceInput = new QLineEdit(page_7);
        categoryBalanceInput->setObjectName("categoryBalanceInput");
        categoryBalanceInput->setGeometry(QRect(310, 170, 231, 21));
        categoryBalanceInput->setFont(font5);
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        Title_9 = new QLabel(page_8);
        Title_9->setObjectName("Title_9");
        Title_9->setGeometry(QRect(320, 80, 151, 31));
        Title_9->setFont(font7);
        Title_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        categoriesTable = new QTableWidget(page_8);
        if (categoriesTable->columnCount() < 2)
            categoriesTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        categoriesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        categoriesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        categoriesTable->setObjectName("categoriesTable");
        categoriesTable->setGeometry(QRect(140, 130, 491, 301));
        categoriesTable->setStyleSheet(QString::fromUtf8("\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        Back_3 = new QPushButton(page_8);
        Back_3->setObjectName("Back_3");
        Back_3->setGeometry(QRect(620, 460, 101, 31));
        Back_3->setFont(font6);
        Back_3->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        Title_10 = new QLabel(page_9);
        Title_10->setObjectName("Title_10");
        Title_10->setGeometry(QRect(340, 70, 111, 31));
        Title_10->setFont(font7);
        Title_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Back_4 = new QPushButton(page_9);
        Back_4->setObjectName("Back_4");
        Back_4->setGeometry(QRect(660, 470, 81, 31));
        Back_4->setFont(font6);
        Back_4->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        label_12 = new QLabel(page_9);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(170, 130, 181, 31));
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        goalAmountInput = new QLineEdit(page_9);
        goalAmountInput->setObjectName("goalAmountInput");
        goalAmountInput->setGeometry(QRect(350, 130, 231, 21));
        goalAmountInput->setFont(font5);
        label_13 = new QLabel(page_9);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(170, 190, 161, 31));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        goalMonthsInput = new QLineEdit(page_9);
        goalMonthsInput->setObjectName("goalMonthsInput");
        goalMonthsInput->setGeometry(QRect(350, 190, 231, 21));
        goalMonthsInput->setFont(font5);
        SetGoalButton = new QPushButton(page_9);
        SetGoalButton->setObjectName("SetGoalButton");
        SetGoalButton->setGeometry(QRect(320, 270, 101, 31));
        SetGoalButton->setFont(font6);
        SetGoalButton->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        Title_11 = new QLabel(page_10);
        Title_11->setObjectName("Title_11");
        Title_11->setGeometry(QRect(340, 90, 111, 31));
        Title_11->setFont(font7);
        Title_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        goalProgressBar = new QProgressBar(page_10);
        goalProgressBar->setObjectName("goalProgressBar");
        goalProgressBar->setGeometry(QRect(210, 190, 381, 31));
        goalProgressBar->setValue(24);
        goalDetailsLabel = new QLabel(page_10);
        goalDetailsLabel->setObjectName("goalDetailsLabel");
        goalDetailsLabel->setGeometry(QRect(300, 140, 181, 31));
        goalDetailsLabel->setFont(font3);
        goalDetailsLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Back_5 = new QPushButton(page_10);
        Back_5->setObjectName("Back_5");
        Back_5->setGeometry(QRect(640, 470, 101, 31));
        Back_5->setFont(font6);
        Back_5->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        stackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        gridLayout = new QGridLayout(page_11);
        gridLayout->setObjectName("gridLayout");
        allocationScrollArea = new QScrollArea(page_11);
        allocationScrollArea->setObjectName("allocationScrollArea");
        allocationScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 754, 436));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName("gridLayout_3");
        allocationScrollAreaWidgetContents = new QWidget(scrollAreaWidgetContents);
        allocationScrollAreaWidgetContents->setObjectName("allocationScrollAreaWidgetContents");

        gridLayout_3->addWidget(allocationScrollAreaWidgetContents, 0, 0, 1, 1);

        allocationScrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(allocationScrollArea, 1, 0, 1, 1);

        Back_6 = new QPushButton(page_11);
        Back_6->setObjectName("Back_6");
        Back_6->setFont(font6);
        Back_6->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));

        gridLayout->addWidget(Back_6, 3, 0, 1, 1);

        Title_12 = new QLabel(page_11);
        Title_12->setObjectName("Title_12");
        Title_12->setFont(font7);
        Title_12->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        Title_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));

        gridLayout->addWidget(Title_12, 0, 0, 1, 1);

        stackedWidget->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName("page_12");
        gridLayout_4 = new QGridLayout(page_12);
        gridLayout_4->setObjectName("gridLayout_4");
        Back_7 = new QPushButton(page_12);
        Back_7->setObjectName("Back_7");
        Back_7->setFont(font6);
        Back_7->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));

        gridLayout_4->addWidget(Back_7, 3, 1, 1, 1);

        spendScrollArea = new QScrollArea(page_12);
        spendScrollArea->setObjectName("spendScrollArea");
        spendScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 754, 308));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_5->setObjectName("gridLayout_5");
        spendScrollAreaWidgetContents = new QWidget(scrollAreaWidgetContents_2);
        spendScrollAreaWidgetContents->setObjectName("spendScrollAreaWidgetContents");

        gridLayout_5->addWidget(spendScrollAreaWidgetContents, 0, 0, 1, 1);

        spendScrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_4->addWidget(spendScrollArea, 1, 0, 2, 2);

        Title_13 = new QLabel(page_12);
        Title_13->setObjectName("Title_13");
        Title_13->setFont(font7);
        Title_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Title_13->setLineWidth(1);
        Title_13->setTextFormat(Qt::TextFormat::MarkdownText);

        gridLayout_4->addWidget(Title_13, 0, 0, 1, 1);

        spendStatusLabel = new QLabel(page_12);
        spendStatusLabel->setObjectName("spendStatusLabel");
        spendStatusLabel->setFont(font10);
        spendStatusLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"font-size: 14px;\n"
"}"));

        gridLayout_4->addWidget(spendStatusLabel, 0, 1, 1, 1);

        stackedWidget->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName("page_13");
        Title_14 = new QLabel(page_13);
        Title_14->setObjectName("Title_14");
        Title_14->setGeometry(QRect(300, 110, 231, 31));
        Title_14->setFont(font7);
        Title_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        Title_15 = new QLabel(page_13);
        Title_15->setObjectName("Title_15");
        Title_15->setGeometry(QRect(170, 190, 141, 31));
        Title_15->setFont(font3);
        Title_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        incomeLineEdit = new QLineEdit(page_13);
        incomeLineEdit->setObjectName("incomeLineEdit");
        incomeLineEdit->setGeometry(QRect(340, 180, 251, 31));
        incomeLineEdit->setFont(font5);
        Back_8 = new QPushButton(page_13);
        Back_8->setObjectName("Back_8");
        Back_8->setGeometry(QRect(660, 470, 81, 31));
        Back_8->setFont(font6);
        Back_8->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        advanceMonthButton = new QPushButton(page_13);
        advanceMonthButton->setObjectName("advanceMonthButton");
        advanceMonthButton->setGeometry(QRect(300, 460, 181, 31));
        advanceMonthButton->setFont(font6);
        advanceMonthButton->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        TaxDeduct = new QLabel(page_13);
        TaxDeduct->setObjectName("TaxDeduct");
        TaxDeduct->setGeometry(QRect(200, 380, 421, 31));
        TaxDeduct->setFont(font3);
        TaxDeduct->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        NewIncome = new QLabel(page_13);
        NewIncome->setObjectName("NewIncome");
        NewIncome->setGeometry(QRect(190, 320, 421, 31));
        NewIncome->setFont(font3);
        NewIncome->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 11pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        stackedWidget->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName("page_14");
        Title_16 = new QLabel(page_14);
        Title_16->setObjectName("Title_16");
        Title_16->setGeometry(QRect(270, 40, 281, 31));
        Title_16->setFont(font7);
        Title_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 13pt \"Impact\";\n"
"	color: rgb(0, 0, 127);\n"
"}"));
        monthlyTransactionsTableWidget = new QTableWidget(page_14);
        monthlyTransactionsTableWidget->setObjectName("monthlyTransactionsTableWidget");
        monthlyTransactionsTableWidget->setGeometry(QRect(70, 90, 641, 341));
        Back_9 = new QPushButton(page_14);
        Back_9->setObjectName("Back_9");
        Back_9->setGeometry(QRect(660, 470, 81, 31));
        Back_9->setFont(font6);
        Back_9->setStyleSheet(QString::fromUtf8("\n"
"	font: 10pt \"Modern No. 20\";\n"
"	color: rgb(0, 0, 127);\n"
""));
        stackedWidget->addWidget(page_14);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ContinueButton->setText(QCoreApplication::translate("MainWindow", "Click to continue", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Personal Finance Tracker", nullptr));
        SigninButton->setText(QCoreApplication::translate("MainWindow", "Sign in ", nullptr));
        Title_3->setText(QCoreApplication::translate("MainWindow", "Do you wanna create an account ?", nullptr));
        Title_4->setText(QCoreApplication::translate("MainWindow", "Do you wanna login from existing account ?", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Title_5->setText(QCoreApplication::translate("MainWindow", "Personal Finance Tracker", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter your name :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter your password :", nullptr));
        usernameInput->setText(QString());
        Enter->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Enter your income :", nullptr));
        Back_11->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Title_6->setText(QCoreApplication::translate("MainWindow", "Personal Finance Tracker", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter your name :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter your password:", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        Enter_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Back_10->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Choose what you want to perform", nullptr));
        SetGoals->setText(QCoreApplication::translate("MainWindow", "Set Goals", nullptr));
        CurrencyConverter->setText(QCoreApplication::translate("MainWindow", "Currency Converter", nullptr));
        AddCategories->setText(QCoreApplication::translate("MainWindow", "Add New Categories", nullptr));
        ViewCategoryButton->setText(QCoreApplication::translate("MainWindow", "View Existing Categories", nullptr));
        ExpenseChart->setText(QCoreApplication::translate("MainWindow", "Visit Existing Expense Chart", nullptr));
        viewMonthlyTransactionsButton->setText(QCoreApplication::translate("MainWindow", "View Transaction History Monthly", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        LogoutButton->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        AllocateFunds->setText(QCoreApplication::translate("MainWindow", "Allocate Funds", nullptr));
        Spend->setText(QCoreApplication::translate("MainWindow", "Spend Funds", nullptr));
        ViewGoals->setText(QCoreApplication::translate("MainWindow", "View Goals", nullptr));
        AdvanceDay->setText(QCoreApplication::translate("MainWindow", "Advance Day", nullptr));
        AdvanceMonth->setText(QCoreApplication::translate("MainWindow", "Advance Month", nullptr));
        dateLabel->setText(QString());
        Title_7->setText(QCoreApplication::translate("MainWindow", "Currency Converter", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter the amount :", nullptr));
        amount->setText(QString());
        ConvertFrom->setItemText(0, QCoreApplication::translate("MainWindow", "USD", nullptr));
        ConvertFrom->setItemText(1, QCoreApplication::translate("MainWindow", "GBP", nullptr));
        ConvertFrom->setItemText(2, QCoreApplication::translate("MainWindow", "PKR", nullptr));

        ConvertTo->setItemText(0, QCoreApplication::translate("MainWindow", "USD", nullptr));
        ConvertTo->setItemText(1, QCoreApplication::translate("MainWindow", "PKR", nullptr));
        ConvertTo->setItemText(2, QCoreApplication::translate("MainWindow", "GBP", nullptr));

#if QT_CONFIG(tooltip)
        label_7->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>From</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
#if QT_CONFIG(tooltip)
        label_8->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>From</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        ConvertButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        ShowRatesButton->setText(QCoreApplication::translate("MainWindow", "Show Rates", nullptr));
        resultLabel->setText(QString());
        Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Title_8->setText(QCoreApplication::translate("MainWindow", "Add New Categories", nullptr));
        categoryNameInput->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Enter category name :", nullptr));
        addCategoryButton->setText(QCoreApplication::translate("MainWindow", "Add Category", nullptr));
        Back_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Enter Balance :", nullptr));
        categoryBalanceInput->setText(QString());
        Title_9->setText(QCoreApplication::translate("MainWindow", "View Categories", nullptr));
        QTableWidgetItem *___qtablewidgetitem = categoriesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = categoriesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        Back_3->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Title_10->setText(QCoreApplication::translate("MainWindow", "Set Goals", nullptr));
        Back_4->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Enter targeted amount :", nullptr));
        goalAmountInput->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Enter targeted date :", nullptr));
        goalMonthsInput->setText(QString());
        SetGoalButton->setText(QCoreApplication::translate("MainWindow", "Set Goal", nullptr));
        Title_11->setText(QCoreApplication::translate("MainWindow", "View Goals", nullptr));
        goalDetailsLabel->setText(QString());
        Back_5->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Back_6->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Title_12->setText(QCoreApplication::translate("MainWindow", "Allocate Funds", nullptr));
        Back_7->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Title_13->setText(QCoreApplication::translate("MainWindow", "Spend Funds", nullptr));
        spendStatusLabel->setText(QString());
        Title_14->setText(QCoreApplication::translate("MainWindow", "Say HELLO to a new month!", nullptr));
        Title_15->setText(QCoreApplication::translate("MainWindow", "Enter your income : ", nullptr));
        incomeLineEdit->setText(QString());
        Back_8->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        advanceMonthButton->setText(QCoreApplication::translate("MainWindow", "Advance Month", nullptr));
        TaxDeduct->setText(QString());
        NewIncome->setText(QString());
        Title_16->setText(QCoreApplication::translate("MainWindow", "Monthly Transaction History", nullptr));
        Back_9->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
