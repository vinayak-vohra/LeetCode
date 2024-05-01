class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& mat) {
        int nRows = mat.size();
        int nCols = mat[0].size();

        vector<int> goodRows(nRows, 0);
        vector<int> goodCols(nCols, 0);
        // vector<vector<int>> diff(nRows, vector<int>(nCols, 0));

        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)    
                if (mat[i][j])
                    goodRows[i]++, goodCols[j]++;
        
        for(int i = 0; i < nRows; i++)
            for(int j = 0; j < nCols; j++)
                mat[i][j] = goodRows[i] + goodCols[j] - (nRows - goodRows[i]) - (nCols - goodCols[j]);

        return mat;
    }
};