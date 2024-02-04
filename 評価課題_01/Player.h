#pragma once

class Player
{
public:
	Player();
	void Initaliza(int x, int y, int speedX, int speedY, int r, int isAlive);
	void Updata(const char* preKeys,const char* keys);
	void Draw();
	int GetPosX() { return x_; };
	int GetPosY() { return y_; };
	void SetAlive(int isAlive);
	int GerRadius() { return r_; };
private:
	int x_;
	int y_;
	int speedX_;
	int speedY_;
	int r_;
	int isAlive_;
};