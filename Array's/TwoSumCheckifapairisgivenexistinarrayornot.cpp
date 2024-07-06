#include <bits/stdc++.h>
#include <vector>
using namespace std;

// BRUTE FORCH APPROACH FOR VARIANT 1
string twoSum1(vector<int> &arr, int target, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
                return "YES";
        }
    }
    return "NO";
}

// BRUTE FORCE APPROACH FOR VARIANT 2
vector<int> twoSum2(vector<int> &arr, int target, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}

// BETTER APPROACH FOR VARIANT 1
string twoSumBetter1(vector<int> &arr, int target, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (map.find(moreNeeded) != map.end())
        {
            return "YES";
        }
    }
    return "NO";
}

// BETTER APPROACH FOR VARIANT 2
vector<int> twoSumBetter2(vector<int> &arr, int target, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (map.find(moreNeeded) != map.end())
        {
            return {map[moreNeeded], i};
        }
        map[num] = i;
    }
    return {-1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ansForVariant1 = twoSum1(arr, target, n);
    cout << "This is the ans for variant 1 : " << ansForVariant1;
    cout << endl;
    vector<int> ansForVariant2 = twoSum2(arr, target, n);
    cout << "This is the answer for variant 2: [" << ansForVariant2[0] << ", "
         << ansForVariant2[1] << "]" << endl;
    string ansForVariant1BETTER = twoSumBetter1(arr, target, n);
    cout << "This is the ans of better approach for variant 1 : " << ansForVariant1BETTER << endl;
    vector<int> ansForVariant2BETTER = twoSumBetter2(arr, target, n);
    cout << "This is the ans of better approach for variant 1 : " << ansForVariant2BETTER << endl;
    return 0;
}
