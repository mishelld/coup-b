#include "Player.hpp"

using namespace std;
namespace coup{

      class Assassin :public Player
    {
      public:
      

     
      //constructor
         Assassin(Game &game,string name);
         //can remove player from its role with 3 coins, but if the assassin is blocket the player comes back to its role
        // void coup(Player &player);
        static string role();


    };
}