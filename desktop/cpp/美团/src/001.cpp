#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int _n = n;
    vector<int> w;
    vector<int> vec;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        w.push_back(tmp);
    }
    while(_n--)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp-1);
    }
    
    int sum_l = 0, sum_r = 0;
    int q = vec[0];
    w[q] = 0;
    for(int i = 0; i < w.size(); i++)
    {
        if(i < q )
        {
            sum_l += w[i];
        }
        if(i > q)
        {
            sum_r += w[i];
        }
    }
    cout << max(sum_r, sum_l) << endl;
    int pre_q = q;
    for(int i = 1; i < vec.size(); i++)
    {
        q = vec[i];
        if(q < pre_q)
        {
            for(int i = q; i <= pre_q; i++)
            {
                sum_l -= w[i];
                sum_r += w[i];
            }
            sum_r -= w[q];
            w[q] = 0;
            pre_q = q;
        }
        if(q > pre_q)
        {
            for(int i = pre_q; i < q; i++)
            {
                sum_l += w[i];
                sum_r -= w[i];
            }
            sum_r -= w[q];
            w[q] = 0;
            pre_q = q;
        }
        cout << max(sum_r, sum_l) << endl;;

    }


    return 0;
}