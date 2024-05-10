#pragma once
#include "planning_base.h"
/*状态机*/
enum Shift//挡位
{
	m_D,//前进档
	m_N,//空挡
	m_R,//倒挡
	m_P//驻车挡
};

enum TurnDirection//转向状态机
{
	TurnRight,//右转
	TurnLeft,//左转
};

/*车基类*/
class CarBase
{
public:
	CarBase();
	virtual ~CarBase() = default;//虚析构
	void initCar(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length);//初始化
	void updatePmidf();//更新前中点xy值
	void updatePmidr();//更新后中点xy值
	void updatePmid();//更新几何中点xy值
	void showCar(const COLORREF& color);//绘制车辆矩形
	void showCircle();//绘制轨迹线
	void coutInfo();//打印信息

	void moveStraightStep();//单帧直行
	void carTurnStep();//单帧转向



public:
	double car_width = 80.0;//车宽
	double car_length = 160.0;//车长

	unique_ptr<Point> plf;//左前点
	unique_ptr<Point> plr;//左后点
	unique_ptr<Point> prf;//右前点
	unique_ptr<Point> prr; //右后点
	unique_ptr<Point> p_center;//转向中心点

	unique_ptr<Point> pmidf;//前轴中心点
	unique_ptr<Point> pmidr;//后轴中心点
	unique_ptr<Point> pmid;//几何中心点

	double Rmin = 100.0;//最小转弯半径
	double Rof = 0.0;//外前半径
	double Ror = 0.0;//外后半径
	double Rif = 0.0;//内前半径
	double Rir = 0.0;//内后半径

	double R0;//半斜长.自转半径
	double theta0;//atan(car_length / car_width)

	double speed = 0.0;//合速度，可正负，负数代表前进，正数代表倒车
	double speed_x = 0.0;//x方向分速度，负数为左边，正数为右边
	double speed_y = 0.0;//y方向分速度，负数为向上，正数代表向下

	double a = 0.0;//合加速度，可正负，负数代表加速，正数代表减速
	double a_x = 0.0;//x方向分加速度，可正负，负数为左加速度，正数为右加速度
	double a_y = 0.0;//y方向分加速度，可正负，负数为上加速度，正数为下加速度

	double delta_theta = 0.0;//角速度，可正负，负数代表顺时针转向，正数代表逆时针转向
	double delta_theta_rot = 0.0;//自转角速度，负数代表顺时针转向，正数代表逆时针转向
	double heading_theta = 0.0;//偏航角，为0时车辆竖直向上，负数代表向左偏航，正数代表向右偏航



	int Gear = m_P;//挡位
	

};

CarBase::CarBase()
{
}

CarBase::~CarBase()
{
}