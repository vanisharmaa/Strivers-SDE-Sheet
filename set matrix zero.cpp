/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

void setZeroes(vector<vector<int>>& matrix) {
    bool col = 1; //create a boolen variable to check if there is any 0 in 0th column
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++){
        if(matrix[i][0] == 0){ //check check
            col = 0;
        }
        for(int j = 1; j < m; j++){ //put the firts row and first col as the dummy matrices themselves
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i = n-1; i >= 0; i--){ //check from [n-1][m-1] to all the way till top
        for(int j = m-1; j >= 1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
        if(col == 0){ //and if there is a zero in the first column
            matrix[i][0] = 0; //put the [i][0] index to be zero.
        }
    }
}
