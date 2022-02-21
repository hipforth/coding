#include <bits/stdc++.h>

using namespace std;


void UsernameCheck(string &user) {
    bool number = false;
    bool flag = false;
    if(!isalpha(user[0])) 
        cout << "Wrong" << endl;
    else {
        for(int i = 0; i < user.size(); i++){
            if(!isalnum(user[i])) {
                cout << "Wrong" << endl;
                flag = true;
                break;
            }
            if(isdigit(user[i])) number = true;
        }
        if(!flag)
        if(number) cout << "Accept" << endl;
        else cout << "Wrong" << endl;
        else ;
    }
    
}



int main() {
    
    int T;
    cin >> T;
    while(T--){
        string Username;
        cin >> Username;
        UsernameCheck(Username);
    }
    return 0;
}