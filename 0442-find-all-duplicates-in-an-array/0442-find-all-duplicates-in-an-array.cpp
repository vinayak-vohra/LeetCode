class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int& n : nums) {
            int i = abs(n) - 1;
            if (nums[i] < 0)
                res.push_back(i + 1);
            nums[i] = -nums[i];
        }
        return res;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();