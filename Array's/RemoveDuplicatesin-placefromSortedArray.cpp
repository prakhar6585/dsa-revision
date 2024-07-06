#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE METHOD : SET DATA STRUCTURE APPROACH
int removeDuplicates(int arr[], int n)
{
    set<int> set;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set)
    {
        arr[j++] = x;
    }
    return k;
}

// OPTIMAL APPROACH : TWO POINTER APPROACH
int removeDuplicates1(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int k = removeDuplicates(arr, n);
    int k = removeDuplicates1(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}