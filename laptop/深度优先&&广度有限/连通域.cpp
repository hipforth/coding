/*
 * 二值图求最大连通域：https://blog.csdn.net/weixin_43795395/article/details/90338956
 * 1. 连通区域标记：二值图像分析的基础，通过对二值图像中白色像素的标记，让每个单独的连通区域形成一个被标识的块。
 *    进一步获取这些块的轮廓、外接矩形、质心、不变矩等几何参数。
 * 2. 求最大连通的算法：根据定义有8点法和4点法。
 * 3. 常见算法：1）Two-Pass法；2）Seed-Filling种子填充法
 * 连通区域的定义：连通区域是由具有相同像素值的相邻像素组成像素集合。
 * 1. 对于每个连通区域，赋予唯一个Lable
 *  
 * 直接深度优先搜索！！！
*/

#include <bits/stdc++.h>

using namespace std;

//找最大的连通域的面积
class Solution {
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};

//找连通域的数量
class Solution1
{
public:
    int numIslands(vector<vector<int>>& grid)
    {
        int nr = grid.size();
        if(nr == 0) return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        for(int r = 0; r < nr; r++)
        {
            for(int c = 0; c < nc; c++)
            {
                if(grid[r][c] == 1)
                {
                    ++num_islands;
                    helper(grid, r, c);
                }
            }
        }
        return num_islands;
    }
private:
    void helper(vector<vector<int>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = 0;
        if(r-1 >= 0 && grid[r-1][c] == 1) helper(grid, r-1, c);
        if(r+1 < nr && grid[r+1][c] == 1) helper(grid, r+1, c);
        if(c-1 >= 0 && grid[r][c-1] == 1) helper(grid, r, c-1);
        if(c+1 < nc && grid[r][c+1] == 1) helper(grid, r, c+1);
    }
};

int main() {
    vector<vector<int> > mat(6, vector<int>(6,0));
    vector<vector<int> > label(6, vector<int>(6,0));
    for(int i = 0; i < mat.size(); i ++) {
        for(int j = 0; j < mat[i].size(); j++) {
            int tmp;
            cin >> tmp;
            mat[i][j] = tmp;
        }
    }
    //two_pass(mat, label);
}


/*
1 0 1 1 0 1
0 1 1 0 0 1
1 0 1 1 0 0
0 1 0 1 0 0
1 1 1 1 0 1
0 0 1 1 0 0
*/