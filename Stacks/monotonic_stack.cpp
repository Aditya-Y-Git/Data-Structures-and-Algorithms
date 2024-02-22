#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printStack(int arr[], int new_arr[], int n, int m)
{
    cout << "The array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The Stack: ";
    for (int i = 0; i < m; i++)
    {
        cout << new_arr[i] << " ";
    }
    cout << endl;
}

// monotonic increasing stack
void increasingStack(int arr[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() > arr[i])
        {
            s.pop();
        }
        s.push(arr[i]);
    }

    int sze = s.size();
    int new_arr[sze] = {0};
    int j = sze - 1;
    while (!s.empty())
    {
        new_arr[j--] = s.top();
        s.pop();
    }

    printStack(arr, new_arr, n, sze);
}

// monotonic decreasing stack
void decreasingStack(int arr[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() < arr[i])
        {
            s.pop();
        }
        s.push(arr[i]);
    }

    int sze = s.size();
    int new_arr[sze] = {0};
    int j = sze - 1;
    while (!s.empty())
    {
        new_arr[j--] = s.top();
        s.pop();
    }

    printStack(arr, new_arr, n, sze);
}

int main()
{
    int arr[] = {1, 4, 5, 3, 12, 10};
    int arr2[] = {15, 17, 12, 13, 14, 14, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    increasingStack(arr, n);
    decreasingStack(arr2, m);
    return 0;
}