class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());

            while (k--) {
            int top = pq.top();
            pq.pop();
            ans += top;
            pq.push(ceil(top / 3.0));
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