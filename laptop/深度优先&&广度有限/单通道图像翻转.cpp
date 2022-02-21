#include <bits/stdc++.h>

using namespace std;

void inverse(vector<vector<int> >& mat) {
        // 上下交换
        // for(int i = 0; i < n/2; ++i){
        //     for(int j = 0; j < n; ++j){
        //         swap(mat[i][j], mat[n-1-i][j]);
        //     }
        // }
        //主对角线交换
        for(int i = 0; i < mat.size(); ++i){
            for(int j = i; j < mat[0].size(); ++j){
                swap(mat[i][j], mat[j][i]);
            }
        }
}




int main() {

    vector<vector<int> > img(3, vector<int>(3,0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int tmp;
            cin >> tmp;
            img[i][j] = tmp;
        }
    }
    inverse(img);
    for(int i = 0; i < img.size(); i++) {
        for(int j = 0; j < img[0].size(); j++) {
            cout << img[i][j] << " ";
        }
        cout << endl;
    }   
    return 0;
}