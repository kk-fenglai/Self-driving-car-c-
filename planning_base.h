#pragma once
#include <iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

/*******************************ȫ�ֱ���*******************/
constexpr auto SWIDTH = 1200;//���ڵĿ�
constexpr auto SHEIGHT = 1200;//���ڵĸ�
constexpr auto PI= 3.14159265358979323846;//Բ����
constexpr auto SHOWCIRCLE=false;//�Ƿ���ƹ켣
constexpr auto DELAYTIME=20;//���ʱ��
constexpr auto CHANGETIME=1000;//����ʱ��

class Point//��
{
public:
	Point() = default;//Ĭ�Ϲ��캯��
	Point(const double& p_x, const double& p_y, const double& p_theta = 0.0, const double& p_R = 0.0);
	void showPoint();//���Ƶ�
	void pointMove(const double& speed_x, const double& speed_y);//����ƶ�
	void pointTurn(const Point& center, const double& turn_speed);//����center��ת��turn_speedΪ���ٶ�
	double distanceTo(const Point& p) const;//����
	double thetaTo(const Point& p) const;

	double x;
	double y;
	double thetaP = 0.0;
	double Rp = 0.0;
	int r = 5;




};






