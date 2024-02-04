#include "Player.h"
#include "Novice.h"
Player::Player()
{
	x_ = 300;
	y_ = 300;
	speedX_ = 5;
	speedY_ = 5;
	r_ = 50;
	isAlive_ = 1;
}

void Player::Initaliza(int x, int y, int speedX, int speedY, int r, int isAlive)
{
	x_ = x;
	y_ = y;
	speedX_ = speedX;
	speedY_ = speedY;
	r_ = r;
	isAlive_ = isAlive;
}

void Player::Updata(const char* preKeys, const char* keys)
{
	if (keys[DIK_A] && preKeys[DIK_A])
	{
		x_ -= speedX_;
	}
	if (keys[DIK_D] && preKeys[DIK_D])
	{
		x_ += speedX_;
	}
	if (keys[DIK_W] && preKeys[DIK_W])
	{
		y_ -= speedY_;
	}
	if (keys[DIK_S] && preKeys[DIK_S])
	{
		y_ += speedY_;
	}
}

void Player::Draw()
{
	if (isAlive_ == 1)
	{
		Novice::DrawBox(x_ - r_, y_ - r_, r_ * 2, r_ * 2, 0.0f, WHITE, kFillModeSolid);
	}
	
}

void Player::SetAlive(int isAlive)
{
	isAlive_ = isAlive;
}
