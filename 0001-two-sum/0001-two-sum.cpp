class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            auto it = umap.find(comp);

            if (it != umap.end())
                return {it->second, i};
            else
                umap[nums[i]] = i;
        }
        return {0, 0};
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();