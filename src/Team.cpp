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

Team::Team(){

}

void Team::addCharacter(ISkillUser* character){
    _members[_memberCounter] = character;
    _memberCounter++;
}

ISkillUser* Team::getMember(int index) const {
    return _members[index];
}

ISkillUser** Team::getAliveMembers(int& outCount) const{
        ISkillUser** aliveMembers = new ISkillUser*[3];
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
