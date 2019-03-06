#include "calculator.h"
#include <string>
#include <cmath>
#include <QTextFormat>

Calculator::Calculator()
{
    this->currentNum = 0.0;
    this->lastNum = 0.0;
}

auto Calculator::setNumberDisplay(QLabel* numberDisplay) -> void {
    this->numberDisplay = numberDisplay;
}

auto Calculator::Render() -> void {
    std::string temp;
    if (this->currentNum - static_cast<int>(this->currentNum) > 0){
        temp = std::to_string(this->currentNum);
        int i = 0;
        while (temp[i] == '0')
            i++;
        temp.erase(0, i);
        i = 0;
        while (temp[temp.size() - 1 - i] == '0')
            i++;
        temp.erase(temp.size() - i, i);
    } else {
        temp = std::to_string(static_cast<int>(this->currentNum));
    }
    this->numberDisplay->setFont(QFont("Trebuchet MS", this->fontSizes[temp.size()]));
    this->numberDisplay->setText(QString::fromStdString(temp));
}

auto Calculator::InsertNum(int num) -> void {
    if (this->decimalDigit > 0){
        if (this->decimalDigit < 100000000){
            this->currentNum = this->currentNum + (static_cast<double>(num) / decimalDigit);
            this->decimalDigit *= 10;
        }
    } else if (this->currentNum < 1000000000.0) {
        this->currentNum = (this->currentNum * 10) + num;
    }
    this->Render();
}

auto Calculator::Calculate() -> void {
    if (this->currentOp != CALC_NOTHING){
        if (this->currentOp == CALC_ADD){
            this->currentNum += this->lastNum;
        } else if (this->currentOp == CALC_SUBTRACT){
            this->currentNum = this->lastNum - this->currentNum;
        } else if (this->currentOp == CALC_MULTIPLY){
            this->currentNum *= this->lastNum;
        } else if (this->currentOp == CALC_DIVIDE){
            this->currentNum = this->lastNum / this->currentNum;
        } else if (this->currentOp == CALC_MODULUS){
            this->currentNum = std::fmod(this->lastNum, this->currentNum);
        }
        this->lastNum = 0.0;
    }
    this->bankedOp = this->currentOp;
    this->currentOp = CALC_NOTHING;
}

auto Calculator::Operation(short Op) -> void {
    if (this->currentOp != CALC_NOTHING) this->Calculate();
    this->currentOp = Op;
    this->decimalDigit = 0;
    this->lastNum = this->currentNum;
    this->currentNum = 0.0;
    this->Render();
}

auto Calculator::Equals() -> void {
    if (this->currentOp == CALC_NOTHING){
        this->lastNum = this->currentNum;
        this->currentNum = this->bankedNum;
        this->currentOp = this->bankedOp;
    } else {
        this->bankedNum = this->currentNum;
    }
    this->decimalDigit = 0;
    this->Calculate();
    this->Render();
}

auto Calculator::StartDecimal() -> void {
    if (this->decimalDigit == 0) this->decimalDigit = 10;
}

auto Calculator::Clear() -> void {
    this->decimalDigit = 0;
    this->currentNum = this->lastNum = this->bankedNum = 0.0;
    this->currentOp = this->bankedOp = 0;
    this->Render();
}

auto Calculator::ChangeSign() -> void {
    this->currentNum *= -1.0;
}
