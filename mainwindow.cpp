#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->calc.setNumberDisplay(this->ui->numberDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button0_clicked()
{
    this->calc.InsertNum(0);
}

void MainWindow::on_button1_clicked()
{
    this->calc.InsertNum(1);
}

void MainWindow::on_button2_clicked()
{
    this->calc.InsertNum(2);
}

void MainWindow::on_button3_clicked()
{
    this->calc.InsertNum(3);
}

void MainWindow::on_button4_clicked()
{
    this->calc.InsertNum(4);
}

void MainWindow::on_button5_clicked()
{
    this->calc.InsertNum(5);
}

void MainWindow::on_button6_clicked()
{
    this->calc.InsertNum(6);
}

void MainWindow::on_button7_clicked()
{
    this->calc.InsertNum(7);
}

void MainWindow::on_button8_clicked()
{
    this->calc.InsertNum(8);
}

void MainWindow::on_button9_clicked()
{
    this->calc.InsertNum(9);
}

void MainWindow::on_buttonPlus_clicked(){
    this->calc.Operation(CALC_ADD);
}

void MainWindow::on_buttonMinus_clicked(){
    this->calc.Operation(CALC_SUBTRACT);
}

void MainWindow::on_buttonMultiply_clicked(){
    this->calc.Operation(CALC_MULTIPLY);
}

void MainWindow::on_buttonDivide_clicked(){
    this->calc.Operation(CALC_DIVIDE);
}

void MainWindow::on_buttonEquals_clicked(){
    this->calc.Equals();
}

void MainWindow::on_buttonDot_clicked(){
    this->calc.StartDecimal();
}

void MainWindow::on_buttonAC_clicked(){
    this->calc.Clear();
}

void MainWindow::on_buttonPM_clicked(){
    this->calc.ChangeSign();
}

void MainWindow::on_buttonMod_clicked(){
    this->calc.Operation(CALC_MODULUS);
}
