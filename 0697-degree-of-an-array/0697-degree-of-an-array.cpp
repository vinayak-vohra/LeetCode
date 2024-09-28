struct Meta {
    int count;
    int first;
    int last;
    Meta() : count(0), first(-1), last(-1) {}
};
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, Meta> freq;
        Meta* ptr = nullptr;
        int i = 0;

        for (int n : nums) {
            ptr = &freq[n];
            ptr->count++;
            if (ptr->first < 0)
                ptr->first = i;
            ptr->last = i;
            i++;
        }

        int deg = 1, ans = 1;
        for (auto& f : freq) {
            ptr = &f.second;
            if (ptr->count > deg) {
                deg = ptr->count;
                ans = ptr->last - ptr->first + 1;
            } else if (ptr->count == deg) {
                ans = min(ans, ptr->last - ptr->first + 1);
            }
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();