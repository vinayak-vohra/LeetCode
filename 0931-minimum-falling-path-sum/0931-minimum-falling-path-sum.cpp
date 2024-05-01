class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        if(mat.size() == 1) 
            return mat[0][0];

        int ans = INT_MAX;
        int size = mat.size();
        int minimum;

        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                minimum = (j == 0) ? mat[i - 1][j] : std::min(mat[i - 1][j], mat[i - 1][j - 1]);
                minimum = (j == size - 1) ? minimum : std::min(minimum, mat[i - 1][j + 1]);
                mat[i][j] += minimum;

                if(i == size - 1)
                    ans = std::min(ans, mat[i][j]);
            }
        }

        return ans;
    }
};