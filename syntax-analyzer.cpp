#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isOp(char ch)
{
    if (ch == '-' || ch == '+' || ch == '/' || ch == '*' || ch == '=')
        return true;
    return false;
}

bool checkValid(string &s)
{
    if (isOp(s[0]))
        return false;

    for (int i = 1; i < s.length(); i++)
    {
        if (i % 2 == 1)
        {
            if (!isOp(s[i]))
                return false;
        }
        else
        {
            if (isOp(s[i]))
                return false;
        }
    }

    return !isOp(*(s.end()));
}

int main()
{
    string s;
    cin >> s;
    cout << (checkValid(s) ? "Correct" : "Incorrect");
}