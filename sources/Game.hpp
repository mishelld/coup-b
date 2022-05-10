#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
// #include "Player.hpp"
#pragma once
using namespace std;

namespace coup
{
    
    class Player;
    class Game 
    {
    public: 
    vector<Player*> original;
    vector<Player*> p_g;
    vector<Player*> p_g_2;
    unsigned int t;
    unsigned int start = 0;
    unsigned int flag = 0;
    unsigned int curr = 0;




     
    //the player that plays in the current time
    string turn();

    //the players that playing in the current game
    vector<string> players();

    vector<string> outside();
    //the winner of the game , if game still on throw exception
    string winner();
    string nextturn();
    void addp(Player *p);
    
        
    };
    
} 