#pragma once

class Enemy
{
public:
	Enemy();
	void Initaliza(int x, int y, int speedX, int r, int isAlive);
	void Update();
	void Draw();
	int GetPosX() { return x_; };
	int GetPosY() { return y_; };
	void SetAlive(int isAlive);
	int GerRadius() { return r_; };

private:
	int x_;
	int y_;
	int speedX_;
	int r_;
	int isAlive_;
	int timer;
};