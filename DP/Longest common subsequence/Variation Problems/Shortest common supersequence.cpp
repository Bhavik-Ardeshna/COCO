#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

// Two Approach

// 1. Used to calculate only length
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

// 2. User to print and determine lenght
int dp[1001][1001];

int lcs_super(string x, string y, int n, int m)
{

    forr(i, n + 1)
    {
        forr(j, m + 1)
        {
            // if n=0 than subseq will length of m of that subproblem vice versa
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;
            // If equal found decreament both and add 1 to count
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            // if unequal observe than take min from both case and consider only one
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

void print_lcs(string x, string y, int n, int m)
{
    int i = n, j = m;
    string res;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            res.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                //t[i-1][j] is greater than move horizontally in string y left
                res.push_back(y[j - 1]);
                j--;
            }
            else
            {
                res.push_back(x[i - 1]);
                i--;
            }
        }
    }
    // If Y reaches its end, put remaining characters
    // of X in the result string
    while (i > 0)
    {
        res.push_back(x[i - 1]);
        i--;
    }

    // If X reaches its end, put remaining characters
    // of Y in the result string
    while (j > 0)
    {
        res.push_back(y[j - 1]);
        j--;
    }

    // reverse the string and return it
    reverse(res.begin(), res.end());

    cout << " Shortest Common Super Sequence : " << res << endl;
}

// Main function
int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int n = x.length();
    int m = y.length();
    int lcs_size = lcs(x, y, n, m);
    cout << " Using First Method \n";
    cout << " Shortest Common Super Sequence : " << n + m - lcs_size << endl;
    cout << " Using Second Method \n";
    cout << " Shortest Common Super Sequence : " << lcs_super(x, y, n, m) << endl;
    print_lcs(x, y, n, m);
    return 0;
}