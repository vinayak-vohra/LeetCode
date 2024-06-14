class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        int ans = 0;
        for(int i = 0; i < temp.size(); i++)
            if(temp[i] != heights[i])
                ans++;

        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();