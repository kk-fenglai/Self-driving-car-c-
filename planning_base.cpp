#include"planning_base.h"

//**��**//

Point:: Point(const double& p_x, const double& p_y, const double& p_theta , const double& p_R): x(p_x),y(p_y),thetaP(p_theta),Rp(p_R)
{

}

void Point::showPoint()//���Ƶ�
{
	setfillcolor(BLACK);
	solidcircle(x, y, r);
}

void Point::pointMove(const double& speed_x, const double& speed_y)//����ƶ�
{
	x += speed_x;
	y += speed_y;
}

void Point:: pointTurn(const Point& center, const double& turn_speed)//�����ת��p����cneter��ת����
{
	thetaP += turn_speed;//turn_speed>0 ˳ʱ��
	x = Rp * cos(thetaP) + center.x;
	y = -Rp * sin(thetaP) + center.y;
}

double Point::distanceTo(const Point& p) const
{
	return hypot(x - p.x, y - p.y);//ƽ����
}

//********ȫ�ֺ���*******//

void delay(const int& time)//��ʱ����
{
	clock_t now = clock();
	while (clock() - now < time)
	{

	}
}