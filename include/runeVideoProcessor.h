#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
#include<cmath>
#include"rune_detect.h"
#include"blade.h"
#include"myFunction.h"
#include<string>
#include <memory>
#include<deque>

//用于处理多张连续的神符图像
class runeVideoProcessor
{
private:
    std::unique_ptr<Rune_detect> _rune_detect_ptr;   //记录最新帧的神符状态
    std::unique_ptr<Rune_detect> _rune_detect_last_ptr;  //记录上一帧的神符状态
    std::vector<Blade> _blades; //用于保存五个神符的最新信息
    std::vector<std::vector<cv::Point2f>> _blades_position_array;   //保存五个神符的历史信息 外层vector:时间 -> 内层vector：五片扇叶中心
    cv::Point2f _rotationCenter;     //记录神符的旋转中心
    double _rotationSpeed;      //记录神符的当前旋转速度
    std::vector<double> _blades_rotation_Speed; //记录当前五片扇叶的旋转速度
    std::vector<double> _rotationSpeed_array; //记录神符的历史旋转速度
    std::deque<std::vector<cv::Point2f>> _blades_polar_position_array; //存储一段时间内的扇叶中心的极坐标数据，方便计算速度。
    int _blades_polar_position_array_size;     //_blades_polar_position_array存储双向列表的内容量大小(取偶数哦~)
    int _getSpeed_n;    //表示速度时，所采用的两点之间的图像张数。
    std::vector<std::vector<int>> _blades_rotationCount_array;  //外层vector保存五个扇叶，内vector保存一个扇叶的历史记录。
    void Init();
    void setRotationCenter();
    void setBladePosition();   
    bool setSpeed();
    bool setRotationFunction();
    bool _start_flag;
    int _num;   //记录图像读取的次数
public: 
    cv::Mat _src;       //存储最新读到的图片
    runeVideoProcessor();
    bool read(cv::Mat src);    //读取新的图片、进行位置更新
    bool src_show(std::string winname = "src");   //展示读取到的新图片
    bool show(std::string winname = "runeVideoProcessor show");   //展示识别效果
    bool getStartFlag();
    int getNum();
    bool print_rotationCenter(cv::Mat src_show);
    bool print_blades_angle(cv::Mat src_show);
    bool print_blades_num(cv::Mat src_show);
    bool print_rotation_speed(cv::Mat src_show);
    bool blades_polar_position_show(cv::Mat src_show);
    bool rotation_speed_show(cv::Mat src_show);
    


};


