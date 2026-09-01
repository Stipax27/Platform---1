#include <iostream>

// Обьявление namespace для написания функций без STD::
using namespace std;
// Структуры Юнитов и Королей
struct Unit
{
	string name;
	int dmg;
};

struct King
{
	string name;
	int Hp;
};

// Массив Юнитов и Переменные королей игрока и врага
Unit pers[3];
King Player;
King Enemy;

void RPS() {

	int choice;// Переменная для выбора игрока
	int choice_enemy = rand()%3;// Рандом для выбора врага

	// Заполнение данных
	Player.name;
	Player.Hp = 200;

	Enemy.name = "Trevor";
	Enemy.Hp = 200;

	pers[0].name = "Swordsman";
	pers[0].dmg = 20;

	pers[1].name = "Archer   ";
	pers[1].dmg = 20;

	pers[2].name = "Horseman ";
	pers[2].dmg = 20;

	// Начало игры
	cout << "Enter your king's name\n";
	cin >> Player.name;
	

	while (true)// Бесконечный цикл игры
	{
		cout << "------------------------------------------------------------------------------\n";
		cout << "Choose the warrior you will play as (1 - Swordsman, 2 - Archer, 3 - Horseman)\n Where the archer is stronger than the swordsman,\n the horseman is stronger than the archer,\n and the swordsman is stronger than the horseman.\n The buff gives the warrior 2x damage boost.\n";
		cout << "------------------------------------------------------------------------------\n";

		for (int i = 0; i < 3; i++)//вывод данных всех воинов
		{
			cout << i + 1 << "\t" << pers[i].name << "   Damage:  " << pers[i].dmg << "\n";
		}
		// Вывод данных о королях
		cout << "\nHealth " << Player.name << ": " << Player.Hp << "\n";
		cout << "Health " << Enemy.name << ": " << Enemy.Hp << "\n";
		
		cout << "Choose your warrior\n";
		cin >> choice;
		
		//Проверка на победу ничью или поражения
		if (choice == 1)
		{
			if (choice_enemy == 0) {

				cout << pers[choice - 1].name <<" VS "<< pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg;
				Enemy.Hp -= pers[choice - 1].dmg;
			}
			else if (choice_enemy == 1)
			{
				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg * 2;
				Enemy.Hp -= pers[choice - 1].dmg;
			}
			else
			{
				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg;
				Enemy.Hp -= pers[choice - 1].dmg * 2;
			}
		}
		else if (choice == 2)
		{
			if (choice_enemy == 0) {

				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg;
				Enemy.Hp -= pers[choice - 1].dmg * 2;
			}
			else if (choice_enemy == 1)
			{
				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg;
				Enemy.Hp -= pers[choice - 1].dmg;
			}
			else
			{
				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg * 2;
				Enemy.Hp -= pers[choice - 1].dmg;
			}
		}
		else
		{
			if (choice_enemy == 0) {

				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg * 2;
				Enemy.Hp -= pers[choice - 1].dmg;
			}
			else if (choice_enemy == 1)
			{
				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg;
				Enemy.Hp -= pers[choice - 1].dmg * 2;
			}
			else
			{
				cout << pers[choice - 1].name << " VS " << pers[choice_enemy].name << "\n";
				Player.Hp -= pers[choice_enemy].dmg;
				Enemy.Hp -= pers[choice - 1].dmg;
			}
		}
		// Проверка на победу или поражение короля
		if (Enemy.Hp <= 0 && Player.Hp <= 0) 
		{
			cout << "Defeat of your King and defeat enemy King\n";
			break;
		}

		if (Enemy.Hp <= 0)
		{
			cout << "Hooray, your king has won!!!\n";
			break;
		}

		if (Player.Hp <= 0)
		{
			cout << "Defeat of your King (((\n";
			break;
		}

	}
	
}

int main()
{
	srand(time(0));
	RPS();// Вызов функции игры
}
