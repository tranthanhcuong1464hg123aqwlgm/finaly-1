#include <iostream>
class ComplexNumber {
private:
    int realPart;
    int imaginaryPart;

public:
    ComplexNumber(int real, int imaginary) : realPart(real), imaginaryPart(imaginary) {}
    void input() {
        std::cout << "Enter the real part: ";
        std::cin >> realPart;

        std::cout << "Enter the imaginary part: ";
        std::cin >> imaginaryPart;
    }
    void output() const {
        std::cout << realPart;
        if (imaginaryPart >= 0) {
            std::cout << " + " << imaginaryPart << "√7";
        } else {
            std::cout << " - " << -imaginaryPart << "√7";
        }
        std::cout << std::endl;
    }
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }
    ComplexNumber operator-() const {
        return ComplexNumber(-realPart, -imaginaryPart);
    }
    ComplexNumber operator*(const ComplexNumber& other) const {
        int newReal = realPart * other.realPart - 7 * imaginaryPart * other.imaginaryPart;
        int newImaginary = realPart * other.imaginaryPart + other.realPart * imaginaryPart;
        return ComplexNumber(newReal, newImaginary);
    }
};
int main() {
    ComplexNumber num1(1, 2);
    ComplexNumber num2(3, -4);
    ComplexNumber sum = num1 + num2;
    ComplexNumber difference = num1 - num2;
    ComplexNumber negation = -num1;
    ComplexNumber product = num1 * num2;
    std::cout << "num1: ";
    num1.output();
    std::cout << "num2: ";
    num2.output();
    std::cout << "Sum: ";
    sum.output();
    std::cout << "Difference: ";
    difference.output();
    std::cout << "Negation of num1: ";
    negation.output();
    std::cout << "Product: ";
    product.output();
    return 0;
}
