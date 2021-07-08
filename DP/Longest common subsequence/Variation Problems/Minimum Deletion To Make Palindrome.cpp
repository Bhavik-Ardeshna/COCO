// LPS = LCS (  string , reverse ( string )  )

#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int lcs(string x, string y, int n, int m)
{

    forr(i, n + 1)
    {
        forr(j, m + 1)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][m];
}

int main()
{
    string x = "agbciopba";
    string rev = x;

    // LPS = LCS(s,reverse(s))
    reverse(rev.begin(), rev.end());

    int res = x.length() - lcs(x, rev, x.length(), rev.length());

    cout << " Number of delete operation to make string palindrome : " << res << endl;

    return 0;
}