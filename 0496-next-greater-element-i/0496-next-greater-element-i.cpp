class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ng;
        stack<int> stk;
        stk.push(1e5);
        for (auto s = nums2.rbegin(); s != nums2.rend(); s++) {
            while (*s >= stk.top())
                stk.pop();
            int tos = stk.top();
            ng[*s] = (tos == 1e5) ? -1 : tos;
            stk.push(*s);
        }
        for (int& n : nums1) {
            n = ng[n];
        }
        return nums1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();