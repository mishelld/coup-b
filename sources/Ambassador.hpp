#include "Player.hpp"
using namespace std;
namespace coup{
 class Ambassador:public Player
    {
        public:
       Ambassador(Game &game,string name);
       //transfer from one player to another;
       void transfer(Player &player1,Player &player2);
       static void block(Player &player1);
       static string role();
       
       

    };
    

}
