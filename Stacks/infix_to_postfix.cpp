// The reason for converting infix to postfix is the compiler scans the expression
// from left to right or from right to left

// In infix the compiler needs to scan the expression multiple times to evaluate it
// Infix : a + b * c + d
// Postfix : abc*+d+

#include <bits/stdc++.h>
using namespace std;

// returns precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;

    else if (c == '/' || c == '*')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    else
        return -1;
}

// returns associativity of operators
char associativity(char c)
{
    if (c == '^')
        return 'R';

    return 'L';
}

void infixToPostfix(string str)
{
    stack<char> st;
    string postfix;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }

        else if (c == '(')
        {
            st.push(c);
        }

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(c) < prec(st.top()) || !st.empty() && prec(c) == prec(st.top()) && associativity(c) == 'L')
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    cout << postfix << endl;
}

int main()
{
    string str = "a+b*c+d";
    infixToPostfix(str);
    return 0;
}