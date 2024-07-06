#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
vector<int> printLeadersBruteForce(vector<int> &arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }
        if (leader)
            ans.push_back(arr[i]);
    }
    return ans;
}

// OPTIMAL APPROACH
vector<int> optimalApproach(vector<int> &arr, int n)
{
    vector<int> ans;
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    int n = arr.size();

    vector<int> ans1 = printLeadersBruteForce(arr, n);
    vector<int> ans2 = optimalApproach(arr, n);

    for (int i = 0; i < ans1.size(); i++)
    {

        cout << ans1[i] << " ";
    }

    for (int i = 0; i < ans2.size(); i++)
    {

        cout << ans2[i] << " ";
    }

    cout << endl;
    return 0;
}