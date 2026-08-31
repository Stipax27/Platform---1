#include <iostream>

int pass;
int wallet = 200;
int payoff;
int honesty;
std::string answer;

void ResultBribe() {

	
	std::cout << "(Yes/No)\n";
	std::cin >> answer;

	if (answer == "Yes")
	{

		std::cout << "Give me the money\n";
		if (wallet >= payoff)
		{
			std::cout << "Okay come on in\n";
			wallet -= payoff;
			std::cout << "Player: I still have\n";
			std::cout << wallet;

		}
		else
		{

			std::cout << "Player: Damn , I don't have enough money\n";
			std::cout << "Yeah yeah get lost\n";

		}
	}
	else if (answer == "No")
	{
		std::cout << "If you don't want to give money, then leave.\n";
	}
	else
	{
		std::cout << "What are you talking about.\n";
	}
}

int main()
{
	srand(time(0));
	pass = rand() % 2;
	payoff = 50 + rand() % 200;
	honesty = 1 + rand() % 100;

	std::cout << "My money: " << wallet << "\n";
	std::cout << "Stalker, to get into the zone, provide a pass.\n";

	if (pass == 0) {

		std::cout << "I have a pass.\n";
		std::cout << "You'r welcome!";
	}
	else 
	{
		std::cout << "I don't have a pass.\n";

		if (honesty <= 30)
		{
			std::cout << "You can give me some money, and we'll settle the matter.\n";
			ResultBribe();
		}
		else if (honesty >= 30 && honesty <=69) 
		{
			std::cout << "I don't even know if he can give a bribe\n";
			ResultBribe();
		}
		else
		{
			std::cout << "I don't even know if he can give a bribe\n";
			std::cout << "(Yes/No)\n";
			std::cin >> answer;

			if (answer == "Yes")
			{
				std::cout << "Leave right now, or I'll get a weapon.\n";
			}
			else if (answer == "No")
			{
				std::cout << "If you don't want to give money, then leave.\n";
			}
			else
			{
				std::cout << "What are you talking about.\n";
			}
		}
	}
}
