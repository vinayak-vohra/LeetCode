class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        auto gi = g.begin();
        auto si = s.begin();

        while (gi < g.end() && si < s.end())
        {
            if (*gi <= *si)
                count++, gi++;

            si++;
        }
        return count;
    }
};