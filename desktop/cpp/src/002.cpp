#include <bits/stdc++.h>

using namespace std;

bool my_sort(int a, int b)
{
    return a >= b;
}

int main()
{
    int n, p, q;
    while(cin >> n >> p >> q)
    {   
        
        vector<int> score;//考试分数
        for(int i = 0; i < n; i++)
        {
            int tmp;//考试成绩
            cin >> tmp;
            score.push_back(tmp);
        }
        sort(score.begin(), score.end(), my_sort);
        int final_people = 0;
        double pre_pingshi = 100;
        double pingshi = 100;
        double _final = 0;
        double tmp = (pre_pingshi * p + score[0] * q) / 100;
        if(tmp >= 60) final_people += 1;
        for(int i = 1; i < n; i++)
        {
            
            _final = 0;
            if(score[i] == score[i-1])
            {
                pingshi = pre_pingshi;
            }
            else{
                pingshi = pre_pingshi - 1;
                pre_pingshi = pre_pingshi - 1;
            }
            _final = (pingshi * p + score[i] * q) / 100;
            if(_final >= 60) final_people += 1;
        }
        cout << final_people;
    }
    return 0;
}


/*
第一行三个正整数n，p，q（1<=n<=200,0<=p<=100,0<=q<=100,p+q=100）

第二行n个正整数表示n个学生的期末考试分数（0<=分数<=100）
*/