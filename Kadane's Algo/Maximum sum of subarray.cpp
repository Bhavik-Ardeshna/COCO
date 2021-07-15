// Kadane's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

int maximum_sum_subarray(vector<int> a)
{
    int max_cur = a[0];
    int max_glob = a[0];
    forr(i, a.size())
    {
        max_cur = max(max_cur + a[i], a[i]);
        max_glob = max(max_cur, max_glob);
    }
    return max_glob;
}

int main()
{

    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum sum of subarray : " << maximum_sum_subarray(a) << endl;
    return 0;
}