#include <iostream>

// Обьявление namespace для написания функций без STD::
using namespace std;

void Terminal()// Функция игры терминал 
{
	int number_player;// Число игрока
	int random_terminal = 1 + rand()%100;// Число терминала

	while (true)// Бесконечный цикл 
	{

		int lie_terminal = 1 + rand()%100;// Число лжи терминала
		// Вводные данные для игрока
		cout << "-----------------------------------------------------------------------\n";
		cout << "You have connected to the terminal of the company 'Bridges of Reality'.\n";
		cout << "-----------------------------------------------------------------------\n";
		cout << "Enter a number to hack the terminal (from 1 to 100)\n";
		cin >> number_player;// Ввод игрока

		//Проверка на соответсвие чисел
		if (number_player == random_terminal)
		{

			cout << "Number of terminals:\t" << random_terminal << "\n";
			cout << "User's number:\t" << number_player << "\n";

			cout << "\n100101110101111010100101\n110101001011001011101011\n100101110101111010100101\n\n";

			cout << "The terminal has been hacked\n";

			break;// Закрытие цикла при соответсвии чисел
		}
		else 
		{
			if (lie_terminal <= 30)// Проверка на лож терминала
			{
				if (number_player < random_terminal)// Проверка на то больше ли число или меньше чем у термианал
				{
					cout << "Incorrect data.\nBlocking\n";
					cout << "----------------------------------------------------------\n";
					cout << "Your number is higher than the one verified by the program\n";
					cout << "----------------------------------------------------------\n";
				}
				else
				{
					cout << "Incorrect data.\nBlocking\n";
					cout << "--------------------------------------------------------\n";
					cout << "Your number is less than the one verified by the program\n";
					cout << "--------------------------------------------------------\n";
				}
			}
			else//
			{
				if (number_player < random_terminal)// Проверка на то больше ли число или меньше чем у термианал
				{
					cout << "Incorrect data.\nBlocking\n";
					cout << "--------------------------------------------------------\n";
					cout << "Your number is less than the one verified by the program\n";
					cout << "--------------------------------------------------------\n";
				}
				else
				{
					cout << "Incorrect data.\nBlocking\n";
					cout << "----------------------------------------------------------\n";
					cout << "Your number is higher than the one verified by the program\n";
					cout << "----------------------------------------------------------\n";
				}
			}

			
				
		}
	}
}

int main()
{
	srand(time(0));
	Terminal();// Вызов функции игры
}
