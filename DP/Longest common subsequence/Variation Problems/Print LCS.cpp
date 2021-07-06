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

            //Base condition
            if (i == 0 || j == 0)
                t[i][j] = 0;

            //Two cases......
            else if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];

            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][m];
}

void print_LCS(string x, string y, int n, int m)
{
    vector<char> res;
    int i = n, j = m;
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
            if (t[i][j - 1] > t[i - 1][j])
                j--;
            else
                i--;
        }
    }
    cout << "LCS string : ";
    for (auto it = res.rbegin(); it != res.rend(); ++it)
    {
        cout << *it << " ";
    }
}

int main()
{
    string x = "abcdghrn";
    string y = "abedfhrn";
    int n = x.length();
    int m = y.length();
    cout << "longest common substring length : " << lcs(x, y, n, m) << " \n";
    print_LCS(x, y, n, m);
    cout << endl;
    return 0;
}