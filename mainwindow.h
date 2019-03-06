#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QMainWindow>
#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_button0_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_buttonPlus_clicked();
    void on_buttonMinus_clicked();
    void on_buttonMultiply_clicked();
    void on_buttonDivide_clicked();
    void on_buttonMod_clicked();
    void on_buttonEquals_clicked();
    void on_buttonAC_clicked();
    void on_buttonDot_clicked();
    void on_buttonPM_clicked();

private:
    Ui::MainWindow* ui;
    Calculator calc;
};

#endif // MAINWINDOW_H
