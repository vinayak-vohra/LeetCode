class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> won;
        unordered_map<int, int> lost;
        vector<vector<int>> res(2, vector<int>());

        for (auto &match : matches)
        {
            // if (won[match[0]] == 0 &&              // first win
            //     lost.find(match[0]) == lost.end()) // no loses
            // {
            //     wonAll.insert(match[0]);
            // }

            // auto it = won.find(match[1]);
            // if (it != won.end())
            //     wonAll.erase(it->first);

            // it = lost.find(match[1]);
            // if (it == lost.end())
            //     lost1.insert(match[1]);

            // else if (it->second == 1)
            //     lost1.erase(it->first);

            won[match[0]]++;
            lost[match[1]]++;
        }

        for(auto&x: won)
        {
            if(lost.find(x.first)==lost.end())
                res[0].push_back(x.first);
        }

        for(auto&x: lost)
        {
            if(x.second == 1)
                res[1].push_back(x.first);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};