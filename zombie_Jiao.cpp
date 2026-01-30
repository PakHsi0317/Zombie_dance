#include "zombie_Jiao.h"

using namespace std;
//class Zombie and constructors
Zombie::Zombie(){
    int num = rand() % 6;
    if(num == 0){
        this->type = 'R';
    }
    if(num == 1){
        this->type = 'Y';
    }
    if(num == 2){
        this->type = 'G';
    }
    if(num == 3){
        this->type = 'B';
    }
    if(num == 4){
        this->type = 'C';
    }
    if(num == 5){
        this->type = 'M';
    }
}
//getters and setters
Zombie::Zombie(char type){
    this->type = type;
}
char Zombie::getType()const{
    return this->type;
}
//determine whether 2 zombies are different
bool Zombie::operator==(const Zombie& zombie){
    return this->type == zombie.type;
}
//color the zombies
ostream& operator<<(ostream& ostr, const Zombie& zombie){
    if(zombie.getType()=='R'){
        ostr << "[" << termcolor::red << zombie.getType() << termcolor::reset << "]";
    }
    if(zombie.getType()=='Y'){
        ostr << "[" << termcolor::yellow << zombie.getType() << termcolor::reset << "]";
    }
    if(zombie.getType()=='G'){
        ostr << "[" << termcolor::green << zombie.getType() << termcolor::reset << "]";
    }
    if(zombie.getType()=='B'){
        ostr << "[" << termcolor::blue << zombie.getType() << termcolor::reset << "]";
    }
    if(zombie.getType()=='C'){
        ostr << "[" << termcolor::cyan << zombie.getType() << termcolor::reset << "]";
    }
    if(zombie.getType()=='M'){
        ostr << "[" << termcolor::magenta << zombie.getType() << termcolor::reset << "]";
    }
    return ostr;
}
