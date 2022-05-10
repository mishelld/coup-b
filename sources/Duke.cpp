#include "Duke.hpp"
namespace coup
{

        Duke::Duke(Game &game,string name): Player(game, move(name)){
          
        }
        //tax-can take 3 coins without anyone stopping him
        void Duke::tax(){
                 if(this->name==game->turn()){
                this->amount+=3;
                game->nextturn();
                 }else{
                 throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
  
                 }
        }
        //block- can clock double pay - the player that is blocked needs to retrun 2 coins
        void Duke::block(Player &player){
                if(player.last_action=="foreign_aid"){
                        player.blocked = true;
                        if( player.amount>=2){
                        player.amount-=2;
                        }else{
                        throw invalid_argument("the player dosent have enough money");
                        }
                }
                else{
                throw invalid_argument("the players last action is not foreign_aid");


                }

        }
        string  Duke::role(){
                return "Duke";
        }



}