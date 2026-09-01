#include <iostream>

int main()
{
    srand(time(0));// Аргумент для перерандома

    // Данные атакующего
    int strength = 100;
    int weapon_damage = 50;
    int сrit_chance = 15;
    int crit_multiplier = 2;

    // Данные защищяющегося 
    int barrier = 30;
    int resistance = 20;
    int dodge = 10;
    int hp = 500;

    // Вспомогательные переменные
    int final_damage;
    int final_resistance;
    int crete_random = 1 + rand() % 100;
    int dodge_random = 1 + rand() % 100;

    //Логика данных и расчёты
    final_damage = strength + weapon_damage;

    if (crete_random <= сrit_chance) 
    {
        final_damage *= crit_multiplier;
    }

    final_resistance = ((final_damage/100)* resistance);
    final_damage -= barrier + final_resistance;

    if (dodge_random <= dodge)
    {
        final_damage = 0;
    }

    // Финальный расчёт и вывод
    hp -= final_damage;
    std::cout << hp;
}
