#include <bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int> &arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return true;
    }
    return false;
}

// BRUTE FORCE APPROACH
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size(); // size of array
    int longest = 1;
    // pick a element and search for its
    // consecutive numbers:
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    vector<int> ans1 = longestSuccessiveElements(arr);
    cout << "The longest consecutive sequence is " << ans1 << "\n";
    return 0;
}