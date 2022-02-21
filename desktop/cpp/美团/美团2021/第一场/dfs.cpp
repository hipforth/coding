//深度优先搜索求岛屿数量

#include <./bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> >& grid, int x, int y)
{
    grid[x][y] = 0;
    if(x - 1 >= 0 && grid[x-1][y] == 1) dfs(grid, x-1, y);
    if(y + 1 < grid[0].size() && grid[x][y+1] == 1) dfs(grid, x, y+1);
    if(x + 1 < grid.size() && grid[x+1][y] == 1) dfs(grid, x+1, y);
    if(y - 1 >= 0 && grid[x][y-1] == 1) dfs(grid, x, y-1);
}

int numIslands(vector<vector<int> >& grid)
{   
    int nums_islands = 0;
    for(int x = 0; x < grid.size(); x++)
    {
        for(int y = 0; y < grid[0].size(); y++)
        {
            if(grid[x][y] == 1)
            {
                nums_islands++;
                dfs(grid, x, y);
            }
        }
    }
    return nums_islands;
}


int main()
{
    vector<vector<int> > island(4, vector<int>(5,0));
    for(int i = 0; i < island.size(); i++)
    {
        for(int j = 0; j < island[0].size(); j++)
        {
            int tmp;
            cin >> tmp;
            island[i][j] = tmp;
        }
    }
    cout << numIslands(island);
    return 0;

}