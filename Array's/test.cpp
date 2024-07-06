#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int countDigits(int n)
{
    int cnt = (int)(log10(n) + 1);
    return cnt;
}
int main()
{
    int N = 432568;
    cout << "N: " << N << endl;
    int digits = countDigits(N);
    cout << "Number of Digits in N: " << digits << endl;
    return 0;
}