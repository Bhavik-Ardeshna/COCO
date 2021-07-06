#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int longest_common_substring(string x, string y, int n, int m)
{
    int res = INT_MIN;

    forr(i, n + 1)
    {
        forr(j, m + 1)
        {

            //Base condition
            if (i == 0 || j == 0)
                t[i][j] = 0;

            // Two case
            // 1. char match ----- so n-1 and m-1
            // 2. char not match ----- so discontinue from their by initializing with 0
            else if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                res = max(res, t[i][j]);
            }
            // Star step
            else
                t[i][j] = 0;
        }
    }
    return res;
}

int main()
{
    string x = "abcdghrn";
    string y = "abedfhrn";
    int n = x.length();
    int m = y.length();
    cout << "longest common substring count : " << longest_common_substring(x, y, n, m) << " \n";

    return 0;
}