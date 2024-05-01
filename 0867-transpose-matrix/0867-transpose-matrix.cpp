class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        if (rows == cols)
        {
            for (int i = 0; i < matrix.size(); i++)
                for (int j = i + 1; j < matrix.size(); j++)
                    swap(matrix[i][j], matrix[j][i]);

            return matrix;
        }
        vector<vector<int>> newMat(cols, vector<int>(rows));

        for (int i = 0; i < cols; i++)
            for (int j = 0; j < rows; j++)
                newMat[i][j] = matrix[j][i];

        return newMat;
    }
};