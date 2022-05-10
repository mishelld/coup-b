#include "Player.hpp"
#include "Game.hpp"
const int num = 7;
const int six = 6;
const int t = 2;
const int ten= 10;

const int tre= 3;
namespace coup{
     
        Player::Player(Game &game,string name){
                this->name = move(name);
                this->game = &game;
                this->amount = 0;
                this->inside = true;
                this->blocked = false;
                this->last_action = "";
                this->type = "";
                this->moneybe = 0;
                this->assassinated = this;
                this->stealfrom = this;
                
                /*
                */
               if(this->inside){
                game.addp(this);
                }
        }
        //take 1 coin 
        void  Player::income(){
                if(!start){
                        start = true;
                }
                if((game->flag>=t) && (game->flag<=six)){
                if(this->name==game->turn()){
                this->amount++;
                game->nextturn();
                this->last_action = "income";

                }
                else{
                        throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
                }
                }
                else{
                         throw invalid_argument("not enough players" );
                }
        }

        //remove other player costs 7 coins
        void Player::coup(Player &p){
                if(!start){
                        start = true;
                }
                if((game->flag>=t) && (game->flag<=six)){
                if(this->name==game->turn()){
                if(this->amount>=num){
                if(p.inside){        
                p.inside = false;
                if(this->type=="Assassin"){
                        this->moneybe=this->amount;
                }

                this->amount-=num;
                this->last_action = "coup";
                this->assassinated = &p;
                game->nextturn();
                game->players();
                
                }else{
                      throw invalid_argument("the player is alredy" );  
                }
               
                }else if(this->amount>=3 && this->type == "Assassin"){
                if(p.inside){        
                p.inside = false;
                this->amount-=tre;
                this->last_action = "coup";
                this->assassinated = &p;
               game->nextturn();
                game->players();
                }else{
                 throw invalid_argument("the player is alredy dead" );  

                }
                }
                else{
                         throw invalid_argument("the player dosent have enough money ");
                }
                }
                else{
                         throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
                }
                }
                else{
                         throw invalid_argument("not enough players" );
  
                 }
        }
        //shows curr role of the player
        int Player::coins() const{
                return this->amount;

        }
        
         //douvle coin take
        void  Player::foreign_aid(){
                if(!start){
                        start = true;
                }
                if((game->flag>=t) && (game->flag<=six)){

                if(this->name==game->turn()){
                if(this->amount<ten){         
                game->nextturn();
                this->amount+=t;
                this->last_action = "foreign_aid";
                }else{
                        throw invalid_argument("more then 10 coins" );
                }
                }
                else{
                          throw invalid_argument("the turn belongs to " +game->turn() +  " and not to " + this->name );
                 }

                }
                else{
                  throw invalid_argument("not enough players" );
  
        }
                

        }


        
}