/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int si = 0, ei = n*m-1;
    int mid = (si + ei)/2;
    while(si <= ei){
        int mid = (si + ei)/2;
        int i = mid/m, j = mid%m;
        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] > target){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }
    return false;
}
