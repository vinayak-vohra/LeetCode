class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);
        stack<int> mdec;

        for(int i = n - 1; i > -1; i--)
        {
            while(!mdec.empty() && temp[mdec.top()] <= temp[i])
                mdec.pop();

            if(!mdec.empty())
                res[i] = mdec.top() - i;

            mdec.push(i);
        }
        return res;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();