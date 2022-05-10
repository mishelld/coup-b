#include "Captain.hpp"
#include "Game.hpp"
namespace coup
{
     Captain::Captain(Game &game,string name):Player(game, move(name)){

     }
      void Captain::steal(Player &player){
             if(this->name==game->turn()){
            if(player.amount>=2){
            game->nextturn();
            player.amount-=2;
            this->amount+=2;
            this->stealfrom = &player;
            
            }
            else if(player.amount==1){
            game->nextturn();
            player.amount-=1;
            this->amount+=1;
            this->stealfrom = &player;
                  }
            else{
                  throw invalid_argument("the player dosent have money");
            }
             }else{
            throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );

             }
           

      }
     void  Captain::block(Player &player){
             if(player.last_action=="foreign_aid"){
             if(!player.blocked){
                   player.blocked = true;
             }
             else {
                    throw invalid_argument("the player is already blocked");
             }
             }else{
                    throw invalid_argument("the last action of the player is not foreign aid");
             }
      }


      string Captain::role(){
            return "Captain";

      }
}