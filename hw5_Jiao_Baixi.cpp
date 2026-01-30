#include "linkedlist_Jiao.hpp"
#include "zombie_Jiao.h"
#include "termcolor.hpp"
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;
//make each case into functions
void engine_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    zombies.AddToFront(randomzombie);
    return;
}
void caboose_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    zombies.AddToEnd(randomzombie);
    return;
}
void jump_in_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    zombies.AddAtIndex(randomzombie,rand() % (zombies.Length() + 1));
    return;
}
void everyone_out_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    zombies.RemoveAllOf(randomzombie);
    return;
}
void you_out_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    zombies.RemoveTheFirst(randomzombie);
    return;
}
void brains_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    engine_action(zombies, randomzombie);
    caboose_action(zombies, randomzombie);
    zombies.AddAtIndex(randomzombie, zombies.Length()/2);
    return;
}
void rainbow_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    engine_action(zombies, randomzombie);
    char ch[6] = {'R', 'Y', 'G', 'B', 'C', 'M'};
    for(int i = 0;i < 6;i++){
        zombies.AddToEnd(Zombie(ch[i]));
    }
    return;
}
void friends_action(LinkedList<Zombie> &zombies, Zombie randomzombie){
    int index = zombies.IndexOf(randomzombie);
    if(index == - 1){
        caboose_action(zombies, randomzombie);
    }
    else {
        if(rand() & 1){
            zombies.AddAtIndex(randomzombie, index + 1);
        }
        else {
            zombies.AddAtIndex(randomzombie, index);
        }
    }
    return;
}
int main(int argc,char *argv[]){
    //determine the number of commands
    if(argc<2){
        srand(time(NULL));
    }
    else {
        srand(atoi(argv[2]));
    }
    //color each zombie
    cout << termcolor::colorize;
    char yn = 'y';
    int roundsNum = 0, flag = 0, roundCounter = 0;
    LinkedList<Zombie> zombies;
    cout << "Number of rounds do you want to run: ";
    cin >> roundsNum;
    cout << endl;
    while(yn == 'y'){
        for(int i = 0;i < roundsNum;i++){
            //add nodes before conga dance
            if(!flag){
                Zombie zombie;
                Zombie zombie1;
                Zombie zombie2;
                Zombie zombie3;
                rainbow_action(zombies, zombie);
                brains_action(zombies, zombie1);
                brains_action(zombies, zombie2);
                brains_action(zombies, zombie3);
                flag = 1;
            }
            //determine the rounds to delete both ends zombies
            if(roundCounter % 5 == 0){
                zombies.RemoveFromFront();
                zombies.RemoveFromEnd();
            }
            cout << "Round: "<< i << endl;
            zombies.PrintList();
            int op = rand() % 8;
            //random select the case we zombies do
            if(op == 0){
                Zombie zombie;
                engine_action(zombies, zombie);
                cout << "New Zombie: " << zombie << " -- Action: [Engine!]" << endl;
            }
            else if(op == 1){
                Zombie zombie;
                caboose_action(zombies,zombie);
                cout << "New Zombie: " << zombie << "]" << " -- Action: [Caboose!]" << endl;
            }
            else if(op == 2){
                Zombie zombie;
                jump_in_action(zombies, zombie);
                cout << "New Zombie: " << zombie << "]" << " -- Action: [Jump In!]" << endl;
            }
            else if(op == 3){
                Zombie zombie;
                everyone_out_action(zombies, zombie);
                cout << "New Zombie: " << zombie << "]" << " -- Action: [Everyone Out!]" << endl;
            }
            else if(op == 4){
                Zombie zombie;
                you_out_action(zombies, zombie);
                cout << "New Zombie: " << zombie << "]" << " -- Action: [You Out!]" << endl;
            }
            else if(op == 5){
                Zombie zombie;
                brains_action(zombies, zombie);
                cout << "New Zombie: " << zombie << " -- Action: [Brains!]" << endl;
            }
            else if(op == 6){
                Zombie zombie;
                rainbow_action(zombies, zombie);
                cout << "New Zombie: " << zombie << " -- Action: [Rainbow!]" << endl;
            }
            else{
                Zombie zombie;
                friends_action(zombies, zombie);
                cout << "New Zombie: " << zombie << " -- Action: [New Friends!]" << endl;
            }
            cout<<"The conga line is now:\n";
            zombies.PrintList();
            cout<<"**************************************************\n" << endl;
            roundCounter++;
        }

        //user decide whether zombies conga dance or not
        cout << "Do you want to continue?(y/n): ";
        cin >> yn;
        if(yn == 'y'){
            cout << "Number of rounds do you want to run: ";
            cin >> roundCounter;
            cout << endl;
        }
        cout << endl;
    }

}
