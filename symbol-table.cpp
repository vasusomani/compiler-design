#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    map<char, string> elements;

    int j = 0;
    while (j < input.size())
    {
        while (j < input.size() && input[j] == ' ')
            j++;
        string temp;
        while (j < input.size() && input[j] != ' ')
        {
            temp += input[j];
            j++;
        }
        j++;

        elements[input[j]] = temp;
        j++;
        if (input[j] == ',')
        { 
            j++;
            elements[input[j]] = temp;
            j++;
        }
        while (j < input.size() && (input[j] == ' ' || input[j] == ';'))
        {
            j++;
        }
    }
    cout << "Symbol Table:" << endl;
    cout << "Symbol   Type      Address" << endl;
    int addr = 1000;
    for (auto it : elements)
    {
        cout << it.first << "       " << it.second << "       " << addr << endl;
        if (it.second == "float")
            addr += 4;
        else
            addr += 2;
    }

    return 0;
}
