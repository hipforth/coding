#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double x = b*b - 4*a*c;
    if(x > 0)
    {
        double x1 = (-b + sqrt(x)) / (2*a);
        double x2 = (-b - sqrt(x)) / (2*a);
        if(x1 > x2)
        {
            cout << x1 << endl;
            cout << x2 << endl;
        } 
        else
        {
            cout << x2 << endl;
            cout << x1 << endl;
        }
    }
    if(x == 0)
    {
        double x0 = -b / (2*a);
        cout << x0 << endl;
        cout << x0 << endl;
    }
    if(x < 0)
    {
        x = -x;
        double x1, x2;
        x1 = -b / (2*a);
        x2 = sqrt(x) / (2*a);
        cout << x1 << " " << x2 << endl;
        x2 = -x2;
        cout << x1 << " " << x2 << endl;
    }
    return 0;
}