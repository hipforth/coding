#include "bits/stdc++.h"
#include <eigen3/Eigen/Dense>
#include <sophus/se3.hpp>
#include <sophus/so3.hpp>

int main()
{
    std::vector<std::pair<Eigen::Vector3d, Eigen::Vector2d>> matched_point;
    Eigen::Matrix3d R = Eigen::Matrix3d::Identity();
    Eigen::Vector2d t = Eigen::Vector2d::Zero();
    Eigen::Matrix3d K = Eigen::Matrix3d::Identity();
    Sophus::SE3<double> T_esti(R,t);

    Eigen::Matrix<double, 6, 6> H;
    Eigen::Matrix<double, 6, 1> b;
    double cost = 0;
    for(int i = 0; i < matched_point.size(); i++)
    {
        //Eigen::Vector3d p3d = matched_point[i].first;
        Eigen::Vector3d p2d = {matched_point[i].second.x(), matched_point[i].second.y(), 1};
        Eigen::Vector3d p3d = K * (R * matched_point[i].first + t);
        Eigen::Vector3d _p3d = p3d / p3d.z();

        Eigen::Vector2d r = {_p3d.x() - p2d.x(), _p3d.y() - p2d.y()};

        Eigen::Matrix<double, 2, 6> J;
        J.setZero();
        
        H += J.transpose() * J;
        b += - J.transpose() * r;
        cost += (r[0]*r[0] + r[1]*r[1]);
    }
    Eigen::Matrix<double, 6, 1> dx;
    dx = H.ldlt().solve(b);
    T_esti = Sophus::SE3<double>::exp(dx)*T_esti;
    return 0;
}