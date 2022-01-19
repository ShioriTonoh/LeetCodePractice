class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix):
    mRow(matrix.size()),
    mCol(matrix[0].size()) {
        preSum.resize(mRow+1,vector<int>(mCol+1,0));
        for(int r=1;r<=mRow;++r)
        {
            for(int c=1;c<=mCol;++c)
            {
                preSum[r][c]=preSum[r-1][c]+preSum[r][c-1]+matrix[r-1][c-1]-preSum[r-1][c-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1]-preSum[row2+1][col1]-preSum[row1][col2+1]+preSum[row1][col1];
    }
private:
    vector<vector<int>> preSum;
    int mRow,mCol;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */