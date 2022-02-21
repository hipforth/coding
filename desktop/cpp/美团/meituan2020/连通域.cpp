/*
 * 二值图求最大连通域：https://blog.csdn.net/weixin_43795395/article/details/90338956
 * 1. 连通区域标记：二值图像分析的基础，通过对二值图像中白色像素的标记，让每个单独的连通区域形成一个被标识的块。
 *    进一步获取这些块的轮廓、外接矩形、质心、不变矩等几何参数。
 * 2. 求最大连通的算法：根据定义有8点法和4点法。
 * 3. 常见算法：1）Two-Pass法；2）Seed-Filling种子填充法
 * 连通区域的定义：连通区域是由具有相同像素值的相邻像素组成像素集合。
 * 1. 对于每个连通区域，赋予唯一个Lable
 *  
*/

#include <bits/stdc++.h>

using namespace std;

void two_pass(vector<vector<int> > mat, vector<vector<int> > label) {
    int lab = 1;
    label[0][0] = lab;
    lab += 1;
    for(int i = 0,j = 1; j < mat[i].size(); j++) {
        if(mat[i][j] == 1) {
            if(mat[i][j-1] == 1) label[i][j] = label[i][j-1];
            
        }
    }
}

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
    two_pass(mat, label);
}


/*
1 0 1 1 0 1
0 1 1 0 0 1
1 0 1 1 0 0
0 1 0 1 0 0
1 1 1 1 0 1
0 0 1 1 0 0
*/