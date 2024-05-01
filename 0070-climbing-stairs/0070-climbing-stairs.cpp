class Solution {
private:
    static vector<long long> steps;
public:
    int climbStairs(int n) {
        for(int i = steps.size(); i < n + 1; i++)
            steps.push_back(steps[i - 1] + steps[i - 2]);
        
        return steps[n];
    }
};
vector<long long> Solution::steps(2, 1);