#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

// свободные ячейки
bool svob[9] = { false };

class Stav {
public:
	Sprite sprite[9];	// ячейки поля с крестиками или ноликами
	bool tik[9];		// отображение проставленных крестиком или ноликом полей

	Stav(Texture& image) {
		for (int i = 0; i < 9; i++) {
			// загружаем картинки 
			sprite[i].setTexture(image);
			tik[i] = false;	// в начале игры они не видны
		}
		for (int i = 0; i < 3; i++)		// пропишем для каждой ячейки позицию на поле
			for (int j = 0; j < 3; j++)
				sprite[i * 3 + j].setPosition(200 * j, 200 * i);
	}

	void update(int& vid) {
		// отрисовывем x или o
		for (int i = 0; i < 9; i++)
			sprite[i].setTextureRect(IntRect(200 * (vid - 1), 0, 200, 200));
	}
};

int BotStav() {
	// функция ищет какая ячейка свободна
	int res = 0;

	bool verno = false;	// нашли какой-нибудь свободный элемент или нет
	while (!verno) {
		res = rand() % 9;

		if (!svob[res])
			verno = true;
		else
			verno = false;
	}

	return res;
}

int main() {
	srand(time(0));
	RenderWindow window(VideoMode(600, 600), "Tic tac toe!");

	// загружвем сетку для фона
	Texture f;
	f.loadFromFile("C:/Users/KUU/source/repos/TicTacToe/TicTacToe/paint/fon.png");
	Sprite fon(f);

	// загружаем картинки крестиков и ноликов
	Texture c;
	c.loadFromFile("C:/Users/KUU/source/repos/TicTacToe/TicTacToe/paint/crnol1.png");
	Sprite vibor[2];
	for (int i = 0; i < 2; i++) {
		vibor[i].setTexture(c);
		vibor[i].setPosition(50 + 300 * i, 180);
	}
	int vib = 0;	// состояние выбора
	Stav player(c), bot(c);	// создаем игрока и бота, с которым будем играть

	int sv = 0;		// сколько заполненых ячеек

	// загрузим выигрошную линию
	Texture l;
	l.loadFromFile("C:/Users/KUU/source/repos/TicTacToe/TicTacToe/paint/line.png");
	Sprite line(l);
	bool win = false;
	bool hotbot = false;	// может ли бот сделать шаг
	bool dumbot = false;	// состояние, когда боту не нужно продумывать ход, а просто достаточно выбрать свободную ячейку

	// начало игры
	while (window.isOpen())
	{
		// двухмерный вектор для работы с экранными координатами
		Vector2i pos = Mouse::getPosition(window);

		Event event;
		while (window.pollEvent(event))
		{	
			// если игру закрыли
			if (event.type == Event::Closed)
				window.close();

			// если происходит сейчас управление мышью
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left) {
					if (vib == 0) {	// если выбор ещё не сделали
						for (int i = 0; i < 2; i++)
							if (vibor[i].getGlobalBounds().contains(pos.x, pos.y))	// если нажимаем на X или О
								vib = i + 1;	// vib = 1 -> X; vib = 2 -> O
					}
					else    // если уже выбрали кем будем играть
						for (int i = 0; i < 9; i++)
							// если нажали на крестик или нолик, отрисовываем рамочку вокруг
							if (player.sprite[i].getGlobalBounds().contains(pos.x, pos.y) && !svob[i]) {	
								player.tik[i] = true;	// отрисовали картинку
								svob[i] = true;			// ячейка уже не свободна
								sv++;					

								hotbot = true;
							}
				}
		}

		// сделали выбор кем будем играть
		for (int i = 0; i < 2; i++)
			if (vibor[i].getGlobalBounds().contains(pos.x, pos.y))	// если курсор находится на X или на О, то обводим
				vibor[i].setTextureRect(IntRect(200 * i, 200, 200, 200));
			else
				vibor[i].setTextureRect(IntRect(200 * i, 0, 200, 200));	// если не находится, не обводим
		
		// отслеживаем выигрыш
		bool winplay[8][2];		// все исходы игры 1 игрока и бота
		for (int i = 0; i < 8; i++) {
			if (i < 3) {	// ХХХ или ООО по горизонтали
				winplay[i][0] = player.tik[3 * i] && player.tik[1 + 3 * i] && player.tik[2 + 3 * i];
				winplay[i][1] = bot.tik[3 * i] && bot.tik[1 + 3 * i] && bot.tik[2 + 3 * i];
			}
			else if (i >= 3 && i < 6) {	// выйграли по вертикали
				winplay[i][0] = player.tik[i - 3] && player.tik[i] && player.tik[i + 3];
				winplay[i][1] = bot.tik[i - 3] && bot.tik[i] && bot.tik[i + 3];
			}
			else if (i >= 6) {	// выиграли по диагонали
				winplay[i][0] = player.tik[2 * (i - 6)] && player.tik[4] && player.tik[8 - 2 * (i - 6)];
				winplay[i][1] = bot.tik[2 * (i - 6)] && bot.tik[4] && bot.tik[8 - 2 * (i - 6)];
			}

			for (int j = 0; j < 2; j++)
				if (winplay[i][j]) {	// если кто-то выиграл
					win = true;
					if (i < 3) {
						// прорисовывем линию по горизонтаои
						line.setTextureRect(IntRect(0, 0, 600, 10));
						int ly = 95 + 200 * i;	// длина линии
						line.setPosition(0, ly);
					}// прорисовывем линию по вертикали
					else if (i < 6) {
						line.setTextureRect(IntRect(0, 0, 600, 10));
						line.setRotation(90);
						int lx = 105 + 200 * (i - 3);
						line.setPosition(lx, 0);
					}
					else if (i == 6)	// прорисовывем линию по диагонали
						line.setTextureRect(IntRect(0, 10, 600, 600));
					else if (i == 7)	// прорисовывем линию по диагонали
						line.setTextureRect(IntRect(600, 10, -600, 600));
				}
		}

		// если бот может играть дальше и еще не выигрыш и есть свободные ячейки
		if (hotbot && !win && sv < 9) {
			sv++;

			int botstav = 0;

			if (!dumbot) {
				// на первом ходу просто ставим рандомный ход
				botstav = BotStav();
				dumbot = true;
			}
			else {
				// учим бота играть
				bool cdat = true;

				for (int i = 0; i < 3; i++) {
					// если 2 из 3 ячеек по вертикали заняты, поставим в последнюю для выиграша
					if (player.tik[i] && player.tik[3 + i] && !svob[6 + i]) {
						botstav = 6 + i;
						cdat = false;
					}
					if (player.tik[6 + i] && player.tik[3 + i] && !svob[i]) {
						botstav = i;
						cdat = false;
					} // то же самое по горизонтали
					if (player.tik[3 * i] && player.tik[1 + 3 * i] && !svob[2 + 3 * i]) {
						botstav = 2 + 3 * i;
						cdat = false;
					}
					if (player.tik[2 + 3 * i] && player.tik[1 + 3 * i] && !svob[3 * i]) {
						botstav = 3 * i;
						cdat = false;
					}
				} // по диагонали
				if (player.tik[0] && player.tik[4] && !svob[8]) {
					botstav = 8;
					cdat = false;
				}
				if (player.tik[8] && player.tik[4] && !svob[0]) {
					botstav = 0;
					cdat = false;
				}
				if (player.tik[2] && player.tik[4] && !svob[6]) {
					botstav = 6;
					cdat = false;
				}
				if (player.tik[6] && player.tik[4] && !svob[2]) {
					botstav = 2;
					cdat = false;
				}
				if (player.tik[2] && player.tik[6] && !svob[4]) {
					botstav = 4;
					cdat = false;
				}

				if (cdat)
					botstav = BotStav();
			}

			bot.tik[botstav] = true;
			svob[botstav] = true;

			hotbot = false;
		}

		// обновляем картинку всоответствии хода игрока
		player.update(vib); 

		// бот будет играть противополодной фигурой
		int biv = vib + 1;	
		if (biv == 3)
			biv = 1;

		// обновляем картинку всоответсвии хода бота
		bot.update(biv);

		window.clear(Color::White);
		if (vib == 0)	// если выбор не сделали
			for (int i = 0; i < 2; i++)
				window.draw(vibor[i]);
		else {	// если выбрали кем будем играть
			window.draw(fon);
			for (int i = 0; i < 9; i++) {
				if (player.tik[i])
					window.draw(player.sprite[i]);	// игрок будет рисовать тем, что выбрал

				if (bot.tik[i])
					window.draw(bot.sprite[i]);
			}
		}
		if (win)
			window.draw(line);
		window.display();
	}

	return 0;
}
