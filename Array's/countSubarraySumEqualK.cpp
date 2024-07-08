#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
int findAllSubarraysWithGivenSum1(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];

            if (sum == k)
                count++;
        }
    }
    return count;
}

// BETTER APPROACH
int findAllSubarraysWithGivenSum2(vector<int> &arr, int k)
{
}

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt1 = findAllSubarraysWithGivenSum1(arr, k);
    int cnt2 = findAllSubarraysWithGivenSum2(arr, k);
    cout << "The number of subarrays is: " << cnt1 << "\n";
    return 0;
}