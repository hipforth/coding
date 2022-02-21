#include <bits/stdc++.h>

using namespace std;


void meituan002(vector<int>& W, vector<int>& List) {

    int pre_l = List[0] - 1;
    long left_sum = 0;
    long right_sum = 0;
    for(int i = 0; i < W.size(); i++){
        if(i < pre_l) left_sum += W[i];
        if(i > pre_l) right_sum += W[i];
    }
    cout << max(left_sum, right_sum) << endl;
    W[pre_l] = 0;
    for(int i = 1; i < List.size(); i++) {
        int l = List[i] - 1;
        if(l < pre_l) {
            for(int j = l; j < pre_l; j++) {
                left_sum -= W[j];
                right_sum += W[j];
            }
        }
        if(l >= pre_l) {
            for(int j = pre_l; j < l; j++) {
                left_sum += W[j];
                right_sum -= W[j];
            }
        }
        pre_l = l;
        right_sum -= W[pre_l];
        W[pre_l] = 0;
        cout << max(left_sum, right_sum) << endl;
    }
}


int main() {
    int T;
    cin >> T;
    int T_1 = T;
    std::vector<int> W;
    while(T--){
        int w;
        cin >> w;
        W.push_back(w);
    }
    std::vector<int> List;
    while(T_1--) {
        int list;
        cin >> list;
        List.push_back(list);
    }
    meituan002(W, List);
    return 0;
}