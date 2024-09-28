struct Comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

        for (auto& f : freq) {
            pq.push(f);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (pq.size()) {
            ans.push_back(pq.top().first);
            pq.pop();
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