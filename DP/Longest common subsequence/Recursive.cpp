#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

int LCS_Recursive(string x, string y, int n, int m)
{
    // Base condition
    // n==0 and m==0
    if (n == 0 || m == 0)
        return 0;

    //if x[n-1] == y[m-1]
    // Remove last char
    if (x[n - 1] == y[n - 1])
    {
        return 1 + LCS_Recursive(x, y, n - 1, m - 1);
    }

    //if x[n-1] != y[m-1]
    // keep one full and from other remove last char
    else
    {
        return max(LCS_Recursive(x, y, n - 1, m), LCS_Recursive(x, y, n, m - 1));
    }
}

int main()
{
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.length();
    int m = y.length();

    cout << "LCS count : " << LCS_Recursive(x, y, n, m) << " \n";

    return 0;
}