/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/
int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);
    for(int i = 0; i < n; i++){
        prev[i] = 1;
    }
    for(int i = 1; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
            if(i==0 and j == 0){
                continue;
            }
            int up = 0, left = 0;
            up = prev[j];
            if (j-1 >= 0){
                left = curr[j-1];
            }
            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[n-1];
}
