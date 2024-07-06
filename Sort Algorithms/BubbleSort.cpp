#include <bits/stdc++.h>
using namespace std;

// with time complexity : O(n^2)
void bubble_sort(int arr[], int n)
{
    // bubble sort
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// with time complexity for best case : O(n)
void bubble_sort(int arr[], int n)
{
    // bubble sort
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// with  recursion time complexity : O(n^2) , Space Complexity : O(N)
void bubble_sort(int arr[], int n)
{
    // Base case for recursion
    if (n == 1)
        return;
    int isSwap = 0;
    for (int j = 0; j <= n - 2; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            isSwap = 1;
        }
    }
    if (isSwap == 0)
    {
        return;
    }
    bubble_sort(arr, n - 1);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;
}
