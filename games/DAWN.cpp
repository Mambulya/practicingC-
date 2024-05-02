#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

const int H = 50;	// количество строк
const int W = 12;	// количество столбцов

const int ts = 50;

float Ty = 0;

String TileMap[H];

bool win = false, lose = false;

class Player {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround, rig;
	Sprite sprite;
	float curFrame;

	Player(Texture& image) {
		sprite.setTexture(image);
		rect = FloatRect(0, 0, 30, 50);
		sprite.setTextureRect(IntRect(0, 0, 30, 50));

		dx = dy = 0;
		rect.left = 50;
		curFrame = 0;
		rig = true;
	}

	void update() {
		if (rect.top + Ty >= 0) {
			rect.left += dx;
			Collision(0);

			if (!onGround)
				dy = dy + 0.005;

			rect.top += dy;

			onGround = false;
			Collision(1);

			if (rect.left < 0)
				rect.left = 550;
			else if (rect.left > 550)
				rect.left = 0;

			if (!win) {
				if (dx != 0) {
					curFrame += 0.02;
					if (curFrame > 6)
						curFrame -= 6;

					if (dx > 0) {
						sprite.setTextureRect(IntRect(30 * int(curFrame), 50, 30, 50));

						rig = true;
					}
					if (dx < 0) {
						sprite.setTextureRect(IntRect(30 * int(curFrame) + 30, 50, -30, 50));

						rig = false;
					}
				}
				else if (dx == 0) {
					curFrame += 0.002;
					if (curFrame > 4)
						curFrame -= 4;

					if (rig)
						sprite.setTextureRect(IntRect(30 * int(curFrame), 0, 30, 50));
					else
						sprite.setTextureRect(IntRect(30 * int(curFrame) + 30, 0, -30, 50));
				}
			}
			else if (win) {
				if (dy < 0) {
					if (curFrame == 0)
						curFrame = 1;

					if (rect.top < 2400 - ts)
						curFrame = 2;
				}
				if (dy > 0) {
					curFrame = 3;

					if (rect.top > 2400 - ts)
						curFrame = 0;
				}

				switch (int(curFrame))
				{
				case 0:
					sprite.setTextureRect(IntRect(0, 0, 30, 50));
					break;
				case 1:
					sprite.setTextureRect(IntRect(30, 100, 30, 50));
					break;
				case 2:
					sprite.setTextureRect(IntRect(60, 100, 30, 50));
					break;
				case 3:
					sprite.setTextureRect(IntRect(0, 100, 30, 50));
					break;
				}
			}
		}
		else {
			if (rig)
				sprite.setTextureRect(IntRect(90, 100, 30, 50));
			else
				sprite.setTextureRect(IntRect(90 + 30, 100, -30, 50));

			lose = true;
		}

		sprite.setPosition(rect.left - ts, rect.top + Ty);

		dx = 0;
	}

	void Collision(float dir) {
		for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
			for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++) {
				if (TileMap[i][j] == 'A' || TileMap[i][j] == 'B') {
					if (dx > 0 && dir == 0)
						rect.left = j * ts - rect.width;
					if (dx < 0 && dir == 0)
						rect.left = j * ts + ts;
					if (dy > 0 && dir == 1) {
						if (!win) {
							rect.top = i * ts - rect.height;
							dy = 0;
							onGround = true;
						}
						if (TileMap[i][j] == 'B') {
							if (curFrame != 0 && !win)
								curFrame = 0;

							win = true;

							dy = -1;
						}
					}
				}
			}
	}
};

int k = 0;

class RandMap {
public:
	int a[10];

	RandMap() {
		srand(time(0));

		for (int i = 0; i < 10; i++)
			a[i] = 0;

		for (int i = 0; i < 10; i++)
		{
			int tmp = rand() % 10;
			while (a[tmp] != 0)
				tmp = rand() % 10;
			a[tmp] = i + 1;
		}

		k = 0;
	}
};

int main()
{
	RenderWindow window(VideoMode(500, 700), "Game");

	// схема кирпичей
	for (int i = 0; i < H - 1; i++)
		TileMap[i] = "AAAAAAAAAAAA";
	TileMap[H - 1] = "BBBBBBBBBBBB";

	// загружаем блоки
	Texture t;
	t.loadFromFile("C:\\Users\\KUU\\source\\repos\\TicTacToe\\TicTacToe\\paint\\block.png");
	Sprite plat(t);

	// где делать проход вниз на каждом уровне
	int rd[H];
	for (int j = 0; j < 5; j++)
		for (int i = 0; i < 10; i++) {
			RandMap rm;

			rd[i + j * 10] = rm.a[i];
		}

	for (int i = 0; i < H; i++) {
		if (rd[i] > 9)
			rd[i] = 9;
	}

	for (int i = 0; i < H; i++) {
		if (i == 0 || (i % 2 == 0))
			for (int j = 0; j < W; j++)
				TileMap[i][j] = ' ';
		if (i % 2 == 1 && TileMap[i][rd[i]] != 'B') {
			TileMap[i][rd[i]] = ' ';
			TileMap[i][rd[i] + 1] = ' ';
		}
	}

	// создаем структуру игнорка
	Texture p;
	p.loadFromFile("C:\\Users\\KUU\\source\\repos\\TicTacToe\\TicTacToe\\paint\\player.png");
	Player player(p);

	// загружаем надпись победы
	Texture yw;
	yw.loadFromFile("C:\\Users\\KUU\\source\\repos\\TicTacToe\\TicTacToe\\paint\\youwin.png");
	Sprite youwin(yw);
	youwin.setPosition(130, 250);

	// загружаем надпись поражения
	Texture yl;
	yl.loadFromFile("C:\\Users\\KUU\\source\\repos\\TicTacToe\\TicTacToe\\paint\\youlose.png");
	Sprite youlose(yl);
	youlose.setPosition(130, 250);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (!win) {
			if (Keyboard::isKeyPressed(Keyboard::Right))
				player.dx = 0.4;
			if (Keyboard::isKeyPressed(Keyboard::Left))
				player.dx = -0.4;
		}

		Vector2f pl = plat.getPosition();

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (TileMap[i][j] == 'B')
					if (pl.y > 650 && player.rect.top > 350 && player.rect.top + Ty >= 0)
						Ty -= 0.009;		// hard level
						//Ty -= 0.008;	// medium level

		if (win)
			window.setFramerateLimit(180);

		player.update();
		window.clear(Color(141, 176, 252));	// цвет фона

		// отрисовывем кирпичи
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'A')
					plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (TileMap[i][j] == 'B')
					plat.setTextureRect(IntRect(ts, 0, ts, ts));
				if (TileMap[i][j] == ' ')
					continue;

				plat.setPosition(j * ts - ts, i * ts + Ty);
				window.draw(plat);
			}

		window.draw(player.sprite);
		if (win)
			window.draw(youwin);
		if (lose)
			window.draw(youlose);
		window.display();
	}

	return 0;
}
