#include "car.h"

//**������**//
void CarBase:: initCar(const double& pos_x, const double& pos_y, const double& heading, const double& width, const double& length)
{
	car_width = width;
	car_length = length;
	heading_theta = heading;

	R0 = hypot(car_width / 2.0, car_length / 2.0);//��б��
	theta0 = atan(car_length / car_width);//

	pmid = make_unique<Point>(pos_x, pos_y);//���ĵ�
	plf = make_unique<Point>(pmid->x - car_width / 2.0, pmid->y - car_length / 2.0, PI - theta0, R0);
	prf = make_unique<Point>(pmid->x + car_width / 2.0, pmid->y - car_length / 2.0, theta0, R0);
	plr = make_unique<Point>(pmid->x - car_width / 2.0, pmid->y + car_length / 2.0, PI + theta0, R0);
	prr = make_unique<Point>(pmid->x + car_width / 2.0, pmid->y + car_length / 2.0, -theta0, R0);

	updatePmidf();
	updatePmidr();
}

void CarBase::updatePmidf()//����ǰ������xyֵ
{
	double x = (plf->x + prf->x) / 2.0;
	double y = (plf->y + prf->y) / 2.0;
	if (pmidf)
	{
		pmidf->x = x;
		pmidf->y = y;
	}
	else
	{
		pmidf = make_unique<Point>(x, y);
	}
}

void CarBase::updatePmidr()//�������ĵ�
{
	double x = (plr->x + prr->x) / 2.0;
	double y = (plr->y + prr->y) / 2.0;
	if (pmidr)
	{
		pmidr->x = x;
		pmidr->y = y;
	}
	else
	{
		pmidr = make_unique<Point>(x, y);
	}
}

void CarBase::updatePmid()//���¼������ĵ�
{
	double x = (plf->x + prr->x) / 2.0;
	double y = (plf->y + prr->y) / 2.0;
	if (pmid)
	{
		pmid->x = x;
		pmid->y = y;
	}
	else
	{
		pmid = make_unique<Point>(x, y);
	}
}

void CarBase::showCar(const COLORREF& color)//���Ƴ�������
{
	setlinestyle(PS_SOLID, 4);	// �����ߵ���ʽ
	setlinecolor(color);
	line(plf->x, plf->y, prf->x, prf->y);
	line(prf->x, prf->y, prr->x, prr->y);
	line(prr->x, prr->y, plr->x, plr->y);
	line(plr->x, plr->y, plf->x, plf->y);
}

void CarBase::showCircle()//���ƹ켣��
{
	setlinestyle(PS_DOT, 2); /* .......  */
	setlinecolor(MAGENTA);
	circle(p_center->x, p_center->y, Rof);//����Բ
	circle(p_center->x, p_center->y, Ror);
	circle(p_center->x, p_center->y, Rif);
	circle(p_center->x, p_center->y, Rir);
}

void CarBase::coutInfo()//��ӡ��Ϣ
{
	cout << "pmidr->x= " << pmidr->x << " pmidr->y= " << pmidr->y << " pmidr->Rp= " << pmidr->Rp << " pmidr->thetaP= " << pmidr->thetaP << endl;
	cout << "pmidf->x= " << pmidf->x << " pmidf->y= " << pmidf->y << " pmidf->Rp= " << pmidf->Rp << " pmidf->thetaP= " << pmidf->thetaP << endl;
	cout << "pmid->x= " << pmid->x << " pmid->y= " << pmid->y << " pmid->Rp= " << pmid->Rp << " pmid->thetaP= " << pmid->thetaP << endl;
	cout << "plf->x= " << plf->x << " plf->y= " << plf->y << " plf->Rp= " << plf->Rp << " plf->thetaP= " << plf->thetaP << endl;
	cout << "prf->x= " << prf->x << " prf->y= " << prf->y << " prf->Rp= " << prf->Rp << " prf->thetaP= " << prf->thetaP << endl;
	cout << "plr->x= " << plr->x << " plr->y= " << plr->y << " plr->Rp= " << plr->Rp << " plr->thetaP= " << plr->thetaP << endl;
	cout << "prr->x= " << prr->x << " prr->y= " << prr->y << " prr->Rp= " << prr->Rp << " prr->thetaP= " << prr->thetaP << endl;
	cout << "speed = " << speed << ", a = " << a << ", delta_theta = " << delta_theta / PI << ", delta_theta_rot = " << delta_theta_rot / PI << ", heading_theta = " << heading_theta / PI << endl;
}

void CarBase::moveStraightStep()//��ֱ֡��
{
	plf->pointMove(speed_x, speed_y);
	prf->pointMove(speed_x, speed_y);
	plr->pointMove(speed_x, speed_y);
	prr->pointMove(speed_x, speed_y);
	pmidf->pointMove(speed_x, speed_y);
	pmidr->pointMove(speed_x, speed_y);
	pmid->pointMove(speed_x, speed_y);
}

void CarBase::carTurnStep()//��֡ת��
{
	pmidr->pointTurn(*p_center, delta_theta);
	plf->pointTurn(*p_center, delta_theta);
	prf->pointTurn(*p_center, delta_theta);
	plr->pointTurn(*p_center, delta_theta);
	prr->pointTurn(*p_center, delta_theta);
	heading_theta += delta_theta;
}