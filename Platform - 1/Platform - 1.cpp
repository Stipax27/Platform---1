#include <iostream>
#include <vector>

// Обьявление namespace для написания функций без STD::
using namespace std;

// Структура предметов
struct item
{
	string name;
	int price;
	int count;
	int weight;

};

// Динамический массив 
vector<item> shop;

// Данные игрока
int wallet;
int weight_player;
int pockets;

void InitShop() // Функция для заполнения данных
{
	// Заполнение массива
	shop.push_back({ "Potion" , 50 , 10 , 1 });
	shop.push_back({ "Sword" , 300 , 2 , 10 });
	shop.push_back({ "Shield" , 200 , 1 , 8 });
	shop.push_back({ "Cuirass" , 250 , 2 , 15 });
	shop.push_back({ "Booster" , 100 , 5 , 2 });

	// Заполнение данных игрока
	wallet = 600;
	weight_player = 30;
	pockets = 5;
}

void Shop() // Функция с логикой игры
{
	// Вывод данных предметов
	cout << "  " << "\t" << "Title" << "\t" << "Price" << "\t" << "Count" << "\t" << "Weight" << "\n\n";

	for (int i = 0; i < shop.size(); i++)
	{
		cout << i+1 << "\t" << shop[i].name << "\t" << shop[i].price << "\t" << shop[i].count << "\t" << shop[i].weight << "\n";
	}

	// Переменные для определения данных желаемого товара
	int choice_item;
	int choice_count;
	int choice_weight;

	while (true)// Цикл всей игры
	{
		cout << "\nTraveler, choose the item you want to buy.\n";
		cout << "-------------------\n";
		cout << "My money: " << wallet << "\n";
		cout << "My weight: " << weight_player << "\n";
		cout << "My pockets: " << pockets << "\n";
		cout << "-------------------\n";
		cin >> choice_item;

		//Проверки на выборы и данные героя
		if (choice_item >= 1 && choice_item <= (int)shop.size())
		{
			int index = choice_item - 1;
			cout << "You'r choice " << shop[index].name << "\n";
			cout << "How much do you want of the item?\n";

			cin >> choice_count;

			if (choice_count <= shop[index].count && choice_count<= pockets)
			{
				cout << "You want to take that much of the item, okay.\n";

				if (weight_player >= shop[index].weight)
				{
					cout << "It's so great that I can lift this.\n";

					if (wallet >= shop[index].price * choice_count)
					{
						cout << "Well, since you’ve made up your mind, let's get the money.\n";
						cout << "\n(yes/no)\n";
						string buy;
						cin >> buy;
						if (buy == "yes")
						{
							cout << "Take the item.\n";
							wallet -= shop[index].price * choice_count;
							weight_player -= shop[index].weight;
							pockets -= choice_count;

						}
						else
						{
							cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n";
							cout << "Hey, stop! Where are you running off to, you thief?.\n";
							cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n";
							weight_player -= shop[index].weight;
							pockets -= choice_count;
						}
					}
					else
					{
						cout << "I don't have enough money.\n";
					}
				}
				else
				{
					cout << "Oh man, I won't be able to carry all this—the item is too heavy.\n";
				}
			}
			else
			{
				cout << "I don't have that much item.\n";
			}
		}
		else
		{
			cout << "I don't have that item.\n";
		}

		
	}
	
	// Задание:Игрок хочет купить 2 зелья и меч.Хватит ли денег и места ?
	// Оптимизация : Каким должен быть список покупок, чтобы потратить максимум денег, уложившись в лимит веса ? (Классическая задача о рюкзаке).
	// Мета : Введите динамическое ценообразование.Если игрок покупает много мечей, цена на них растет(спрос рождает предложение).Если игрок продает мечи, цена падает(рынок наводнен).


}

int main()
{
	// Вызова функций
	srand(time(0));
	InitShop();
	Shop();
}
