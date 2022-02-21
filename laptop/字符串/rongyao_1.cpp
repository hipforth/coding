#include <bits/stdc++.h>

using namespace std;

vector<string> vec;

int main()
{
    int N;
    cin >> N;
    vector<string> _vec;
    string s;
    cin >> s;
    _vec.push_back(s);

    while(cin.get() != '\n')
    {
        string str;
        cin >> str;
        
        _vec.push_back(str);
    }

    for(auto& x : _vec)
    {
        if(x.empty()) continue;
        if(x.size() <= 8)
        {
            string temp;
            temp = x;
            for(int i = 0; i < 8-x.size(); i++) temp.append("0");
            vec.push_back(temp);
        }
        if(x.size() > 8)
        {
            int n = x.size() / 8;
            int _i = 0;
            while(n--)
            {
                stringstream stream;
                stream << x[_i];
                string temp = stream.str();
                for(int i = 1; i <= 7; i++)
                {
                    char c = x[_i+i];
                    temp = temp + c;
                }
                _i += 8;
                vec.push_back(temp);
                temp.clear(); 
            }

            int m = x.size() % 8;
            if(m > 0)
            {
                string temp;
                for(int i = 8; i < x.size(); i++)
                    temp = temp + x[i];
                for(int i = m; i <= 7; i++)
                {
                    temp = temp + "0";
                }
                vec.push_back(temp);
            }
        }    
    }
    sort(vec.begin(), vec.end());

    for(auto x : vec)
    {
        cout << x << " ";
    }
    return 0;
}