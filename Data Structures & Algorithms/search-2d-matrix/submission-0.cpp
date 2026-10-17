class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = find_row(matrix, 0, matrix.size() - 1, target);

        if (row == -1) {
            return false;
        }

        return exists(matrix[row], 0, matrix[row].size() - 1, target);
    }

    bool exists(vector<int>& row, int left, int right, int target) {
        if (left > right) {
            return false;
        }

        int mid = (left + right) / 2;

        if (target == row[mid]) {
            return true;
        } else if (target < row[mid]) {
            return exists(row, left, mid - 1, target);
        } else {
            return exists(row, mid + 1, right, target);
        }
    }

    int find_row(vector<vector<int>>& matrix, int up, int down, int target) {
        if (up > down) {
            return -1;
        }

        int mid = (up + down) / 2;

        int val = matrix[mid][0];
        int m = matrix[mid].size();

        if (target < val) {
            return find_row(matrix, up, mid - 1, target);
        } else if (target >= val && target <= matrix[mid][m - 1]) {
            return mid;
        } else {
            return find_row(matrix, mid + 1, down, target);
        }
    }
};
