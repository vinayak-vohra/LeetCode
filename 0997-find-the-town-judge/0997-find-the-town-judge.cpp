#pragma gcc("03", "unroll-loops")
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<bool> judge(n+1, 1);
       judge[0] = false;
       unordered_map<int, int> trusted;

       for(int i=0; i<trust.size(); i++) {
           judge[trust[i][0]] = false;
           trusted[trust[i][1]]++;
       }

        // int ans = -1;
       for(int i=1; i<=n; i++) {
           if(judge[i] && trusted[i] == n-1)
            return i;
       }
       return -1;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();