#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int Sum_of_Subset_Top_Down(vector<int> arr, int tar, int n)
{
    forr(i, 11 + 1)
    {
        t[0][i] = false;
    }
    forr(i, 4 + 1)
    {
        t[i][0] = true;
    }
    forrr(i, 4)
    {
        forrr(s, 11)
        {
            s = s + 10;
            t[i][s] = t[i - 1][s - arr[i - 1]];
            t[i][s] |= t[i - 1][s + arr[i - 1]];
            t[i][s] |= t[i - 1][s];
        }
    }
    return t[n][tar];
}
int main()
{
    vector<int> arr{2, 3, 5};
    int n = 3;
    int sum = -2 + 10;
    cout << Sum_of_Subset_Top_Down(arr, sum, n);
}