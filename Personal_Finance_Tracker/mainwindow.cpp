#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <QtCore/QCoreApplication>
#include <QMessageBox>
#include <QLayout>
#include <QString>
#include <QTableWidget>


QT_USE_NAMESPACE
using namespace std;

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

struct DateTime {
    int day, month, year, hour, minute;

    DateTime(int d = 1, int m = 1, int y = 2023, int h = 0, int min = 0)
        : day(d), month(m), year(y), hour(h), minute(min) {}

    bool isLeapYear() const {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int daysInMonth() const {
        const int daysInEachMonth[12] = {31, (isLeapYear() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return daysInEachMonth[month - 1];
    }

    void advance(int days, int hours, int minutes) {
        minute += minutes;
        hour += hours + minute / 60;
        day += days + hour / 24;
        minute %= 60;
        hour %= 24;

        while (day > daysInMonth()) {
            day -= daysInMonth();
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void display() const {
        cout << setw(2) << setfill('0') << day << "/"
             << setw(2) << setfill('0') << month << "/"
             << year << " "
             << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute;
    }

    bool operator<(const DateTime& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        return minute < other.minute;
    }
};

struct Goal {
    string name;
    double targetAmount;
    int targetMonths;
    double goalProgress;
    bool isCompleted;
    DateTime startDate; // New field to track when the goal was set

    Goal(string goalName, double targetAmt, int months, DateTime date)
        : name(goalName), targetAmount(targetAmt), targetMonths(months), goalProgress(0), isCompleted(false), startDate(date) {}

    void setGoal(double targetAmt, int months, DateTime date) {
        targetAmount = targetAmt;
        targetMonths = months;
        goalProgress = 0;
        isCompleted = false;
        startDate = date;
        cout << "Goal set successfully on " << setw(2) << setfill('0') << startDate.day << "/"
             << setw(2) << setfill('0') << startDate.month << "/" << startDate.year
             << "! Target: " << targetAmount << " in " << targetMonths << " months.\n";
    }
};

struct Transaction {
    int amount;
    string type;
    string category;
    DateTime dateTime;
    Transaction* next;

    Transaction(int amt, string t, DateTime dt, string c) : amount(amt), type(t), dateTime(dt), next(nullptr), category(c) {}
};

struct CategoryNode {
    string name;
    int balance;
    Transaction* transactions;
    CategoryNode* left;
    CategoryNode* right;

    CategoryNode(string n) : name(n), balance(0), transactions(nullptr), left(nullptr), right(nullptr) {}

    void addTransaction(int amount, string type, DateTime dateTime, string category) {
        Transaction* newTransaction = new Transaction(amount, type, dateTime, category);
        newTransaction->next = transactions;
        transactions = newTransaction;
    }

    void resetBalance() {
        balance = 0; // Reset the category balance
    }

    void displayTransactions() {
        Transaction* temp = transactions;
        while (temp) {
            cout << "Type: " << temp->type << ", Amount: " << temp->amount << ", Date: ";
            temp->dateTime.display();
            cout << endl;
            temp = temp->next;
        }
    }
};

class CurrencyConverter {
private:
    std::map<std::string, double> conversionRates;

public:
    CurrencyConverter() {
        conversionRates["USD"] = 1.0;
        conversionRates["PKR"] = 270.0;
        conversionRates["GBP"] = 0.76;
    }

    // Conversion function
    double convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency) {
        if (conversionRates.find(fromCurrency) == conversionRates.end() ||
            conversionRates.find(toCurrency) == conversionRates.end()) {
            std::cout << "Error: Unsupported currency." << std::endl;
            return -1;
        }

        double amountInUSD = amount / conversionRates[fromCurrency];
        return amountInUSD * conversionRates[toCurrency];
    }

    // Getter for conversion rates
    const std::map<std::string, double>& getConversionRates() const {
        return conversionRates;
    }

    // Display conversion rates in a QListWidget
    static void displayConversionRates(QListWidget* listWidget, const std::map<std::string, double>& rates) {
        listWidget->clear();

        // Retrieve individual rates
        double usdToPkr = rates.at("PKR");
        double usdToGbp = rates.at("GBP");
        double usdToUsd = rates.at("USD");

        // PKR to others
        double pkrToUsd = 1.0 / usdToPkr;
        double pkrToGbp = usdToGbp / usdToPkr;

        // GBP to others
        double gbpToUsd = 1.0 / usdToGbp;
        double gbpToPkr = usdToPkr / usdToGbp;

        // Add items manually
        listWidget->addItem("1 USD = " + QString::number(usdToPkr, 'f', 2) + " PKR");
        listWidget->addItem("1 USD = " + QString::number(usdToGbp, 'f', 2) + " GBP");

        listWidget->addItem("1 PKR = " + QString::number(pkrToUsd, 'f', 4) + " USD");
        listWidget->addItem("1 PKR = " + QString::number(pkrToGbp, 'f', 4) + " GBP");

        listWidget->addItem("1 GBP = " + QString::number(gbpToUsd, 'f', 2) + " USD");
        listWidget->addItem("1 GBP = " + QString::number(gbpToPkr, 'f', 2) + " PKR");
    }
};

class FinanceTracker {
private:
    CategoryNode* root;
    int totalIncome;
    CategoryNode* savings;
    CategoryNode* emergencyFunds;
    CategoryNode* sinkingFunds;
    DateTime currentDate;
    CurrencyConverter converter;
    Goal* currentGoal = nullptr;  // Pointer to dynamically manage goal lifecycle

    CategoryNode* insertCategory(CategoryNode* node, string name) {
        if (!node) return new CategoryNode(name);
        if (name < node->name) node->left = insertCategory(node->left, name);
        else if (name > node->name) node->right = insertCategory(node->right, name);
        return node;
    }

    CategoryNode* searchCategory(CategoryNode* node, string name) {
        if (!node || node->name == name) return node;
        if (name < node->name) return searchCategory(node->left, name);
        return searchCategory(node->right, name);
    }

    // Gather all categories' balances
    void gatherCategoryBalances(CategoryNode* node, QPieSeries* series) {
        if (!node) return;
        gatherCategoryBalances(node->left, series);
        series->append(QString::fromStdString(node->name), node->balance);
        gatherCategoryBalances(node->right, series);
    }

    void resetUserCategories(CategoryNode* node) {
        if (!node) return;
        node->resetBalance();
        resetUserCategories(node->left);
        resetUserCategories(node->right);
    }

    void sortTransactionsByDate(vector<Transaction*>& sortedTransactions) {
        // Sort the vector of transactions by date
        sort(sortedTransactions.begin(), sortedTransactions.end(), [](Transaction* a, Transaction* b) {
            return a->dateTime < b->dateTime; // Compare using DateTime's overloaded operator<
        });
    }

    // Function to calculate tax and deduct it from the income
    void calculateTax(double& income, QLabel* taxdeduct) {
        double taxRate = 0.1; // 10% tax rate
        double tax = income * taxRate;
        income -= tax;
        taxdeduct->setText("Tax calculated and deducted: " + QString::number(tax) + "\n");
    }

public:
    FinanceTracker(int income) : root(nullptr), totalIncome(income), currentDate(1, 1, 2023) {
        savings = new CategoryNode("Savings");
        emergencyFunds = new CategoryNode("Emergency Funds");
        sinkingFunds = new CategoryNode("Sinking Funds");
    }

    void addCategory(string name) {
        root = insertCategory(root, name);
    }

    void displayCategoryBalances(QTableWidget* table, CategoryNode* savings, CategoryNode* emergencyFunds, CategoryNode* sinkingFunds, CategoryNode* root) {
        // Clear any existing rows in the table
        table->setRowCount(0);

        // Add the three hardcoded categories to the table
        int rowCount = 0;

        // Add Savings
        table->insertRow(rowCount);
        table->setItem(rowCount, 0, new QTableWidgetItem("Savings"));
        table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(savings->balance)));
        rowCount++;

        // Add Emergency Funds
        table->insertRow(rowCount);
        table->setItem(rowCount, 0, new QTableWidgetItem("Emergency Funds"));
        table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(emergencyFunds->balance)));
        rowCount++;

        // Add Sinking Funds
        table->insertRow(rowCount);
        table->setItem(rowCount, 0, new QTableWidgetItem("Sinking Funds"));
        table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(sinkingFunds->balance)));
        rowCount++;

        // Recursive lambda to add user-defined categories
        std::function<void(CategoryNode*)> addCategories = [&](CategoryNode* node) {
            if (!node) return;

            // Add left subtree categories
            addCategories(node->left);

            // Add current node's data
            table->insertRow(rowCount);
            table->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(node->name)));
            table->setItem(rowCount, 1, new QTableWidgetItem(QString::number(node->balance)));
            rowCount++;

            // Add right subtree categories
            addCategories(node->right);
        };

        // Add user-defined categories starting from the root
        addCategories(root);
    }

    void viewCategoriesAndBalances(QTableWidget* table) {
        displayCategoryBalances(table, savings, emergencyFunds, sinkingFunds, root);
    }

    CategoryNode* getCategoryRoot(){
        return root;
    }

    Goal* getCurrentGoal() const {
        return currentGoal;
    }

    int getSavingsBalance() const {
        return savings->balance;  // Assuming savings is a predefined category
    }

    DateTime getCurrentDate() const {
        return currentDate;
    }

    bool allocateFunds(const std::string& name, int amount) {
        // Validate amount
        if (amount <= 0) {
            std::cout << "Error: Amount must be greater than zero.\n";
            return false;
        }

        // Find the appropriate category
        CategoryNode* category = (name == "Savings" ? savings :
                                      (name == "Emergency Funds" ? emergencyFunds :
                                           (name == "Sinking Funds" ? sinkingFunds :
                                                searchCategory(root, name))));

        // Check if the category exists and if there is enough income
        if (category && amount <= totalIncome) {
            // Allocate funds
            category->balance += amount;
            totalIncome -= amount;

            // Log the transaction
            category->addTransaction(amount, "add", currentDate, name);

            std::cout << "Successfully allocated " << amount << " to " << name << ".\n";
            return true;
        }

        // Provide meaningful feedback for failure
        if (!category) {
            std::cout << "Error: Category " << name << " not found.\n";
        } else if (amount > totalIncome) {
            std::cout << "Error: Insufficient income to allocate " << amount << ".\n";
        }
        return false;
    }

    bool spendFunds(const string& name, int amount) {
        CategoryNode* category = (name == "Savings" ? savings :
                                      (name == "Emergency Funds" ? emergencyFunds :
                                           (name == "Sinking Funds" ? sinkingFunds :
                                                searchCategory(root, name))));

        if (category) {
            if (category->balance >= amount) {
                category->balance -= amount;
                category->addTransaction(-amount, "Spent", currentDate, name);
                std::cout << "Spent " << amount << " from " << name << "\n";
                return true;
            } else {
                std::cout << "Insufficient funds in " << name << " category.\n";
                return false;
            }
        }

        cout << "Category " << name << " not found.\n";
        return false;
    }

    void setGoal(const string& goalName, double targetAmount, int months, DateTime currentDate) {
        if (currentGoal) {
            cout << "A goal already exists. Resetting the previous goal.\n";
            delete currentGoal;
        }
        currentGoal = new Goal(goalName, targetAmount, months, currentDate);
        cout << "Goal set successfully on " << setw(2) << setfill('0') << currentDate.day << "/"
             << setw(2) << setfill('0') << currentDate.month << "/" << currentDate.year
             << ".\n";
    }


    void checkGoalProgress(int savingsBalance) {
        if (currentGoal) {
            // Calculate the progress
            currentGoal->goalProgress = savingsBalance;

            if (currentGoal->goalProgress >= currentGoal->targetAmount) {
                currentGoal->isCompleted = true;
                cout << "Congratulations! You have achieved your goal: " << currentGoal->name << "\n";

                // Reset the current goal
                delete currentGoal;
                currentGoal = nullptr;
                cout << "The goal has been reset. You can now set a new goal.\n";
            } else {
                cout << "Goal progress: " << currentGoal->goalProgress << " / " << currentGoal->targetAmount << "\n";
            }
        } else {
            cout << "No goal is currently set.\n";
        }
    }

    void startNewMonth(double newIncome, QLabel* taxdeduct, QLabel* newincome) {
        transferCategoryBalancesToSavings();
        calculateTax(newIncome, taxdeduct);  // Deduct tax from new income
        totalIncome = newIncome;

        // Advance to the next month
        currentDate.advance(currentDate.daysInMonth(), 0, 0);

        printTransactionHistory();
        resetUserCategories(root);
        newincome->setText("New Income Entered (After Tax Deduction): " + QString::number(totalIncome) + "\n");
    }

    void startNewDay() {
        currentDate.advance(1, 0, 0);
    }

    void transferCategoryBalancesToSavings() {
        savings->balance += root->balance;
        root->resetBalance();
        emergencyFunds->balance += sinkingFunds->balance;
        sinkingFunds->resetBalance();
    }

    void printTransactionHistory() {
        vector<Transaction*> allTransactions;

        // Gather transactions from all categories
        gatherCategoryTransactions(root, allTransactions);
        gatherCategoryTransactions(savings, allTransactions);
        gatherCategoryTransactions(emergencyFunds, allTransactions);
        gatherCategoryTransactions(sinkingFunds, allTransactions);

        // Sort transactions by date
        sortTransactionsByDate(allTransactions);

        // Print the sorted transaction history
        cout << "Transaction History (Sorted by Date & Time):\n";
        for (auto& transaction : allTransactions) {
            cout << "Amount: " << transaction->amount
                 << ", Type: " << transaction->type
                 << ", Date: ";
            transaction->dateTime.display();
            cout << endl;
        }
    }

    void showMonthlyTransactions(QTableWidget* tableWidget) {
        // Clear the existing data in the table
        tableWidget->clearContents();
        tableWidget->setRowCount(0);

        // Gather all transactions from categories (using std::vector)
        std::vector<Transaction*> allTransactions;
        gatherCategoryTransactions(root, allTransactions);
        gatherCategoryTransactions(savings, allTransactions);
        gatherCategoryTransactions(emergencyFunds, allTransactions);
        gatherCategoryTransactions(sinkingFunds, allTransactions);

        // Sort transactions by date (same logic as printTransactionHistory)
        sortTransactionsByDate(allTransactions);

        // Set up the table headers
        tableWidget->setColumnCount(4);  // Only 3 columns: Amount, Type, Date
        tableWidget->setHorizontalHeaderLabels({"Amount", "Type", "Date", "Category"});

        // Populate the table with all transactions
        for (int row = 0; row < allTransactions.size(); ++row) {
            Transaction* transaction = allTransactions[row];

            // Insert a new row
            tableWidget->insertRow(row);

            // Set data for each column (use std::string for conversion)
            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(std::to_string(transaction->amount))));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(transaction->type)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(
                                             std::to_string(transaction->dateTime.day) + "-" +
                                             std::to_string(transaction->dateTime.month) + "-" +
                                             std::to_string(transaction->dateTime.year)
                                             )));
            tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(transaction->category)));
        }

        // Resize columns to fit the content
        tableWidget->resizeColumnsToContents();
    }

    void gatherCategoryTransactions(CategoryNode* node, vector<Transaction*>& allTransactions) {
        if (!node) return;

        // Add transactions from the current node
        Transaction* temp = node->transactions;
        while (temp) {
            allTransactions.push_back(temp);
            temp = temp->next;
        }

        // Recurse into left and right subtrees
        gatherCategoryTransactions(node->left, allTransactions);
        gatherCategoryTransactions(node->right, allTransactions);
    }

    void displayPieChart() {
        QPieSeries* series = new QPieSeries();

        // Add predefined categories to the pie chart
        series->append("Savings", savings->balance);
        series->append("Emergency Funds", emergencyFunds->balance);
        series->append("Sinking Funds", sinkingFunds->balance);

        // Gather user-added categories and add them to the pie chart
        gatherCategoryBalances(root, series);

        // Create a chart and add the series
        QChart* chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Income Distribution by Category");

        // Create a chart view and display it
        QChartView* chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(600, 400);
        chartView->show();
    }

    ~FinanceTracker() {
        if (currentGoal) {
            delete currentGoal;  // Ensure no memory leaks
        }
    }
};

struct User {
    string username;
    string password;
    FinanceTracker Tracker;

    User(const string &u, const string &p, int income) : username(u),
        password(p), Tracker(income) {}
};

vector<User> users;
User* currentUser = nullptr; // Global pointer to the currently logged-in user
CurrencyConverter converter;

void MainWindow::on_ContinueButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Navigate to the next screen
}

void MainWindow::on_SigninButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Navigate to the registration screen
}

void MainWindow::on_LoginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Navigate to the login screen
}

void MainWindow::on_Enter_clicked()
{
    string username = ui->usernameInput->text().toStdString();
    string password = ui->passwordInput->text().toStdString();
    int income = ui->incomeInput->text().toInt();

    // Check if username already exists
    auto it = find_if(users.begin(), users.end(), [&username](const User &user) {
        return user.username == username;
    });

    if (it != users.end()) {
        QMessageBox::warning(this, "Error", "Username already exists!");
        return;
    }

    // Register new user
    users.emplace_back(username, password, income);
    QMessageBox::information(this, "Success", "User registered successfully!");

    // Go to login page
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Enter_2_clicked() {
    string username = ui->usernameInput->text().toStdString();
    string password = ui->passwordInput->text().toStdString();


    // Check if user exists and password matches
    auto it = find_if(users.begin(), users.end(), [&username, &password](const User &user) {
        return user.username == username && user.password == password;
    });

    if (it == users.end()) {
        QMessageBox::warning(this, "Error", "Invalid username or password!");
        return;
    }

    // Login successful
    QMessageBox::information(this, "Welcome", "Welcome back, " + QString::fromStdString(username) + "!");

    // Set current user and populate categories
    currentUser = &(*it); // Point currentUser to the logged-in user
    updateDateLabelFromTracker();
    // Go to the dashboard
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutButton_clicked()
{
    currentUser = nullptr; // Reset current user
    // ui->usernameInput->clear();
    // ui->passwordInput->clear();

    // Go back to the login/register screen
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_exit_clicked()
{
    QApplication::quit(); // Cleanly exits the application
}

void MainWindow::on_CurrencyConverter_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ConvertButton_clicked()
{
    double amount = ui->amount->text().toDouble();
    QString fromCurrency = ui->ConvertFrom->currentText();
    QString toCurrency = ui->ConvertTo->currentText();

    double result = converter.convertCurrency(amount, fromCurrency.toStdString(), toCurrency.toStdString());

    if (result == -1) {
        ui->resultLabel->setText("Error: Unsupported currency.");
    } else {
        ui->resultLabel->setText("Converted Amount: " + QString::number(result));
    }
}

void MainWindow::on_ShowRatesButton_clicked() {
    // Use the global CurrencyConverter object
    const std::map<std::string, double>& rates = converter.getConversionRates();

    // Display manually calculated rates in the QListWidget
    CurrencyConverter::displayConversionRates(ui->DisplayRates, rates);
}

void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_AddCategories_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_addCategoryButton_clicked()
{
    // Get the category name from input
    QString categoryName = ui->categoryNameInput->text();

    if (categoryName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Category name cannot be empty!");
        return;
    }

    // Convert the category name to std::string for case-insensitive comparison
    auto toLower = [](const std::string& str) -> std::string {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    };
    std::string newCategoryLower = toLower(categoryName.toStdString());

    // Check for predefined category names
    const std::vector<std::string> predefinedCategories = {
        "savings",
        "emergency funds",
        "sinking funds"
    };

    if (std::find(predefinedCategories.begin(), predefinedCategories.end(), newCategoryLower) != predefinedCategories.end()) {
        QMessageBox::warning(this, "Predefined Category",
                             categoryName + " is a predefined category. You can only allocate funds to it.");
        // Clear the input fields
        ui->categoryNameInput->clear();
        ui->categoryBalanceInput->clear();
        return;
    }

    // Check if the category already exists
    bool categoryExists = false;

    // Lambda function for case-insensitive category search
    std::function<void(CategoryNode*)> checkExistingCategory = [&](CategoryNode* node) {
        if (!node) return;

        // Check current node
        if (toLower(node->name) == newCategoryLower) {
            categoryExists = true;
            return;
        }

        // Check left and right subtrees
        checkExistingCategory(node->left);
        checkExistingCategory(node->right);
    };

    // Get the root of the category tree and check for duplicates
    if (currentUser) {
        CategoryNode* root = currentUser->Tracker.getCategoryRoot();
        checkExistingCategory(root);

        if (categoryExists) {
            QMessageBox::warning(this, "Category Exists",
                                 categoryName + " already exists. You can only allocate funds.");
            // Clear the input fields after adding
            ui->categoryNameInput->clear();
            ui->categoryBalanceInput->clear();
            return;
        }

        // Proceed to add the new category
        int initialBalance = ui->categoryBalanceInput->text().toInt();
        currentUser->Tracker.addCategory(categoryName.toStdString());

        // Optionally, allocate the initial balance to the category
        if (initialBalance > 0) {
            currentUser->Tracker.allocateFunds(categoryName.toStdString(), initialBalance);
        }

        QMessageBox::information(this, "Success", "Category added successfully!");
    } else {
        QMessageBox::warning(this, "Error", "No user is logged in!");
    }

    // Clear the input fields after adding
    ui->categoryNameInput->clear();
    ui->categoryBalanceInput->clear();
}

void MainWindow::on_Back_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_ViewCategoryButton_clicked()
{
    ui->categoriesTable->setRowCount(0); // Clear existing rows
    if (currentUser) {
        currentUser->Tracker.viewCategoriesAndBalances(ui->categoriesTable);
        ui->stackedWidget->setCurrentIndex(7);
    } else {
        QMessageBox::warning(this, "Error", "No user is logged in!");
    }
}

void MainWindow::on_Back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_SetGoals_clicked()
{
    // Check if a goal already exists
    if (currentUser && currentUser->Tracker.getCurrentGoal() != nullptr) {
        QMessageBox::warning(this, "Existing Goal", "You already have an existing "
                        "goal. Complete or remove it before setting a new one.");
        return;
    }
    else
        ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_SetGoalButton_clicked() {
    // Get input from UI fields
    double targetAmount = ui->goalAmountInput->text().toDouble();
    int targetMonths = ui->goalMonthsInput->text().toInt();

    // Validate input
    if (targetAmount <= 0 || targetMonths <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter valid values for both target amount and months.");
        return;
    }

    // Set the new goal
    if (currentUser) {
        if (currentUser->Tracker.getCurrentGoal()) {
            QMessageBox::StandardButton response = QMessageBox::question(
                this, "Existing Goal",
                "An existing goal is already set. Do you want to replace it?",
                QMessageBox::Yes | QMessageBox::No);

            if (response == QMessageBox::No) {
                return; // Do not overwrite the existing goal
            }
        }

        DateTime currentDate = currentUser->Tracker.getCurrentDate(); // Get the current date
        currentUser->Tracker.setGoal("Financial Goal", targetAmount, targetMonths, currentDate);

        QMessageBox::information(this, "Goal Set",
                                 QString("Your financial goal has been successfully set!\nStart Date: %1-%2-%3")
                                     .arg(currentDate.day, 2, 10, QChar('0'))
                                     .arg(currentDate.month, 2, 10, QChar('0'))
                                     .arg(currentDate.year));
    } else {
        QMessageBox::warning(this, "Error", "No user is logged in. Please log in to set a goal.");
        return;
    }

    // Clear input fields
    ui->goalAmountInput->clear();
    ui->goalMonthsInput->clear();
}

void MainWindow::on_ViewGoals_clicked() {
    if (!currentUser || currentUser->Tracker.getCurrentGoal() == nullptr) {
        QMessageBox::warning(this, "No Goal Set", "You have not set a financial goal yet.");
        return;
    }

    Goal* goal = currentUser->Tracker.getCurrentGoal();
    DateTime currentDate = currentUser->Tracker.getCurrentDate();

    // Calculate months elapsed since the goal was set
    int monthsElapsed = (currentDate.year - goal->startDate.year) * 12 + (currentDate.month - goal->startDate.month);

    // Check if the goal timeline has been exceeded
    if (monthsElapsed > goal->targetMonths && !goal->isCompleted) {
        QMessageBox::critical(this, "Missed Goal", "You have missed your goal timeline. Please set a new goal.");
        return;
    }

    // Get savings balance and calculate progress
    int savingsBalance = currentUser->Tracker.getSavingsBalance();
    currentUser->Tracker.checkGoalProgress(savingsBalance);

    // Update progress bar
    double progressPercentage = static_cast<double>(goal->goalProgress) / goal->targetAmount * 100;
    ui->goalProgressBar->setValue(static_cast<int>(progressPercentage));

    // Update label with goal details
    QString details = QString("Goal: %1\nTarget Amount: %2\nCurrent Progress: %3\nTime Left: %4 months")
                          .arg(QString::fromStdString(goal->name))
                          .arg(goal->targetAmount)
                          .arg(goal->goalProgress)
                          .arg(goal->targetMonths - monthsElapsed);

    ui->goalDetailsLabel->setText(details);

    // Congratulate the user if the goal is completed
    if (goal->isCompleted) {
        QMessageBox::information(this, "Congratulations!",
                                 "You have achieved your goal: " + QString::fromStdString(goal->name) + "!");
        return;
    }

    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_Back_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::allocateFundsToCategory(const std::string& categoryName, int amount) {
    if (currentUser) {
        if (amount <= 0) {
            QMessageBox::warning(this, "Invalid Amount", "Please enter a valid amount.");
            return;
        }

        // Allocate the funds to the selected category
        if (currentUser->Tracker.allocateFunds(categoryName, amount)) {
            QMessageBox::information(this, "Success",
                                     QString("Allocated %1 to %2.")
                                         .arg(amount)
                                         .arg(QString::fromStdString(categoryName)));
        } else {
            QMessageBox::warning(this, "Error", "Failed to allocate funds. Check your balance.");
        }
    } else {
        QMessageBox::warning(this, "Error", "No user is logged in!");
    }
}

void MainWindow::displayAllocationUI() {
    // Clear the existing layout (if any)
    QLayout* layout = ui->allocationScrollAreaWidgetContents->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout;
    }

    // Create a new vertical layout for the scroll area's widget
    QVBoxLayout* allocationLayout = new QVBoxLayout();

    if (currentUser) {
        // Define a vector to store category names
        std::vector<std::string> categories;

        // Hardcoded predefined categories
        categories.push_back("Savings");
        categories.push_back("Emergency Funds");
        categories.push_back("Sinking Funds");

        // Recursive function to traverse and gather user-defined categories
        std::function<void(CategoryNode*)> gatherCategories = [&](CategoryNode* node) {
            if (!node) return;
            gatherCategories(node->left);
            categories.push_back(node->name);
            gatherCategories(node->right);
        };

        // Get user-defined categories
        gatherCategories(currentUser->Tracker.getCategoryRoot());

        // Dynamically create UI for each category
        for (const auto& categoryName : categories) {
            QLabel* categoryLabel = new QLabel(QString::fromStdString(categoryName), this);
            QLineEdit* amountInput = new QLineEdit(this);
            QPushButton* allocateButton = new QPushButton("Allocate", this);

            // Set placeholder text for the amount input
            amountInput->setPlaceholderText("Enter amount");

            // Connect the allocate button to the allocation logic
            connect(allocateButton, &QPushButton::clicked, this, [=]() {
                allocateFundsToCategory(categoryName, amountInput->text().toInt());
            });

            // Add widgets to the layout
            allocationLayout->addWidget(categoryLabel);
            allocationLayout->addWidget(amountInput);
            allocationLayout->addWidget(allocateButton);
        }
    }

    // Add a spacer at the bottom to ensure proper layout expansion
    allocationLayout->addStretch();

    // Set the new layout to the scroll area's widget contents
    ui->allocationScrollAreaWidgetContents->setLayout(allocationLayout);

    // Ensure the widget expands and scrolls properly
    ui->allocationScrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->allocationScrollAreaWidgetContents->adjustSize();
}

void MainWindow::on_AllocateFunds_clicked()
{
    if (currentUser) {
        // Get the current date from the finance tracker
        DateTime currentDate = currentUser->Tracker.getCurrentDate();

        // Check if it's the first day of the month
        if (currentDate.day != 1) {
            QMessageBox::warning(this, "Invalid Operation",
            "Funds can only be allocated on the 1st day of the month.");
            return;
        }
        displayAllocationUI();
        // Proceed to allocation UI if the condition is satisfied
        ui->stackedWidget->setCurrentIndex(10); // Navigate to allocation page
    } else {
        QMessageBox::warning(this, "Error", "No user is logged in!");
    }
}

void MainWindow::on_Back_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Spend_clicked()
{
    if (!currentUser) {
        QMessageBox::warning(this, "No User", "No user is logged in.");
        return;
    }
    displaySpendUI();
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_Back_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::displaySpendUI() {
    // Clear the existing layout (if any)
    QLayout* layout = ui->spendScrollAreaWidgetContents->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout;
    }

    // Create a new vertical layout for the scroll area's widget
    QVBoxLayout* spendLayout = new QVBoxLayout();

    if (currentUser) {
        // Define a vector to store category names
        std::vector<std::string> categories;

        // Hardcoded predefined categories
        categories.push_back("Savings");
        categories.push_back("Emergency Funds");
        categories.push_back("Sinking Funds");

        // Recursive function to traverse and gather user-defined categories
        std::function<void(CategoryNode*)> gatherCategories = [&](CategoryNode* node) {
            if (!node) return;
            gatherCategories(node->left);
            categories.push_back(node->name);
            gatherCategories(node->right);
        };

        // Get user-defined categories
        gatherCategories(currentUser->Tracker.getCategoryRoot());

        // Dynamically create UI for each category
        for (const auto& categoryName : categories) {
            QLabel* categoryLabel = new QLabel(QString::fromStdString(categoryName), this);
            QLineEdit* amountInput = new QLineEdit(this);
            QPushButton* spendButton = new QPushButton("Spend", this);

            // Set placeholder text for the amount input
            amountInput->setPlaceholderText("Enter amount");

            // Connect the spend button to the spending logic
            connect(spendButton, &QPushButton::clicked, this, [=]() {
                int amount = amountInput->text().toInt();
                if (amount <= 0) {
                    QMessageBox::warning(this, "Error", "Please enter a valid amount.");
                    return;
                }

                if (currentUser->Tracker.spendFunds(categoryName, amount)) {
                    ui->spendStatusLabel->setText(QString("Spent %1 from %2.")
                                                      .arg(amount)
                                                      .arg(QString::fromStdString(categoryName)));
                } else {
                    //QMessageBox::warning(this, "Error", "Please enter a valid amount.");
                    ui->spendStatusLabel->setText(QString("Insufficient funds in %1.")
                                                      .arg(QString::fromStdString(categoryName)));
                }
                amountInput->clear();
            });

            // Add widgets to the layout
            spendLayout->addWidget(categoryLabel);
            spendLayout->addWidget(amountInput);
            spendLayout->addWidget(spendButton);
        }
    }

    // Add a spacer at the bottom to ensure proper layout expansion
    spendLayout->addStretch();

    // Set the new layout to the scroll area's widget contents
    ui->spendScrollAreaWidgetContents->setLayout(spendLayout);

    // Ensure the widget expands and scrolls properly
    ui->spendScrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->spendScrollAreaWidgetContents->adjustSize();
}

void MainWindow::updateDateLabelFromTracker() {
    if (!currentUser) {
        ui->dateLabel->setText("<b>No user is logged in.</b>");
        return;
    }

    // Get the current date from the tracker
    DateTime dateTime = currentUser->Tracker.getCurrentDate();

    // Use HTML for user-friendly formatting
    QString dateText = QString("<b>Date:</b> %1<br>"
                               "<b>Month:</b> %2<br>"
                               "<b>Year:</b> %3")
                           .arg(dateTime.day)
                           .arg(dateTime.month)
                           .arg(dateTime.year);

    // Update the QLabel with the formatted text
    ui->dateLabel->setText(dateText);
}

void MainWindow::on_AdvanceMonth_clicked()
{
    if (!currentUser) {
        // Handle case where no user is logged in
        QMessageBox::warning(this, "Error", "No user is logged in.");
        return;
    }
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_Back_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_advanceMonthButton_clicked()
{

    // Get income from the QLineEdit
    QString incomeText = ui->incomeLineEdit->text();
    if (incomeText.isEmpty() || incomeText.toDouble() <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid income.");
        return;
    }

    double newIncome = incomeText.toDouble();

    try {
        currentUser->Tracker.startNewMonth(newIncome, ui->TaxDeduct, ui->NewIncome);
    } catch (const exception& e) {
        QMessageBox::critical(this, "Error", QString("An error occurred: %1").arg(e.what()));
    }

    // Get the updated date
    DateTime currentDate = currentUser->Tracker.getCurrentDate();

    // Map month numbers to names for user-friendly display
    QStringList monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Create a notification message
    QString message = QString("A new month has started:\n"
                              "Date: %1 %2, %3\n"
                              "Income: %4")
                          .arg(currentDate.day)
                          .arg(monthNames[currentDate.month - 1])
                          .arg(currentDate.year)
                          .arg(newIncome);

    // Show the message in a QMessageBox
    QMessageBox::information(this, "New Month Started", message);

    // Optionally clear the input field after use
    ui->incomeLineEdit->clear();

    // Update any relevant UI elements (e.g., date label)
    updateDateLabelFromTracker();
}

void MainWindow::on_viewMonthlyTransactionsButton_clicked()
{
    if (currentUser) {  // Check if user is logged in
        currentUser->Tracker.showMonthlyTransactions(ui->monthlyTransactionsTableWidget);
        ui->stackedWidget->setCurrentIndex(13);
    } else
        QMessageBox::warning(this, "Not Logged In", "Please log in first.");
}

void MainWindow::on_Back_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_AdvanceDay_clicked()
{
    currentUser->Tracker.startNewDay();
    updateDateLabelFromTracker();
}

void MainWindow::on_Back_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Back_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ExpenseChart_clicked()
{
    if (!currentUser) {
        QMessageBox::warning(this, "Not Logged In", "Please log in first.");
    } else
        currentUser->Tracker.displayPieChart();
}

