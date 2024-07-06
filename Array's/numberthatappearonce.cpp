#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
int getSingleElement(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (num == arr[j])
                count++;
        }
        if (count == 1)
            return num;
    }

    return -1;
}

// BETTER APPROACH
int getSingleElement2(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}

// OPTIMAL APPROACH
int getSingleElement3(vector<int> &arr)
{
    // size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}