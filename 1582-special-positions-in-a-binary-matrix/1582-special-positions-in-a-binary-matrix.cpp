/**
 * @author vinayak-vohra
 * @link https://leetcode.com/problems//?envType=daily-question&envId=2023-12-07
 * @brief
 *
 * Time: ms; %
 * Mem : mb; %
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int nRows = mat.size();
        int nCols = mat[0].size();

        vector<int> goodRows(nRows, -1);
        vector<int> goodCols(nCols, -1);
        vector<vector<int>> sparse;

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                if (mat[i][j])
                {
                    // for row
                    goodRows[i] = goodRows[i] == -1 ? 1 : 0;

                    // for col
                    goodCols[j] = goodCols[j] == -1 ? 1 : 0;

                    if (goodRows[i] && goodCols[j])
                        sparse.push_back({i, j});
                }
            }
        }
        int count = 0;
        for (auto &rc : sparse)
            if (goodRows[rc[0]] && goodCols[rc[1]])
                count++;
        return count;
    }
};
