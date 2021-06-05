#include "HumanPlayer.h"

Schiff *HumanPlayer::getAttackerSchiff()
{
    int attackschiff = 0;
    do {
        cout << "Deine ";
        flotte->ausSchreiben();
        cout << "\nWahle ein Schiff, einen Feind anzugreifen!" << endl;
        cout << ">"; cin >> attackschiff; cout << endl; system("cls");
        string s; getline(cin, s);
        if (attackschiff > flotte->nummer() || attackschiff < 1) {
            cout << "Invalid number. Try again!\n" << endl;
        }
    } while (attackschiff > flotte->nummer() || attackschiff < 1);

    return flotte->bekommenSchiff(attackschiff);
}

Schiff *HumanPlayer::getDefenderSchiff()
{
    int defendschiff = 0;
    do {
        cout << "Enemy ";
        enemyFlotte->ausSchreiben();
        cout << "\nWahle ein Schiff, einen Feind zu schutzen!" << endl;
        cout << ">"; cin >> defendschiff; cout << endl; system("cls");
        string s; getline(cin, s);
        if (defendschiff > enemyFlotte->nummer() || defendschiff < 1) {
            cout << "Invalid number. Try again!\n" << endl;
        }
    } while (defendschiff > enemyFlotte->nummer() || defendschiff < 1);

    return enemyFlotte->bekommenSchiff(defendschiff);
}
