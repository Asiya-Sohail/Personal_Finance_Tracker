#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ContinueButton_clicked();

    void on_SigninButton_clicked();

    void on_LoginButton_clicked();

    void on_Enter_clicked();

    void on_Enter_2_clicked();

    void on_LogoutButton_clicked();

    void on_exit_clicked();

    void on_SetGoals_clicked();

    void on_CurrencyConverter_clicked();

    void on_ConvertButton_clicked();

    void on_ShowRatesButton_clicked();

    void on_Back_clicked();

    void on_AddCategories_clicked();

    void on_addCategoryButton_clicked();

    void on_Back_2_clicked();

    void on_ViewCategoryButton_clicked();

    void on_Back_3_clicked();

    void on_Back_4_clicked();

    void on_SetGoalButton_clicked();

    void on_ViewGoals_clicked();

    void on_Back_5_clicked();

    void on_AllocateFunds_clicked();

    void on_Back_6_clicked();

    void displayAllocationUI();

    void allocateFundsToCategory(const std::string& categoryName, int amount);

    void on_Back_7_clicked();

    void on_Spend_clicked();

    void displaySpendUI();

    void updateDateLabelFromTracker();
    void on_AdvanceMonth_clicked();

    void on_Back_8_clicked();

    void on_advanceMonthButton_clicked();

    void on_viewMonthlyTransactionsButton_clicked();

    void on_Back_9_clicked();

    void on_AdvanceDay_clicked();

    void on_Back_10_clicked();

    void on_Back_11_clicked();

    void on_ExpenseChart_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
