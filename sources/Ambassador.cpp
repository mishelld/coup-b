#include "Ambassador.hpp"
namespace coup{

   Ambassador::Ambassador(Game &game, string name) :Player(game, move(name)){
     
       
   }

   void Ambassador::transfer(Player &player1,Player &player2){
       if(this->name==game->turn()){
       if(player1.amount>=1){
            game->nextturn();
           player1.amount-=1;
           player2.amount+=1;
       }else{
        throw invalid_argument("not enough money" );

       }
       }else{
           throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );

       }
   }

   void Ambassador::block(Player &player1){
       player1.stealfrom->amount+=2;
       player1.amount-=2;
   }
       string Ambassador::role(){
           return "Ambassador";
       }



   


}