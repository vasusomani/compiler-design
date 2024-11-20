#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Expression
{
    string result, opd1, opd2, op;
};

void generateAssemblyCode(const vector<Expression> &expressions)
{
    cout << "\nGenerated Assembly Code:\n";
    cout << "-------------------------\n";

    int regCount = 0; // Register counter
    for (const auto &exp : expressions)
    {
        string reg = "R" + to_string(regCount++); // Allocate a new register

        // Load operand1 into the new register
        cout << "MOV " << exp.opd1 << ", " << reg << "\n";

        // Perform the operation using operand2
        if (exp.op == "+")
        {
            cout << "ADD " << exp.opd2 << ", " << reg << "\n";
        }
        else if (exp.op == "-")
        {
            cout << "SUB " << exp.opd2 << ", " << reg << "\n";
        }
        else if (exp.op == "*")
        {
            cout << "MUL " << exp.opd2 << ", " << reg << "\n";
        }
        else if (exp.op == "/")
        {
            cout << "DIV " << exp.opd2 << ", " << reg << "\n";
        }

        // Store the result in the result variable
        cout << "MOV " << reg << ", " << exp.result << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter number of expressions: ";
    cin >> n;

    vector<Expression> expressions;

    cout << "Enter expressions (like 't = a - b'):\n";
    for (int i = 0; i < n; i++)
    {
        string result, opd1, opd2, op, equalSign;
        cin >> result >> equalSign >> opd1 >> op >> opd2;

        expressions.push_back({result, opd1, opd2, op});
    }

    generateAssemblyCode(expressions);

    return 0;
}
