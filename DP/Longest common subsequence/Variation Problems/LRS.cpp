// Longest Repeating Subsequence
// LRS = LCS(s,s) and i!=j

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

            // i!=j
            else if (x[i - 1] == y[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][m];
}

void print_lrs(string x, int n)
{
    string s = "";
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (t[i][j] == t[i - 1][j - 1] + 1)
        {
            s = x[i - 1] + s;
            j--;
            i--;
        }
        else if (t[i][j] == t[i - 1][j])
            i--;
        else
            j--;
    }
    cout << "Print LRS : " << s << endl;
}

int main()
{
    string x = "aaxyyy";

    cout << "Longest Repeating Subsequence : " << lcs(x, x, x.length(), x.length()) << endl;
    cout << "DP Table for observation to see how print happens!!!!! \n";
    forr(i, x.length() + 1)
    {
        cout << endl;
        forr(j, x.length() + 1)
        {
            cout << t[i][j] << " ";
        }
    }
    cout << "\n\n";
    print_lrs(x, x.length());

    return 0;
}