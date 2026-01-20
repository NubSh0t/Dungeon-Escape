class DynamicArray{
    int capacity;
    int size;
    string* array;

    void resize(){

        string* temp=new string[capacity*2];

        for (int i=0;i<capacity;i++){
            temp[i]=array[i];
        }
        capacity=capacity*2;
        delete[] array;
        array=temp;
    }

    public:
        DynamicArray(int cap=20){
            capacity=cap;
            size=0;
            array = new string[capacity];
        }

        ~DynamicArray(){
            delete[] array;
        }

        void push(string s){
            if (size==capacity){
                resize();
            }
            array[size]=s;
            size+=1;
        }

        string pop(){
            if (size>0){
                size-=1;
                return array[size];
            }
            return "";
        }

        string* get(int index){
            return &array[index];
        }

        int getSize(){
            return size+1;
        }

};

class Player{

    DynamicArray inventory;
    int health;
    int attack;
    bool dead;
    int armor;
    int maxhealth;

    public:
        Player(){
            health=50;
            attack=3;
            armor=0.0;    //armor is in percent
            dead=false;
            maxhealth=50;
        }

        int getAttack(){
            return attack;
        }

        bool isAlive(){
            return !dead;
        }

        void showInventory(){
            cout<<"Your Inventory: "<<endl;
            for(int i=0;i<inventory.getSize();i++){
                if (*inventory.get(i) !=""){
                    cout<<*inventory.get(i)<<" ";
                }
            }
            cout<<endl;
        }

        bool removeItem(string s){
            for(int i=0;i<inventory.getSize();i++){
                if (s==*inventory.get(i)){
                    *inventory.get(i)="";
                    return true;
                }
            }
            return false;
        }

        void getItem(string s){
            inventory.push(s);
        }

        int takeDamage(int atk){
            int dmg=atk-armor;
            if (dmg<1){
                dmg=1;
            }
            if (health-dmg<=0){
                if(this->removeItem("Healing Potion")){
                    health=maxhealth;
                    cout<<"(after using the healing potion) "<<endl;
                }

            }
            health-=dmg;
            if (health<=0){
                dead=true;
            }
            return health;
        }

        void buff(int h=0,int a=0, int ar=0){
            health+=h;
            attack+=a;
            armor+=ar;
        }

        void healthboost(){
            maxhealth*=2;
            health+=50;
        }

        void attackboost(){
            attack*=2;
        }
};

