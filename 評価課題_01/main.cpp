#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

const char kWindowTitle[] = "GC1B_06_シミズ_タクミ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//int isShot = 0;
	Enemy* enemy = new Enemy();
	Player* player = new Player();
	Bullet* bullet = new Bullet();
	int enemyIsAlive = 1;
	int playerIsAlive = 1;
	int playerBulletIsShot = 0;
	int posX = 300;
	int posY = 300;
	int bulletPosX = posX;
	int bulletPosY = posY;

	enemy->Initaliza(100, 100, 5, 30, enemyIsAlive);
	player->Initaliza(posX, posY, 5, 5, 50, playerIsAlive);
	bullet->Initaliza(bulletPosX, bulletPosY, 5,50, playerBulletIsShot);
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		///
		/// ↓更新処理ここから
		///
		enemy->Update();
		player->Updata(preKeys, keys);
		if (keys[DIK_SPACE]&&preKeys[DIK_SPACE])
		{
			playerBulletIsShot = 1;
			posX=bulletPosX;
			posY=bulletPosY;

		}
		if (playerBulletIsShot == 1)
		{
			bullet->Updata();
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		enemy->Draw();
		player->Draw();
		bullet->Draw();

		
		Novice::ScreenPrintf(0, 0, "posX:%d  posY:%d", posX, posY);
		Novice::ScreenPrintf(0, 50, "bulletPosX:%d  bulletPosY:%d", bulletPosX, bulletPosY);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	
	}

	delete enemy;
	delete player;
	delete bullet;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
