#include <iostream>
#include <stdio.h>
using namespace std;
// It has time complexity of O of N Square at worst case and in best case It has complexity of O of N
int insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

// Insertion sort using recursive approach : It has time complexity of O of N Square at worst case and in best case It has complexity of O of N
int insertion_sort(int arr[], int i, int n)
{
    if (n == i)
        return;
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
    }
    insertion_sort(arr, i + 1, n);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    cout << "Array before sort" << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);

    cout << "Array after sort" << endl;

    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}
