#include<bits/stdc++.h> 
#include <queue>
using namespace std;
  
 const int maxn = 1e2 + 10;
 int maze[maxn][maxn];
 int dx[4] = { 0, 0, 1, -1 };
 int dy[4] = { 1, -1, 0, 0 };
 bool visited[maxn][maxn];
 int m, n;
 
 struct node {
     int x;
     int y;
     int step;
 }S,Node,T;
 
 bool judge(int x, int y) {
     if(x>=m ||y>=n||x<0||y<0) return false;  //超出边界，不合理 
	if(visited[x][y] ==true) return false;    //已经走过，不合理
	if(maze[x][y] == 1)   return false;     // 障碍物， 不合理
	return true; 
 }
 
 int BFS() {
 	 queue<node>q;
     q.push(S);
     while (!q.empty()) {
         node top = q.front();
         q.pop();
         if (top.x == m - 1 && top.y == n - 1) {  //到达右下角 
             return top.step;
         }
         for (int i = 0; i < 4; i++) {
             int newx = top.x + dx[i];
             int newy = top.y + dy[i];
             if (judge(newx, newy)) {
                 Node.x = newx;
                 Node.y = newy;
                 Node.step = top.step + 1;
                 q.push(Node);
                 visited[newx][newy] = true;
             }
         }
     }
 }
 
 int main() {
     cin >> m >> n;
     for (int i = 0; i < m; i++)
         for (int j = 0; j < n; j++)
             cin >> maze[i][j];
    S.x = 0;
    S.y = 0;
    S.step = 0;
    cout<<BFS();
    return 0;
 }

