// Kadane's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

int minimum_sum_subarray(vector<int> a)
{
    int min_cur = a[0];
    int min_glob = a[0];
    forr(i, a.size())
    {
        min_cur = min(min_cur + a[i], a[i]);
        min_glob = min(min_cur, min_glob);
    }
    return min_glob;
}

int main()
{

    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Minimum sum of subarray : " << minimum_sum_subarray(a) << endl;
    return 0;
}