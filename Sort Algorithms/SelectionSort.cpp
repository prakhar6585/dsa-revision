#include <iostream>
#include <stdio.h>
using namespace std;

int selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    cout << "Array before sort" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);

    cout << "Array after sort" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}