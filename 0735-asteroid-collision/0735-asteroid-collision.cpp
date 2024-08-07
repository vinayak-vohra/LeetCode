class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans;

        for (int a : ast) {
            while (ans.size() &&                 // not empty
                   *ans.rbegin() > 0 && a < 0 && // collision
                   abs(a) > *ans.rbegin()        // current can destroy previous
            )
                ans.pop_back();

            // current asteroid biggest
            if (!ans.size()) {
                ans.push_back(a);
            }

            // never meet
            else if (*ans.rbegin() < 0 || a > 0)
                ans.push_back(a);

            // same size, opposite dir
            else if (*ans.rbegin() == -a)
                ans.pop_back();
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