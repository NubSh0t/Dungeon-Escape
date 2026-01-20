#include <iostream>
using namespace std;
#include "player.hpp"
#include "enemy.hpp"

string emptyRoom[]={
    "/ / / / / / / / / / / / / / / / / / / / / /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                 (O_O)                   /",
    "/                /)   )--                 /",
    "/                 /   \\                   /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/ / / / / / / / / / / / / / / / / / / / / /"
};

string treasureRoom[]={
    "/ / / / / / / / / / / / / / / / / / / / / /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                 _____                   /",   
    "/                |_____|                  /",
    "/                | $ $ |                  /",
    "/                |_____|                  /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                 (0_0)                   /",
    "/                /)   )--                 /",
    "/                 /   \\                   /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/ / / / / / / / / / / / / / / / / / / / / /"
};

string enemyRoom[]={
    "/ / / / / / / / / / / / / / / / / / / / / /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                 (>_<)                   /",    
    "/               /-|   |-\\                 /",
    "/                 |   |                   /",
    "/                /     \\                  /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/                 (0_0)                   /",
    "/                /)   )--                 /",
    "/                 /   \\                   /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/ / / / / / / / / / / / / / / / / / / / / /"
};

string challengeRoom[]={
    "/ / / / / / / / / / / / / / / / / / / / / /",
    "/                                         /",
    "/                                         /",
    "/                  ###                    /",
    "/               #       #                 /",    
    "/             #           #               /",
    "/             #           #               /",
    "/               #       #                 /",
    "/                  ###                    /",
    "/                                         /",
    "/                                         /",
    "/                 (0_0)                   /",
    "/                /)   )--                 /",
    "/                 /   \\                   /",
    "/                                         /",
    "/                                         /",
    "/                                         /",
    "/ / / / / / / / / / / / / / / / / / / / / /"
};


class Room{

    string content;
    string name;
    bool b;

    public:
        Room()=default;

        Room(string n,string c="Null"){
            name=n;
            content=c;
            b=false;
        }

        string getName(){
            return name;
        }

        string getContent(){
            return content;
        }

        void setContent(string c){
            content=c;
        }

        void display(){

            if(content=="Null"){
                for(int i=0;i<size(emptyRoom);i++){
                    cout<<emptyRoom[i]<<endl;
                }
            }else if (content=="Treasure"){
                for(int i=0;i<size(treasureRoom);i++){
                    cout<<treasureRoom[i]<<endl;
                }
            }else if (content=="Enemy"){
                for(int i=0;i<size(enemyRoom);i++){
                    cout<<enemyRoom[i]<<endl;
                }
            }else if (content=="Challenge"){
                for(int i=0;i<size(challengeRoom);i++){
                    cout<<challengeRoom[i]<<endl;
                }
            }

            cout<<endl;

        }
};