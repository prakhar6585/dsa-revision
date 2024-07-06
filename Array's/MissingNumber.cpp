#include <iostream>
#include <stdio.h>
using namespace std;

// BETTER APPROACH USING HASH
int missingNumber(int arr[], int n)
{
    int hash[n + 1] = {};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

// OPTIMAL SOLUTION 1 => firstly find the sum from 1 to N. Then check the total of the values of array. The difference between them will be the misssing number.

// OPTIMAL APPROACH 2 => USING XOR METHOD

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = 5;
    missingNumber(arr, n);
}