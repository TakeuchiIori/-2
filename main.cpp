#include <Novice.h>

const char kWindowTitle[] = "LC1B_16_タケウチイオリ_タイトル";

struct Vector2 {
	float x;
	float y;
};

struct Square {
	Vector2 pos;
	Vector2 size;
	Vector2 velocity;
	Vector2 acceleration;
};

struct RectanglePos {

	Vector2 TopLeft;
	Vector2 TopRight;
	Vector2 BottomLeft;
	Vector2 BottomRight;

};


Square square = {
	{0.0f,300.0f},
	{48.0f,48.0f},
	{0.0f,0.0f,},
	{0.8f,-0.5f,},
};
//struct Ball {
//	Vector2 position;
//	Vector2 velocity;
//	Vector2 acceleration;
//	float radius;
//	unsigned int color;
//};




//624.0f

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 704);


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	//変数

	int Map1[22][40] = {

		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,},
		{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{3,3,3,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

	};

	RectanglePos Temp = {

	{ -32.0f, -32.0f, },
	{ +32.0f, -32.0f, },
	{ -32.0f, +32.0f, },
	{ +32.0f, +32.0f, },

	};



	RectanglePos HitBox = {

		{square.pos.x - 32.0f,square.pos.y - 32.0f, },
		{square.pos.x + 32.0f,square.pos.y - 32.0f, },
		{square.pos.x - 32.0f,square.pos.y + 32.0f, },
		{square.pos.x + 32.0f,square.pos.y + 32.0f, },

	};


	RectanglePos oldHitBox = HitBox;


	float  X = 32;
	float  Y = 32;

	float Size = 32;


	int Tile1 = Novice::LoadTexture("./images/Tile.png");

	float SpeedX = 10.0f;
	float SpeedY = 10.0f;

	//float oldSpeedX = 0;
	//float oldSpeedY = 0;

	//float oldPosX = 0;
	//float oldPosY = 0;

	square.velocity.y *= -1.0f;
	square.acceleration.y *= -1.0f;

	float isSquare = 0;

	int addressX = (int)square.pos.x / 32;
	int addressY = (int)square.pos.y / 32;

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

		square.acceleration.y = -0.5f;



		if (keys[DIK_SPACE]) {
			SpeedX += 0.1f;
			SpeedY += 0.1f;
		}


		if (!keys[DIK_SPACE] && preKeys[DIK_SPACE]) {

			square.velocity.y = SpeedY;
			square.velocity.x = SpeedX;

			isSquare = 1;
		}

		if (!keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		

			SpeedX = 10.0f;
			SpeedY = 10.0f;

			

		}




		if (isSquare == 1) {

			square.pos.y += square.velocity.y;
			square.velocity.y += square.acceleration.y;

			square.pos.x += square.velocity.x;
			
		}

		/*if (square.pos.y < 48) {
			square.pos.y = 48;
		}*/

		float ScreenY = square.pos.y;
		ScreenY += -924;
		ScreenY *= -1;

		if (ScreenY > 914) {
			ScreenY= 914;
		}

		for (int y = 0; y < 22; y++) {
			for (int x = 0; x < 40; x++) {
				addressX = ((int)square.pos.x + 48) / 32;
				addressY = ((int)ScreenY + 48) / 32;
				if (Map1[addressY][addressX] == 1 ) {
					
				
				}

				/*if (Map1[addressY][addressX] == 0 ) {
					ScreenY -= oldSpeedY;
					square.pos.x -= oldSpeedX;
					
				}*/

			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 40; j++) {

				if (Map1[i][j] == 1) {
					/*Novice::DrawBox(j * X, i * Y,32, 32, 0.0f, WHITE, kFillModeSolid);*/
					Novice::DrawSprite(j * (int)X, i * (int)Y, Tile1, 1.0f, 1.0f, 0.0f, WHITE);
				}

				if (Map1[i][j] == 2) {
					Novice::DrawBox(j * (int)X, i * (int)Y, 32, 32, 0.0f, 0xFFF, kFillModeSolid);
				}

				if (Map1[i][j] == 3) {
					Novice::DrawBox(j * (int)X, i * (int)Y, 32, 32, 0.0f, RED, kFillModeSolid);
				}


			}
		}

		Novice::ScreenPrintf(10, 10, "x = %f  y = %f", SpeedX, SpeedY);
		Novice::ScreenPrintf(30, 30, "old x = %f  oldy = %f", oldSpeedX, oldSpeedY);

		Novice::DrawBox((int)square.pos.x, (int)ScreenY, (int)square.size.x, (int)square.size.y, 0.0f, WHITE, kFillModeSolid);

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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
