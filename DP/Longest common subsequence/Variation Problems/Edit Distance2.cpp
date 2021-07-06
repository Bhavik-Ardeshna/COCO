// Convert X----->Y
// 1. Insert t[i][j-1]
// 2. Delete t[i-1][j]
// 3. Replace t[i-1][j-1]
// TS : O(n*m)
// AS: O(n*m)

// Now to reduce AS we can reduce
// Here we need to row for further computation
// t[2][n]
#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

//--------------------------------
// Space Reduction
void EditDistDP(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    // Create a DP array to memoize result
    // of previous computations
    int DP[2][len1 + 1];

    // To fill the DP array with 0
    memset(DP, 0, sizeof DP);

    // Base condition when second string
    // is empty then we remove all characters
    for (int i = 0; i <= len1; i++)
        DP[0][i] = i;

    // Start filling the DP
    // This loop run for every
    // character in second string
    for (int i = 1; i <= len2; i++)
    {
        // This loop compares the char from
        // second string with first string
        // characters
        for (int j = 0; j <= len1; j++)
        {
            // if first string is empty then
            // we have to perform add character
            // operation to get second string
            if (j == 0)
                DP[i % 2][j] = i;

            // if character from both string
            // is same then we do not perform any
            // operation . here i % 2 is for bound
            // the row number.
            else if (str1[j - 1] == str2[i - 1])
            {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }

            // if character from both string is
            // not same then we take the minimum
            // from three specified operation
            else
            {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
                                       min(DP[i % 2][j - 1],
                                           DP[(i - 1) % 2][j - 1]));
            }
        }
    }

    // after complete fill the DP array
    // if the len2 is even then we end
    // up in the 0th row else we end up
    // in the 1th row so we take len2 % 2
    // to get row
    cout << "Space Optimization : " << DP[len2 % 2][len1] << endl;
}

//--------------------------------

int lcs(string x, string y, int n, int m)
{
    forr(i, n + 1)
    {
        forr(j, m + 1)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                t[i][j] = t[i - 1][j - 1];

            else
                t[i][j] = 1 + min(t[i - 1][j], min(t[i][j - 1], t[i - 1][j - 1]));
        }
    }
    return t[n][m];
}

int main()
{
    string x = "food";
    string y = "money";

    int n = x.length();
    int m = y.length();

    int lcs_size = lcs(x, y, n, m);
    cout << "Edit Distance : " << lcs_size << endl;
    EditDistDP(x, y);

    return 0;
}