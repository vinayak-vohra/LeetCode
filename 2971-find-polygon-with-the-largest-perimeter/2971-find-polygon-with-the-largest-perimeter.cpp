#pragma gcc ("03", "unroll-loops")
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long maxSum = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < sum)
                maxSum = nums[i] + sum;
                sum += nums[i];
        }        
        return maxSum;
    }
};
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// 1 1 2 3 5 12 50