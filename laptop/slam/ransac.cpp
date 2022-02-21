#include "bits/stdc++.h"
#include <Eigen/Dense>
/*
1. 随机选择两个点(确定一条直线的最小点集)；由这两个点确定一条直线l;
2. 根据阈值t，确定与直线l的几何距离小于t的数据点集S(l)， 称为l的一致集。
3. 重复若干次选择，得到直线l1, l2, l3 ... ln相应的一致集S(ln);
4. 使用几何距离，求最大一致集的最佳拟合直线，作为数据点的最佳匹配直线。
简单来讲，就是随机n次选取两个点计算n条直线，分别计算n条直线的内点，内点最多的使用这些内点最小二乘来拟合一条直线。

需要设置的参数：采样次数和几何距离阈值t
*/

//一个最小二乘拟合函数，一个两点法求直线的函数，一个筛选当前内点的函数

class Ransac
{
    Ransac(){a = 1;b = 0;}
public:
    //输入一对点，获取直线方程
    Eigen::Vector2d getLine(std::pair<double, double>& point1, std::pair<double, double>& point2)
    {

    }
    //筛选当前内点
    std::vector<std::pair<double, double>> getInlier(std::vector<std::pair<double, double>>& nPoints, Eigen::Vector2d& ab)
    {

    }
    //最小二乘法拟合直线
    Eigen::Vector2d LeastSquard(std::vector<std::pair<double, double>>& points)
    {

    }
private:
    double a;
    double b;
};

int main()
{

    return 0;
}