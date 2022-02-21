#include <bits/stdc++.h>

using namespace std;

bool less_sort(int a, int b)
{
    return a < b;
}

bool greater_sort(int a, int b)
{
    return a > b;
}

void meituan014(map<int, int>& ab, int x, int y) 
{

    if(x == y)
    {
        for(int i = 0; i < x; i++)
        {
            cout << "A";
        }
        for(int i = 0; i < y; i++)
        {
            cout << "B";
        }
    }
    if(x < y)
    {
        auto iter = ab.end();
        iter--;
        vector<int> out(x+y,2001);
        for(int i = 0; i < x; i++)
        {
            out[i] = iter->second;
            iter--;
        }
        sort(out.begin(),out.end(), less_sort);
        int j = 0;
        for(int i = 0; i < x+y; i++)
        {
            if(i == out[j]) 
            {
                cout << "A";
                j++;
            }
            
            else cout << "B";
        }
    }
    if(x > y)
    {
        auto iter = ab.begin();
        vector<int> out(x+y,20001);
        for(int i = 0; i < x; i++){
            out[i] = iter->second;
            iter++;
        }
        sort(out.begin(),out.end(), less_sort);
        int j = 0;
        for(int i = 0; i < x+y; i++)
        {
            if(i == out[j]) 
            {
                cout << "A";
                j++;
            }
            
            else cout << "B";
        }
    }

}


int main() {

    int x, y;
    cin >> x >> y;
    map<int, int> ab;
    for(int i = 0; i < x+y; i++)
    {
        int tmp;
        cin >> tmp;
        ab[tmp] = i;
    }
    meituan014(ab, x, y);
    return 0;
}