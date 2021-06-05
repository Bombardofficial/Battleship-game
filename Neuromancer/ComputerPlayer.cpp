#include "ComputerPlayer.h"
#include <chrono>
#include <thread>

Schiff* ComputerPlayer::getAttackerSchiff() {
    this_thread::sleep_for(chrono::milliseconds(250));
    int wsch = rand() % flotte->nummer();
    return flotte->bekommenSchiff(wsch + 1);
    
    
}

Schiff* ComputerPlayer::getDefenderSchiff() {
    this_thread::sleep_for(chrono::milliseconds(250));
    int wsch = rand() % enemyFlotte->nummer();
    return enemyFlotte->bekommenSchiff(wsch + 1);
    
    
}
