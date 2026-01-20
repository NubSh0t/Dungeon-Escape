#include <iostream>
using namespace std;
#include "room.hpp"

class Queue{
    Enemy* arr;
    int capacity;
    int front;
    int rear;
    int size;  
    public:
        Queue(int cap=10){
            capacity=cap;
            arr=new Enemy[capacity];
            front=0;
            rear=0;
            size=0;
        }

        void resize(){  //O(n)
            Enemy* arr2=new Enemy[capacity*2];

            for (int i=0;i<capacity;i++){
                arr2[i]=arr[i];
            }
            capacity=capacity*2;
            delete[] arr;
            arr=arr2;
        }

        Enemy dequeue(){ 
            if (size==0){   
                Enemy e(0,0);
                return e;
            }else{
                Enemy temp=arr[front];
                front=(front+1)%capacity;
                size-=1;
                return temp;
            }
        }

        void queue(Enemy value){   
            if (size+1==capacity){  
                resize();
            }
            arr[rear]=value;
            rear=(rear+1)%capacity; 
            size+=1;
        }

        int getSize(){
            return size;
        }

};

class Stack{
    DynamicArray array;
    int top;

    public:
        Stack(){
            top=-1;
        }

        void push(string value){
            array.push(value);
            top+=1;
        }

        string pop(){
            string s=array.pop();
            top-=1;
            return s;
        }

        string peek(){
            if (top>-1){
                return *array.get(top);
            }
            return "";
        }

};

class Node{

    Node* top;
    Node* bottom;
    Node* right;
    Node* left;
    Room room;

    public:
        Node()=default;

        Node(Room& r){     //r to store room in Node
            top=nullptr;
            bottom=nullptr;
            right=nullptr;
            left=nullptr;
            room=r;
        }

        ~Node(){
            if(top!=nullptr){
                top->setBottomRoom(nullptr);
                delete top;
            }

            if(bottom!=nullptr){
                bottom->setTopRoom(nullptr);
                delete bottom;
            }

            if(right!=nullptr){
                right->setLeftRoom(nullptr);
                delete right;
            }

            if(left!=nullptr){
                left->setRightRoom(nullptr);
                delete left;
            }

            delete this;
        }

        Room* getRoom(){
            return &room;
        }

        void setTopRoom(Node* t){
            top=t;
        }

        void setBottomRoom(Node* b){
            bottom=b;
        }

        void setRightRoom(Node* r){
            right=r;
        }

        void setLeftRoom(Node* l){
            left=l;
        }

        Node* getTopRoom(){
            return top;
        }

        Node* getBottomRoom(){
            return bottom;
        }

        Node* getRightRoom(){
            return right;
        }

        Node* getLeftRoom(){
            return left;
        }


};

class Dungeon{

    Node* current;
    Node* prev;
    Player p;
    Stack path;
    bool finished;
    Queue EnemyHandler;

    public:
        Dungeon(){
            finished=false;
            prev=nullptr;

            Room r1("Room 1","Null");
            Room r2("Room 2","Treasure");
            Room r3("Room 3","Treasure");
            Room r4("Room 4","Challenge");
            Room r5("Room 5","Enemy");
            Room r6("Room 6","Null");
            Room r7("Room 7","Enemy");
            Room r8("Room 8","Treasure");
            Room r9("Room 9","Treasure");
            Room r10("Room 10","Enemy");
            Room r11("Room 11","Enemy");
            Room r12("Room 12","Treasure");
            Room r13("Room 13","Enemy");
            Room r14("Room 14","Null");
            Room r15("Room 15","Treasure");
            Room r16("Room 16","Enemy");
            Room r17("Room 17","Enemy");
            Room r18("Room 18","Challenge");
            Room r19("Room 19","Enemy");
            Room r20("Room 20","Challenge");

            Node* n1=new Node(r1);
            Node* n2=new Node(r2);
            Node* n3=new Node(r3);
            Node* n4=new Node(r4);
            Node* n5=new Node(r5);
            Node* n6=new Node(r6);
            Node* n7=new Node(r7);
            Node* n8=new Node(r8);
            Node* n9=new Node(r9);
            Node* n10=new Node(r10);
            Node* n11=new Node(r11);
            Node* n12=new Node(r12);
            Node* n13=new Node(r13);
            Node* n14=new Node(r14);
            Node* n15=new Node(r15);
            Node* n16=new Node(r16);
            Node* n17=new Node(r17);
            Node* n18=new Node(r18);
            Node* n19=new Node(r19);
            Node* n20=new Node(r20);

            current=n1;

            n1->setTopRoom(n2);
            n1->setBottomRoom(n10);
            n1->setLeftRoom(n5);
            n1->setRightRoom(n6);

            n2->setBottomRoom(n1);

            n3->setBottomRoom(n6);

            n4->setBottomRoom(n5);

            n5->setRightRoom(n1);
            n5->setTopRoom(n4);

            n6->setTopRoom(n3);
            n6->setBottomRoom(n11);
            n6->setLeftRoom(n1);
            n6->setRightRoom(n7);

            n7->setLeftRoom(n6);
            n7->setRightRoom(n8);

            n8->setLeftRoom(n7);

            n9->setRightRoom(n10);

            n10->setTopRoom(n1);
            n10->setBottomRoom(n13);
            n10-> setLeftRoom(n9);

            n11->setTopRoom(n6);
            n11->setRightRoom(n20);
            n11->setBottomRoom(n12);

            n12->setTopRoom(n11);

            n13->setTopRoom(n10);
            n13->setLeftRoom(n14);

            n14->setRightRoom(n13);
            n14->setLeftRoom(n15);

            n15->setRightRoom(n14);
            n15->setLeftRoom(n16);

            n16->setRightRoom(n15);
            n16->setTopRoom(n17);

            n17->setBottomRoom(n16);
            n17->setTopRoom(n18);

            n18->setBottomRoom(n17);
            n18->setTopRoom(n19);

            n19->setBottomRoom(n18);

            n20->setLeftRoom(n11);

            path.push(r1.getName());
        }

        ~Dungeon(){
            delete current;
        }

        void run(){
            cout<<"Hello! there. Robbie is lost in dungeon. Can you help him to escape?(Y/N): ";
            string answer;
            cin>>answer;
            while (answer!="Y" && answer != "N"){
                cout<<"Enter again: ";
                cin>>answer;
            }

            if(answer=="N"){
                cout<<"Booooo! Boring"<<endl;
                return;
            }
            
            system("cls");  //clear screen

            string temp;

            while (!finished)
            {
                current->getRoom()->display();
                cout<<endl;
                cout<<"The current room is: "<<path.peek()<<endl;
                cout<<endl;
                p.showInventory();
                cout<<endl;

                if(current->getRoom()->getContent()=="Treasure"){
                    cout<<"You found a treasure chest!(press any key to continue): ";
                    cin>>temp;
                    current->getRoom()->setContent("Null");
                    if(current->getRoom()->getName()=="Room 2"){
                        p.getItem("Sword");
                        p.getItem("Healing Potion");
                        p.getItem("Healing Potion");
                        p.getItem("Healing Potion");
                        p.getItem("Healing Potion");
                        p.getItem("Healing Potion");
                        cout<<"You got a sword and 5 healing potions"<<endl;
                        cout<<"Attack increased"<<endl;
                        p.buff(0,7,0);
                    }
                    else if (current->getRoom()->getName()=="Room 8"){
                        p.getItem("Orb of Attack");
                        cout<<"You got the Orb of Attack"<<endl;
                        p.buff(0,0,5);
                    }
                    else if (current->getRoom()->getName()=="Room 3"){
                        p.getItem("Helmet");
                        cout<<"You got a helmet"<<endl;
                        cout<<"Armor increased"<<endl;
                        p.buff(0,0,5);
                    }
                    else if (current->getRoom()->getName()=="Room 9"){
                        p.getItem("Boots");
                        cout<<"You got boots"<<endl;
                        cout<<"Armor increased"<<endl;
                        p.buff(0,0,5);
                        
                    }
                    else if (current->getRoom()->getName()=="Room 15"){
                        p.getItem("Leggings");
                        cout<<"You got leggings"<<endl;
                        cout<<"Armor increased"<<endl;
                        p.buff(0,0,5);
                    }
                    else if (current->getRoom()->getName()=="Room 12"){
                        p.getItem("Chestplate");
                        cout<<"You got Chestplate"<<endl;
                        cout<<"Armor increased"<<endl;
                        p.buff(0,0,10);
                    }
                }
                else if(current->getRoom()->getContent()=="Challenge"){
                    cout<<"You are in a challenge room!(press any key to continue): ";
                    cin>>temp;
                    if(current->getRoom()->getName()=="Room 4"){
                        if(p.removeItem("Orb of Health")){
                            current->getRoom()->setContent("Null");
                            cout<<"Using the Orb of Health"<<endl;
                            cout<<"You got a 2x health boost"<<endl;
                            p.healthboost();
                        }
                        else{
                            cout<<"You don't have the Orb of Health"<<endl;
                            cout<<"Returning you back(press any key to continue): "<<endl;
                            cin>>temp;
                            path.pop();
                            current=prev;
                            system("cls");
                            continue;
                        }
                    }else if(current->getRoom()->getName()=="Room 18"){
                        if(p.removeItem("Orb of Attack")){
                            current->getRoom()->setContent("Null");
                            cout<<"Using the Orb of Attack"<<endl;
                            cout<<"You got a 2x attack boost"<<endl;
                            p.attackboost();
                        }
                        else{
                            cout<<"You don't have the Orb of Attack"<<endl;
                            cout<<"Returning you back(press any key to continue): "<<endl;
                            cin>>temp;
                            path.pop();
                            current=prev;
                            system("cls");
                            continue;
                        }
                    }else if(current->getRoom()->getName()=="Room 20"){
                        if(p.removeItem("Key")){
                            current->getRoom()->setContent("Null");
                            cout<<"Using the Key"<<endl;
                            cout<<"You escaped"<<endl;
                            finished=true;
                            cout<<endl<<"Robbie has escaped the dungeon, all thanks to you !!!";
                            break;
                        }
                        else{
                            cout<<"You don't have the Key"<<endl;
                            cout<<"Returning you back(press any key to continue): "<<endl;
                            cin>>temp;
                            path.pop();
                            current=prev;
                            system("cls");
                            continue;
                        }
                    }

                }
                else if(current->getRoom()->getContent()=="Enemy"){
                    cout<<"You just found some enemies!(press any key to continue): ";
                    cin>>temp;
                    if(current->getRoom()->getName()=="Room 5"){
                        Enemy e1(30,4);
                        EnemyHandler.queue(e1);
                    }else if(current->getRoom()->getName()=="Room 7"){
                        Enemy e1(40,8);
                        EnemyHandler.queue(e1);
                    }else if(current->getRoom()->getName()=="Room 10"){
                        Enemy e1(40,10);
                        EnemyHandler.queue(e1);
                    }else if(current->getRoom()->getName()=="Room 11"){
                        Enemy e1(60,15);
                        Enemy e2(40,15);
                        Enemy e3(40,15);
                        EnemyHandler.queue(e1);
                        EnemyHandler.queue(e2);
                        EnemyHandler.queue(e3);
                    }else if(current->getRoom()->getName()=="Room 13"){
                        Enemy e1(40,10);
                        EnemyHandler.queue(e1);
                    }else if(current->getRoom()->getName()=="Room 16"){
                        Enemy e1(40,10);
                        EnemyHandler.queue(e1);
                    }else if(current->getRoom()->getName()=="Room 17"){
                        Enemy e1(90,20);
                        EnemyHandler.queue(e1);
                    }else if(current->getRoom()->getName()=="Room 19"){
                        Enemy e1(200,25);
                        EnemyHandler.queue(e1);
                    }

                    int count=0;
                    while (EnemyHandler.getSize()>0){
                        count+=1;
                        Enemy e=EnemyHandler.dequeue();
                        while (e.isAlive() && p.isAlive()){
                            cout<<"You attacked Enemy "<<count<<endl;
                            cout<<"The attack did "<<p.getAttack()<<" and the enemy hp is now "<<e.takeDamage(p.getAttack())<<endl;
                            cout<<"The Enemy "<<count<<" attacked you"<<endl;
                            cout<<"The attack did "<<e.getAttack()<<" and now your hp is "<<p.takeDamage(e.getAttack())<<endl;

                        }
                    }


                    if (p.isAlive()){
                        cout<<endl<<"You won the fight!"<<endl;
                        current->getRoom()->setContent("Null");

                        if (current->getRoom()->getName()=="Room 11"){
                            cout<<"The enemy dropped the orb of health"<<endl;
                            p.getItem("Orb of Health");
                        }else if (current->getRoom()->getName()=="Room 19"){
                            cout<<"The enemy dropped a key"<<endl;
                            p.getItem("Key");
                        }

                    }else{
                        cout<<endl<<"You died :("<<endl;
                        cout<<endl<<"Run the program again to play again";
                        finished=true;
                        break;
                    }
                }

                cout<<endl;

                cout<<"Choose a room to move(W/A/S/D): ";
                cin>>answer;

                bool b=false;

                while (!b){

                    if(answer=="W"){
                        if(current->getTopRoom()!=nullptr){
                            string temp=path.pop();
                            path.push(current->getTopRoom()->getRoom()->getName());
                            prev=current;
                            current=current->getTopRoom();
                            b=true;
                        }else{
                            cout<<"There is no path north"<<endl;
                        }
                    }
                    else if(answer=="D"){
                        if(current->getRightRoom()!=nullptr){
                            path.push(current->getRightRoom()->getRoom()->getName());
                            prev=current;
                            current=current->getRightRoom();
                            b=true;
                        }else{
                            cout<<"There is no path east"<<endl;
                        }
                    }
                    else if(answer=="S"){
                        if(current->getBottomRoom()!=nullptr){
                            string temp=path.pop();
                            path.push(current->getBottomRoom()->getRoom()->getName());
                            prev=current;
                            current=current->getBottomRoom();
                            b=true;
                        }else{
                            cout<<"There is no path south"<<endl;
                        }
                    }
                    else if(answer=="A"){
                        if(current->getLeftRoom()!=nullptr){
                            string temp=path.pop();
                            path.push(current->getLeftRoom()->getRoom()->getName());
                            prev=current;
                            current=current->getLeftRoom();
                            b=true;
                        }else{
                            cout<<"There is no path west"<<endl;
                        }
                    }

                    if(!b){
                        cout<<"Enter again: ";
                        cin>>answer;
                    }
                }

                system("cls");

            }
        }
};