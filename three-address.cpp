#include <iostream>
#include <cstdio>
using namespace std;

int precedence(char op){
    if(op=='+' || op=='-' ){
        return 1;
    }
    if(op=='/' || op=='*'){
        return 2;
    }
    return 0;
}

int main()
{
    char lhs, var1, var2, var3, op1, op2, op3;
    printf("Enter expression (eg: a=b*c-d)");
    scanf("%c=%c%c%c%c%c", &lhs, &var1, &op1, &var2, &op2, &var3);

    if (precedence(op1) >= precedence(op2))
    {
        // op1 has higher or equal precedence
        cout << "t1 = " << var1 << " " << op1 << " " << var2 << endl;
        cout << "t2 = t1 " << op2 << " " << var3 << endl;
        cout << lhs << " = t2" << endl;
    }
    else
    {
        // op2 has higher precedence
        cout << "t1 = " << var2 << " " << op2 << " " << var3 << endl;
        cout << "t2 = " << var1 << " " << op1 << " t1" << endl;
        cout << lhs << " = t2" << endl;
    }
}