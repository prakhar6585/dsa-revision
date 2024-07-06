#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
int maxPro1(vector<int> &arr)
{
    int max_so_far = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                max_so_far = max(arr[j] - arr[i], max_so_far);
            }
        }
    }
    return max_so_far;
}

// OPTIMAL APPROACH
int maxPro2(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans1 = maxPro1(prices);
    int ans2 = maxPro2(prices);
    cout << "Max profit is : " << ans2 << endl;
}