#include "Game.hpp"
#include <string>
#pragma once
using namespace std;
namespace coup{
    class Game;
    class Player
    {   
        public:
        int amount;
        string name;
        Game *game;
        bool inside;
        bool blocked;
        string last_action;
        Player  *assassinated;
        Player *stealfrom;
        string type;
        int moneybe;
        bool start = false;
        Player(Game &game,string name);
        //take 1 coin 
        void income();
        //remove other player costs 7 coins
        void coup(Player &p);
        //shows curr role of the player
        
        
        //shows amount of coins 
        int coins() const;

        int shekels();
         //douvle coin take
        void foreign_aid();

      

    };
}