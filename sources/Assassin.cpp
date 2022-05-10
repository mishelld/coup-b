#include "Assassin.hpp"
namespace coup{
     Assassin::Assassin(Game &game, string name) :Player(game,move(name) )
    {
        this->type = "Assassin";
    }

  /* void Assassin::coup(Player &player)
   {   
        if(this->name==game->turn()){
         if(this->amount>=7){
              if(player.inside==true){
           this->amount-=7;
           player.inside = false; 
           this-> last_action = "coup";
           this->assassinated = &player;
             game->nextturn();


           game->players();

         }else{
            
            throw invalid_argument("player already dead");

          }
         }   
       else if(this->amount>=3){
          if(player.inside==true){
           this->amount-=3;
           player.inside = false; 
           this-> last_action = "coup";
           this->assassinated = &player;

           game->nextturn();
           game->players();
          }else{
            throw invalid_argument("player already dead");

          }
           
       }else{
           throw invalid_argument("not enough coins");
       }
        }else{
                                    throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );

        }

    }*/

    string Assassin::role(){
        return "Assassin";

    }
}