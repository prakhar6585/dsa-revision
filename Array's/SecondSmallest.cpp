#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
int getElements1(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        cout << -1 << " " << -1;
    }
    sort(arr, arr + n);
    int small = arr[1];
    int secondLargest = arr[n - 2];
    cout << "Smallest Element" << " " << small << endl;
    cout << "Second largest Element" << " " << secondLargest << endl;
}

// BETTER APPROACH
int getElements2(int arr[], int n)
{
    // for edge case
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int large = INT_MIN;
    int second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }
    cout << "Second Smallest Element is " << second_small << endl;
    cout << "Second Largest Element is " << second_large << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // getElements1(arr, n);
    // getElements2(arr, n);
}