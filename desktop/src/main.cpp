#include "bits/stdc++.h"

 
int main()
{
    long long x;
    std::stringstream ss;
    ss << std::hex << "FFFFFFFF";
    ss >> x;
    // std::string out = "1A";
    // long long x = std::stoi(out, nullptr, 16);
    std::cout << x << std::endl;
    return 0;
}