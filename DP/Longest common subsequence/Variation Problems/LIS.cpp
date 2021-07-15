// Longest Repeating Subsequence
// LRS = LCS(s,s) and i!=j

// LPS = LCS (  string , reverse ( string )  )

// LIS = LCS(arr,sort(arr))

#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int lcs(vector<int> x, vector<int> y, int n, int m)
{

    forr(i, n + 1)
    {
        forr(j, m + 1)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;

            // i!=j
            else if (x[i - 1] == y[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][m];
}

int main()
{
    vector<int> x{7, 7, 7, 7, 7, 7, 7};

    cout << "Longest Increasing Subsequence : " << lcs(x, x, x.size(), x.size()) << endl;

    return 0;
}