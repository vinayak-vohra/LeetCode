class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        unordered_map<string, int> vis;
        int i = 0;
        for (string& s : list1) {
            vis[s] = i++;
        }

        i = 0;
        int lis = 2002;
        vector<string> ans;

        for (string& s : list2) {
            if (vis.count(s)) {
                int lisi = vis[s] + i;
                if (lisi < lis) {
                    ans.clear();
                    lis = lisi;
                    ans.push_back(s);
                } else if (lisi == lis) {
                    ans.push_back(s);
                }
            }
            i++;
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