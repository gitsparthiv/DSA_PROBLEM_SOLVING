class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int m = matrix.size();
     int n = matrix[0].size();
     for(int i = 0; i < m; i++)
     {
        int low = 0;
        int high = n - 1;
        // int low = matrix[i][0];
        // int high = matrix[i][n - 1];
        if(target <= matrix[i][high]){
        while(high >= low){
            int mid = low + ((high - low)/2);
            if(matrix[i][mid] == target){
                return true;
            }
            else if(matrix[i][mid] < target){
                low = mid + 1;
            }
            else if(matrix[i][mid] > target){
                high = mid - 1;
            }
        }
        }
        else{
            continue;
        }
     }
     return false;
    }
};
