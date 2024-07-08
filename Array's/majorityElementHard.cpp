#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
int majorityElement1(vector<int> &arr)
{

    // size of the given array:
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (arr[j] == arr[i])
            {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return arr[i];
    }

    return -1;
}

// BETTER APPROACH
int majorityElement2(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// OPTIMAL APPROACH OR MOORE'S VOTING ALGORITHM
int majorityElement3(vector<int> &v)
{
    // size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el;      // Element

    // applying the algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i])
            cnt++;
        else
            cnt--;
    }

    // checking if the stored element
    //  is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans1 = majorityElement1(arr);
    int ans2 = majorityElement2(arr);
    int ans3 = majorityElement3(arr);
    cout << "The majority element is: " << ans1 << endl;
    return 0;
}
