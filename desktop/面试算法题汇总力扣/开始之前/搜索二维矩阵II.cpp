#include "bits/stdc++.h"

using namespace std;
/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/
// 从左下角开始查找 速度会快很多
bool main()
{
    vector<vector<int>> matrix;
    int row = matrix[0].size();
    int col = matrix.size();
    int target;
    int r = row - 1, c = 0;
    while(r >= 0 && c <= col)
    {
        if(matrix[r][c] < target) 
            c++;
        if(matrix[r][c] > target)
            r--;
        if(matrix[r][c] == target)
            return true;
    }

    return false;
}