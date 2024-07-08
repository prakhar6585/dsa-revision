// 3 Sum : Find triplets that add up to a zero
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
vector<vector<int>> triplet1(int n, vector<int> &arr)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; j < n; j++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// BETTER APPROACH
vector<vector<int>> triplet2(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = (arr[i] + arr[j]);

            // find element in the hash set
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// OPTIMAL APPROACH
vector<vector<int>> triplet3(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        // remove duplicates
        (i != 0 && arr[i] == arr[i - 1]);
        continue;

        // moving  two pointers
        int j = i + 1;
        int k = n - 1;

        int sum = arr[i] + arr[j] + arr[k];
        if (sum < 0)
        {
            j++;
        }
        else if (sum > 0)
        {
            k--;
        }
        else
        {
            vector<int> temp = {arr[i], arr[j], arr[k]};
            ans.push_back(temp);
            j++;
            k--;
            // skip the duplicates:
            while (j < k && arr[j] == arr[j - 1])
                j++;
            while (j < k && arr[k] == arr[k + 1])
                k--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet1(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}