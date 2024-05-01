#define len(x) x.size()
#define sort(x) sort(x.begin(), x.end())

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // sol 1
        sort(nums);
        return (nums[len(nums) - 1] - 1) * (nums[len(nums) - 2] - 1);
    }
};