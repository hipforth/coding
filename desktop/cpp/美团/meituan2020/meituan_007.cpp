#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int N = n;
    set<int> out;
    while(n--) {
        int m = N - n;
        while (m--)
        {
            int tmp;
            cin >> tmp;
            int pre_size = out.size();
            out.insert(tmp);
            if(out.size() == pre_size + 1) {
                cout << tmp << " ";
                cin.ignore(numeric_limits<int>::max(), '\n');
                break;
            }
        }
        
    }

    return 0;
}