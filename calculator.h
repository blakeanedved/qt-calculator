#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QLabel>

#define CALC_NOTHING 0
#define CALC_ADD 1
#define CALC_SUBTRACT 2
#define CALC_MULTIPLY 3
#define CALC_DIVIDE 4
#define CALC_MODULUS 5

class Calculator
{
private:
    double currentNum, lastNum, bankedNum;
    short currentOp, bankedOp;
    int decimalDigit = 0;
    QLabel* numberDisplay;
    QLabel* lastNumberDisplay;
    int fontSizes[18] = {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 34, 32, 30, 26, 24, 22, 22, 20};
    std::string symbols[6] = {" ", "+", "-", "×", "÷", "%"};

public:
    Calculator();
    auto setNumberDisplay(QLabel* numberDisplay, QLabel* lastNumberDisplay) -> void;
    auto Render() -> void;
    auto InsertNum(int num) -> void;
    auto Calculate() -> void;
    auto Operation(short Op) -> void;
    auto Equals() -> void;
    auto StartDecimal() -> void;
    auto Clear() -> void;
    auto ChangeSign() -> void;
    auto FormatNumber(double num, short extraBit) -> std::string;
};

#endif // CALCULATOR_H
