#include <iostream>
#include <cmath>

using namespace std;

class Calculator
{
protected:
    int a, b;
    int ans;
    char ch;

public:
    void operands();
};

void Calculator::operands()
{
    cout << "Enter operands: ";
    cin >> a >> b;

    cout << "Enter operator (+, -, *, /): ";
    cin >> ch;

    if (ch == '+')
    {
        ans = a + b;
        cout << "The sum of " << a << " and " << b << " is " << ans << endl;
    }
    else if (ch == '-')
    {
        ans = a - b;
        cout << "The difference of " << a << " and " << b << " is " << ans << endl;
    }
    else if (ch == '*')
    {
        ans = a * b;
        cout << "The product of " << a << " and " << b << " is " << ans << endl;
    }
    else if (ch == '/')
    {
        if (b == 0)
        {
            cout << "Error! Division by zero is not allowed." << endl;
        }
        else
        {
            ans = a / b;
            cout << "The quotient of " << a << " divided by " << b << " is " << ans << endl;
        }
    }
    else
    {
        cout << "Invalid operator!" << endl;
    }
}

class ScientificCalculator
{
public:
    void exponentiation();
    void squareRoot();
    void logarithm();
    void trigonometry();
};

void ScientificCalculator::exponentiation()
{
    int base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;

    cout << base << "^" << exponent << " = " << pow(base, exponent) << endl;
}

void ScientificCalculator::squareRoot()
{
    double num;
    cout << "Enter a number to find the square root: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Error! Square root of a negative number is not defined in real numbers." << endl;
    }
    else
    {
        cout << "Square root of " << num << " is " << sqrt(num) << endl;
    }
}

void ScientificCalculator::logarithm()
{
    double num;
    cout << "Enter a number to find the natural logarithm (ln): ";
    cin >> num;

    if (num <= 0)
    {
        cout << "Error! Logarithm of zero or a negative number is undefined." << endl;
    }
    else
    {
        cout << "ln(" << num << ") = " << log(num) << endl;
    }
}

void ScientificCalculator::trigonometry()
{
    double angle;
    int choice;

    cout << "Choose a trigonometric function: \n";
    cout << "1 - Sine (sin)\n2 - Cosine (cos)\n3 - Tangent (tan)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter angle in degrees: ";
    cin >> angle;
    double radians = angle * (M_PI / 180.0); // Convert degrees to radians

    switch (choice)
    {
    case 1:
        cout << "sin(" << angle << ") = " << sin(radians) << endl;
        break;
    case 2:
        cout << "cos(" << angle << ") = " << cos(radians) << endl;
        break;
    case 3:
        cout << "tan(" << angle << ") = " << tan(radians) << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

class HybridCalculator : public Calculator, public ScientificCalculator
{
};

int main()
{
    int option;
    HybridCalculator finalCalc;

    cout << "Choose calculator: \n";
    cout << "1 - Normal Calculator\n";
    cout << "2 - Scientific Calculator\n";
    cout << "Enter your choice: ";
    cin >> option;

    if (option == 1)
    {
        finalCalc.operands();
    }
    else if (option == 2)
    {
        int sciOption;
        cout << "\nChoose Scientific Operation:\n";
        cout << "1 - Exponentiation (Power)\n";
        cout << "2 - Square Root\n";
        cout << "3 - Logarithm (ln)\n";
        cout << "4 - Trigonometry (sin, cos, tan)\n";
        cout << "Enter your choice: ";
        cin >> sciOption;

        switch (sciOption)
        {
        case 1:
            finalCalc.exponentiation();
            break;
        case 2:
            finalCalc.squareRoot();
            break;
        case 3:
            finalCalc.logarithm();
            break;
        case 4:
            finalCalc.trigonometry();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}