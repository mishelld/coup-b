#include "Player.hpp"

namespace coup{
      class Contessa :public Player
    {
       public:  
       Contessa(Game &game,string name);
       void block(Player &Player1);
       static string role();

    };
}