#include "Team.h"

Team::Team(std::string name)
{
    _name = name;
    _memberCounter = 0;
}

Team::~Team()
{
    //dtor
}


void Team::addCharacter(Character* character){
    _members[_memberCounter] = character;
    _memberCounter++;
}


Character** Team::getAliveMembers(int& outCount) const{
        Character** aliveMembers = new Character*[3];
        int counter=0;
        for(int i=0;i<_memberCounter;i++){
            if(_members[i]->isAlive()){
                aliveMembers[counter] = _members[i];
                counter++;
            }
        }
        outCount = counter;
        return aliveMembers;

}


int Team::getMemberCounter() const{
    return _memberCounter;
}
