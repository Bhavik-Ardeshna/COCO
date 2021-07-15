// Kadane's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

int maximum_product_subarray(vector<int> nums)
{
    // If negative number comes swap maximum and minimum value

    int max_glob = nums[0];
    int max_cur = nums[0];
    int min_cur = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            int temp = max_cur;
            max_cur = min_cur;
            min_cur = temp;
        }
        max_cur = max(nums[i], max_cur * nums[i]);
        min_cur = min(nums[i], min_cur * nums[i]);
        max_glob = max(max_glob, max_cur);
    }
    return max_glob;
}

int main()
{

    vector<int> a{2, 3, -2, 4};
    cout << "Maximum product of subarray : " << maximum_product_subarray(a) << endl;
    return 0;
}