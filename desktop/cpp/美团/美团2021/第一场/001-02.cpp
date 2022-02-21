#include <bits/stdc++.h>

using namespace std;



int main()
{
    double num=0, sum=0;
    for(int i = 1; i <= 5; i++)
    {
        double _score;
        cin >> _score;
        num += _score;
        sum = sum + (i * _score);
    }
    if(num == 0) cout << "0.0";
    else
    {
        cout.precision(2);
        int _sum = (int)((sum / num) * 10);
        double out = (double)_sum/10;
        cout << out;
    }
    return 0;
}