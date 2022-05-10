#include "Game.hpp"
#include "Player.hpp"
namespace coup{
const int s = 6;


    //the players that playing in the current game
    vector<string> Game::players(){
        vector <string> p;
        vector <Player*> temp;
        vector <Player*> temp2;
        if(start==0){
            for(Player *pl:p_g){
                original.push_back(pl);
                  p.push_back(pl->name);
            }
            start=1;
            return p;
        }
        for(Player *pl: original){
        if(pl->inside) {
               p.push_back(pl->name);
               temp.push_back(pl);
           }
        else{
                 temp2.push_back(pl);
           }
        }
        p_g.clear();
       p_g = temp;
       p_g_2.clear();
       p_g_2= temp2;




        return p;
    
    }
     


        void Game::addp(Player *p){
            flag++;
            if(flag>s){
                       throw invalid_argument("too many");

            }
            if(start!=0U){
                 throw invalid_argument("game already started");
            }
            p_g.push_back(p);

            

            
        }

    /// | | |
    string Game::turn(){
  
    if(t>0){  
       return original[t%original.size()]->name;
        }
        return p_g[t%p_g.size()]->name;


    }
    //the winner of the game , if game still on throw exception
    string Game::winner(){
        if(p_g.size()==1 && flag>=2){
            return p_g[0]->name;
        }
        throw invalid_argument("not winner yet");
        
    }

    string Game::nextturn(){
       players();
        do
        {
            t = (t+1) % original.size();
        } while (!original[t]->inside);
     
       return p_g[(t%original.size())]->name;
    }

}