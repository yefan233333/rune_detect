#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
#include<cmath>

class myLine
{
friend std::ostream& operator<<(std::ostream& cout,const myLine& myline);
private:
    double _A;
    double _B;
    double _C;
public:

    myLine(){};
    myLine(double A,double B,double C):_A(A),_B(B),_C(C){};
    myLine(double k,double m);
    myLine(cv::Point2f p1,cv::Point2f p2,cv::Point2f p3);
    myLine(cv::Point2f p1,cv::Point2f p2);
    void init(cv::Point2f p1,cv::Point2f p2,cv::Point2f p3);
    void init(cv::Point2f p1,cv::Point2f p2);
    double get_x(double y);
    double get_y(double x);
    void print(cv::Mat src_show,cv::Scalar color = cv::Scalar(200,40,140));
    cv::Point2f intersectLine(myLine l2);
    myLine getPerpLine(double x);
};