#include <bits/stdc++.h>

using namespace std;


bool check_char_num(char& c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    else return false;
}


void check(string& s)
{
    char c = s[0];
    bool num_flag = false;
    bool flag = false;
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'z'))
    {
        for(auto x : s)
        {
            if(check_char_num(x))
            {
                if(x >= '0' && x <= '9') num_flag = true;
            }
            else
            {
                flag = true;
                cout << "Wrong" << endl;
                break;
            }
        }
        if(!flag)
        {
            if(num_flag)  cout << "Accept" << endl;
            else cout << "Wrong" << endl;
        }
    }
    else
    {
        cout << "Wrong" << endl;
    }

    
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vec.push_back(s);
    }
    for(auto s : vec)
    {
        check(s);
    }
    return 0;
}

/*
5
Ooook
Hhhh666
ABCD
Meituan
6666
*/