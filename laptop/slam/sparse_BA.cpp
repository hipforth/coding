#include "bits/stdc++.h"
#include <eigen3/Eigen/Dense>

int main()
{
    double a = 1.0, b = 2.0, c = 1.0;
    int N = 100;
    double w_sigma = 1.0;
    double ae = 10.0, be = -10.0, ce = 10.0;

    std::vector<std::pair<double, double>> data;
    std::random_device rd;
    std::default_random_engine generator_(rd());
    std::normal_distribution<double> noise(0.0, 1.0);
    //产生数据
    for(int i = 0; i < N; i++)
    {
        double x = i/100;
        double y = exp(a*x*x + b*x + c) + noise(generator_);
        data.push_back({x, y});
    }

    int iterations = 100;
    double cost = 0, lastcost = 0;

    for(int iter = 0; iter < iterations; iter++)
    {
        Eigen::Matrix3d H = Eigen::Matrix3d::Zero();
        Eigen::Vector3d b = Eigen::Vector3d::Zero();
        cost = 0;

        for(int i = 0; i < N; i++)
        {
            double xi = data[i].first;
            double yi = data[i].second;
            double error_i = yi - exp(ae*xi*xi + be*xi + ce);
            Eigen::Vector3d J = Eigen::Vector3d::Zero();

            J[0] = - xi*xi*exp(ae*xi*xi + be*xi + ce);
            J[1] = - xi*exp(ae*xi*xi + be*xi + ce);
            J[2] = - exp(ae*xi*xi + be*xi + ce);

            H += J * J.transpose();
            b += -error_i * J;

            cost += error_i*error_i;
        }
        

        Eigen::Vector3d dx;
        //dx = H.inverse() * b;//直接求逆
        //dx = H.colPivHouseholderQr().solve(b); //QR分解
        dx = H.ldlt().solve(b); //ldlt分解

        //更新估计值
        ae += dx[0];
        be += dx[1];
        ce += dx[2];

        lastcost = cost;
    }

    return 0;
}