class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for(int x: nums) {
            freq[x]++;
        }
        
        int i = 0;
        for(int j=0; j < 3; ++j) {
            std::fill(nums.begin() + i, nums.begin() + i + freq[j], j);
            i += freq[j];
        }
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();