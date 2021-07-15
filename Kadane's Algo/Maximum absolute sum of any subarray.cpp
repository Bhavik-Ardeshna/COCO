// Kadane's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

int kadane(vector<int> a)
{
    int max_cur = a[0];
    int max_glob = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        max_cur = max(max_cur + a[i], a[i]);
        max_glob = max(max_cur, max_glob);
    }
    return max_glob;
}
int maxAbsoluteSum(vector<int> &nums)
{
    int a = kadane(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] *= -1;
    }
    int b = kadane(nums);
    return max(a, b);
}

int main()
{

    vector<int> a{1, -3, 2, 3, -4};
    cout << "Maximum absolute sum of subarray : " << maxAbsoluteSum(a) << endl;
    return 0;
}