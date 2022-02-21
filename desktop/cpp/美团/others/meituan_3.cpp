#include <iostream>
#include <math.h>


class _stdout{
public:
    void outputData(int& M, int& N){
        std::cout << M << " " << N << std::endl;
    }
};


class _stdin{
public:
    void inputData(int& M, int& N){
        std::cin >> M >> N;
    }
};

class _algorithm{
public:
    int algo(int& M, int& N){
        M++;
        N++;
        return M+N;
    }
};



int main(){
    int M, N;
    _stdout Sout;
    _stdin Sin;
    int result;
    _algorithm Algorithm;
    while (1)
    {
        Sin.inputData(M, N);
        result = Algorithm.algo(M, N);
        Sout.outputData(M, N);
    }
    return 0;
}