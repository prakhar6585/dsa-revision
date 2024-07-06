#include <iostream>
#include <stdio.h>
using namespace std;

// BRUTE FORCE APPROACH
bool isSorted1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                return false;
        }
    }
    return true;
}

// OPTITMAL APPROACH
bool isSorted2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {8, 2, 3, 4, 5}, n = 5;
    // bool ans = isSorted1(arr, n);
    bool ans = isSorted2(arr, n);
    if (ans)
        cout << "It is sorted" << endl;
    else
        cout << "It is not sorted" << endl;
    return 0;
}