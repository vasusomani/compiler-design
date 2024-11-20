#include <iostream>
#include <string>
#include <vector>
using namespace std;

void optimizeCode(vector<string> &lines)
{
    cout << "\nAfter Optimization:\n";
    vector<char> lhs;
    vector<string> rhs;
    for (string s : lines)
    {
        lhs.push_back(s[0]);
        rhs.push_back(s.substr(2));
    }
    string res;
    res += lhs.back();
    res += "=";

    string lastRhs = rhs.back();
    for (int i = 0; i < lastRhs.length(); i++)
    {
        bool replaced = false;
        for (int j = 0; j < lhs.size(); j++)
        {
            if (lastRhs[i] == lhs[j])
            {
                res += rhs[j];
                replaced = true;
                break;
            }
        }

        if (!replaced)
        {
            res += lastRhs[i];
        }
    }
    cout << res;
}

int main()
{
    int n;
    cout << "\nEnter the number of lines in the code: ";
    cin >> n;

    vector<string> lines(n);
    cout << "Enter the code (line by line):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i];
    }

    // Before
    cout << "\nBefore Optimization:\n";
    for (const string &line : lines)
    {
        cout << line << endl;
    }

    // After
    optimizeCode(lines);
}
