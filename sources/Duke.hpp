#include "Player.hpp"

namespace coup{

    class Duke : public Player
    {  
        public:
        //constructor
        Duke(Game &game,string name);
        //tax-can take 3 coins without anyone stopping him
        void tax();
        //block- can clock double pay - the player that is blocked needs to retrun 2 coins
        static void block(Player &player);
        static string role();

    };
}