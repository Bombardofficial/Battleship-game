
#include <iostream>

#include "Schiff.h"
#include "Jager.h"
#include "Kreuzer.h"
#include "Flotte.h"

#include <cstdlib>
#include "player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <chrono>
#include <thread>
using namespace std;



int main()
{
    cout << "                                                     ";
    
    //LADEBILDSCHIRM
    cout << "B";this_thread::sleep_for(chrono::milliseconds(50));cout << "A";this_thread::sleep_for(chrono::milliseconds(50));
    cout << "T";this_thread::sleep_for(chrono::milliseconds(50)); cout << "T"; this_thread::sleep_for(chrono::milliseconds(50)); 
    cout << "L"; this_thread::sleep_for(chrono::milliseconds(50)); cout << "E"; this_thread::sleep_for(chrono::milliseconds(50)); 
    cout << "S"; this_thread::sleep_for(chrono::milliseconds(50)); cout << "H"; this_thread::sleep_for(chrono::milliseconds(50)); 
    cout << "I"; this_thread::sleep_for(chrono::milliseconds(50)); cout << "P" << endl; this_thread::sleep_for(chrono::milliseconds(250));
    cout << endl << "                                                     ";
    cout << "Loading "; this_thread::sleep_for(chrono::milliseconds(500)); cout << "."; this_thread::sleep_for(chrono::milliseconds(300));
    cout << "."; this_thread::sleep_for(chrono::milliseconds(200)); cout << "."; this_thread::sleep_for(chrono::milliseconds(1000));
    system("cls");


    srand(time(NULL));
    int choosemod;
    do {
        cout << "MODES: \n(1)Player vs. Computer\n(2)Computer vs Computer" << endl;
        cin >> choosemod;
    } while(choosemod != 1 && choosemod != 2);
    system("cls");
    player* player1;
    player* player2;
    player* players[2];
    Flotte* flotte1 = new Flotte();
    Flotte* flotte2 = new Flotte();
    switch (choosemod) {
    case 1:
        players[0] = new HumanPlayer("Player", flotte1, flotte2);
        players[1] = new ComputerPlayer("Computer",flotte2, flotte1);
        break;
        
    case 2:
        players[0] = new ComputerPlayer("Computer_1", flotte1, flotte2);
        players[1] = new ComputerPlayer("Computer_2", flotte2, flotte1);
        break;

    default:
        cout << "Your choose is unavailable. Try Again!" << endl;
    }
    system("cls");
    int playerIndex = 0;
    do {
        string s;
        cout << "\nPlease press enter to continue." << endl;
        getline(cin, s);
        system("cls");
        cout << endl << players[playerIndex]->getName();
        cout << " Runde:\n" << endl;
        // Wir fragen den aktuellen Spieler, mit dem er angreift
        Schiff* attacker = players[playerIndex]->getAttackerSchiff();
        // Wir fragen den aktuellen Spieler, der angreift
        Schiff* defender = players[playerIndex]->getDefenderSchiff();

        bool angriffsErfolg;

        do {
            cout << "\nAttacker: ";
            attacker->ausSchreiben();
            cout << "\nDefender: ";
            defender->ausSchreiben();
            angriffsErfolg = false;
            int trefferprobe = rand() % 10 + 1; // 1-10
            if (trefferprobe + attacker->trefferProbeModifikator() >= defender->getGrosse()) {
                // wenn Angriff erfolgreich
                cout << "\nAngriff erfolgreich.\n" << endl;
                angriffsErfolg = true;
                int schaden = attacker->getkonkretSchaden(trefferprobe);
                defender->subtrahierenHulle(schaden);
                if (defender->getHulle() < 1) {
                    cout << "\nSchiff wurde zerstort.\n" << endl;
                    // Löschung aus der Flotte
                    players[playerIndex]->getEnemyFlotte()->loschenSchiff(defender);
                    cout << players[playerIndex]->getEnemyFlotte()->nummer() << " Schiff remaining.\n" << endl;
                }
            }
            else {
                cout << "\nAngriff NICHT erfolgreich\n" << endl;
            }
        } while (angriffsErfolg && attacker->hasBombardment() && defender->getHulle() > 0);
        cout << "\nResults: " << endl;
        cout << endl << players[playerIndex]->getName();
        cout << " Schiff:\n" << endl;
        attacker->ausSchreiben();
        cout << endl << players[1-playerIndex]->getName();
        cout << " Schiff:\n" << endl;
        defender->ausSchreiben();
        if (defender->getHulle() <= 0) {
            delete defender;
        }
        if (playerIndex == 0) {
            playerIndex = 1;
        }
        else {
            playerIndex = 0;
        }
    } while (flotte1->nummer() > 0 && flotte2->nummer() > 0);
    if (flotte1->nummer() == 0) 
    {
        cout << players[1]->getName() << " gewinnt." << endl;
    }
    else 
    {
        cout << players[0]->getName() << " gewinnt." << endl;
    }
}
