#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int longest_common_substring(string x, string y, int n, int m)
{
    forr(i, n + 1)
    {
        forr(j, m + 1)
        {

            //Base condition
            if (i == 0 || j == 0)
                t[i][j] = 0;

            //Two cases......
            else if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];

            else
                t[i][j] = 0;
        }
    }
    return t[n][m];
}

void print_substring(string x, string y, int n, int m)
{
    string res = "", max = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            res = x[i - 1] + res;
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] == 0 && t[i - 1][j] == 0)
                if (res.length() > max.length())
                {
                    max = res;
                    res = "";
                    i--;
                    j--;
                }
        }
    }
    cout << "LCS string : " << max;
}

int main()
{
    string x = "abcdopadghrn";
    string y = "abedopadfhrn";
    int n = x.length();
    int m = y.length();
    cout << "longest common substring length : " << longest_common_substring(x, y, n, m) << " \n";
    print_substring(x, y, n, m);
    cout << endl;
    return 0;
}