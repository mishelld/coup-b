#include "Contessa.hpp"
#include "Game.hpp"
#include "Player.hpp"
namespace coup{
    const int e = 6;

    Contessa::Contessa(Game &game,string name):Player(game, move(name)){

    }
     void Contessa::block(Player &player){
         if(player.last_action=="coup"){
             if(player.type=="Assassin" && player.moneybe<e){
             player.blocked=true;
             player.assassinated->inside = true;
             game->players();
             }else{
                 throw invalid_argument("assain had 8 coins"); 
             }
             }
             
         else{
             throw invalid_argument("the last action is not coup its" +player.last_action);
         }
     }
      string Contessa::role(){
            return "Contessa";

      }
     
}