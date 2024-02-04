#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
{
	x_ = 100;
	y_ = 200;
	speed_ = 5;
	r_ = 20;
	isShot_ = 0;
}

void Bullet::Initaliza(int x, int y, int speed, int r, int isShot)
{
	x_ = x;
	y_ = y;
	speed_ = speed;
	r_ = r;
	isShot_ = isShot;
}

void Bullet::Updata()
{

	y_ -= speed_;
	if (y_ < 0 - r_)
	{
		isShot_ = 0;
	}
}

void Bullet::Draw()
{
	Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, BLACK, kFillModeSolid);
}

void Bullet::SetShot(int isShot)
{
	isShot_ = isShot;
}


