#include"planning_base.h"

//**点**//

Point:: Point(const double& p_x, const double& p_y, const double& p_theta , const double& p_R): x(p_x),y(p_y),thetaP(p_theta),Rp(p_R)
{

}

void Point::showPoint()//绘制点
{
	setfillcolor(BLACK);
	solidcircle(x, y, r);
}

void Point::pointMove(const double& speed_x, const double& speed_y)//点的移动
{
	x += speed_x;
	y += speed_y;
}

void Point:: pointTurn(const Point& center, const double& turn_speed)//点的旋转（p绕着cneter旋转））
{
	thetaP += turn_speed;//turn_speed>0 顺时针
	x = Rp * cos(thetaP) + center.x;
	y = -Rp * sin(thetaP) + center.y;
}

double Point::distanceTo(const Point& p) const
{
	return hypot(x - p.x, y - p.y);//平方根
}

//********全局函数*******//

void delay(const int& time)//延时函数
{
	clock_t now = clock();
	while (clock() - now < time)
	{

	}
}