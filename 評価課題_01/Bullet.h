#pragma once

class Bullet
{
public:
	Bullet();
	void Initaliza(int x, int y, int speed, int r, int isShot);
	void Updata();
	void Draw();
	int GetPosX() { return x_; };
	int GetPosY() { return y_; };
	void SetShot(int isShot);
	int GerRadius() { return r_; };

private:
	int x_;
	int y_;
	int speed_;
	int r_;
	int isShot_;

};