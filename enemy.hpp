class Enemy{
    int health;
    int attack;
    bool dead;

    public:
        Enemy(int hp,int atk){
            health=hp;
            attack=atk;
            dead=false;
        }

        Enemy()=default;

        int takeDamage(int atk){
            health-=atk;
            if (health<=0){
                dead=true;
                health=0;
            }
            return health;

        }

        int getAttack(){
            return attack;
        }

        bool isAlive(){
            return !dead;
        }

};