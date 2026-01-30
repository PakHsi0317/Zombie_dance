#pragma once
#ifndef ZOMBIE_JIAO_H
#define ZOMBIE_JIAO_H
#include "termcolor.hpp"
#include<iostream>
#include<string>


using namespace std;
//declare before we use
class Zombie{
    private:
        char type;

    public:
        Zombie();
        Zombie(char type);
        char getType()const;
        bool operator==(const Zombie& zombie);
        friend ostream& operator<<(ostream& ostr, const Zombie& zombie);
};

ostream& operator<<(ostream& ostr, const Zombie& zombie);

#endif
