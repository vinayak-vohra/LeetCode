class Solution {
public:
    int minGroups(vector<vector<int>>& ints) {
        sort(begin(ints), end(ints));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& i : ints) {
            if (!pq.empty() && pq.top() < i[0])
                pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();