/*
S->aA|aAB|b

S->aS'|b
S'->B|ep
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void removeLeftFactoring(const string &data)
{
    char start = data[0];        // Start symbol (non-terminal)
    string rhs = data.substr(3); // Right-hand side of the production

    // Split RHS into prod
    vector<string> prod;
    for (int i = 3; i < data.length(); i++)
    {
        string s = "";
        while (i<data.length() && data[i] != '/')
        {
            s += data[i++];
        }
        prod.push_back(s);
    }

    // Find the longest common prefix
    string prefix = "";
    string prod1 = prod[0];
    string prod2 = prod[1];
    for (int i = 0; i < min(prod1.length(), prod2.length()); i++)
    {
        if (prod1[i] == prod2[i])
            prefix += prod1[i];
        else
            break;
    }

    // Divide into alpha and beta
    vector<string> alpha, beta;
    for (string s : prod)
    {
        int i;
        for (i = 0; i < prefix.length(); i++)
        {
            if (s[i] != prefix[i])
                break;
        }
        if (i < s.length())
        {
            if (i != 0)
            {
                alpha.push_back(s.substr(i));
            }
            else
            {
                beta.push_back(s);
            }
        }
    }

    // Output the left-factored grammar
    cout << "\nOutput:\n";
    cout << start << " -> " << prefix << start << "'";
    for (string s : beta)
    {
        cout << " / " << s;
    }
    cout << "\n";

    cout << start << "' -> ";
    for (size_t i = 0; i < alpha.size(); i++)
    {
        cout << alpha[i];
        if (i != alpha.size() - 1)
            cout << " / ";
    }
    cout << " / ε\n";
}

int main()
{
    string data;
    cout << "Enter the production (e.g., S->iEtS/iEtSeS/a): ";
    cin >> data;
    removeLeftFactoring(data);
}
