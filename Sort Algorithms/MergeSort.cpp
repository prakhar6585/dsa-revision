#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // pushing Pushing sorted array from array one and array two in the temporary array

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
        }
        if (arr[right] <= arr[left])
        {
            temp.push_back(arr[right]);
        }
    }

    // If after above steps some elements are left in both parts of array then push it in the temporary array if (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    if (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int> &arr, int low, int high)
{
    vector<int> temp;
    int left = low;
    int right = high;

    if (low >= high)
        return;
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}
int main()
{
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}