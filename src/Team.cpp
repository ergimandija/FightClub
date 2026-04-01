#include "Team.h"

Team::Team(std::string name)
{
    _name = name;
    _memberCounter = 0;
    _wins = 0;
    _losses = 0;
}

Team::~Team()
{
    //dtor
}

Team::Team(){

}

void Team::addCharacter(ISkillUser* character){
    if(_memberCounter < 3){
    _members[_memberCounter] = character;
    _memberCounter++;
    }
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

void Team::win(){
    std::cout << _name << " won!" << std::endl;
    _wins++;
}

void Team::lose() {
    _losses++;
}


int Team::getAliveMemberCounter() {
    int counter=0;
    for(int i=0;i<_memberCounter;i++){
            if(_members[i]->isAlive()){
                counter++;
        }
    }
    return counter;

}

int Team::getMemberCounter() const{
    return _memberCounter;
}

std::string Team::getTeamName() const {
    return _name;
}

void Team::resetTeam() {
    for(int i=0;i<_memberCounter;i++){
        _members[i]->setStatus(true);
        _members[i]->setHP(100);
    }
}

void Team::showStats() const {
    std::cout << "===== Team Stats =====" << std::endl;
    std::cout << "Team: " << _name << std::endl;
    std::cout << "Wins: " << _wins << std::endl;
    std::cout << "Losses: " << _losses << std::endl;

    std::cout << std::endl;
    std::cout << "Members:" << std::endl;

    for (int i = 0; i < _memberCounter; i++) {
        std::cout << "Member " << i + 1 << ": ";

        if (_members[i]->isAlive()) {
            std::cout << "Alive";
        } else {
            std::cout << "Dead";
        }

        std::cout << " | HP: " << _members[i]->getHP();

        std::cout << std::endl;
    }

    std::cout << "======================" << std::endl;
}
