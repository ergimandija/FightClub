#include "Game.h"

Game::Game()
{
    std::cout << "Game Start!" << std::endl;
    std::string teamName = "";
    std::cout << "Team 1 being created...give in the name" << std::endl;
    std::cin >> teamName;
    _teamA = Team(teamName);
    generateCharacters(_teamA,Game::pickTeamMode());
    std::cout << "Team 2 being created...give in the name" << std::endl;
    std::cin >> teamName;
    _teamB = Team(teamName);
    generateCharacters(_teamB,Game::pickTeamMode());
}

Game::~Game()
{
    std::cout << "Game finished" << std::endl;
}
CharacterType Game::pickTeamMode(){
    int pick;
    while(true){
    std::cout << "Please give in the Team type," << std::endl;
    std::cout << "(0->AI Team, 1-> Player Team)" << std::endl;
    std::cin >> pick;
    if(pick == 0 || pick == 1){
        break;
    }
    std::cout << "Input Invalid, try Again" << std::endl;
    }
    return static_cast<CharacterType>(pick);
}

ClassType Game::pickClassType(){
    int pick;
    while(true){
    std::cout << "Character being created, please give in the class," << std::endl;
    std::cout << "(0->Fighter, 1->Mage,2->Healer ,3->Custom)" << std::endl;
    std::cin >> pick;
    if(pick >= 0 || pick < 4){
        break;
    }
    std::cout << "Input Invalid, try Again" << std::endl;
    }
    return static_cast<ClassType>(pick);
}

std::string Game::selectName() {
    std::string name;
    std::cout << "Enter Character Name: " << std::endl;
    std::cin >> name;
    return name;
}

void Game::generateCharacters(Team& t, CharacterType chtype){
        for(int i=0;i<3;i++){
        ClassType cltype = Game::pickClassType();
        std::string name =  Game::selectName();
        t.addCharacter(CharacterFactory::createCharacter(name,cltype,chtype));
        }
}

void Game::reset(){
    std::cout << "Game Resetting!" << std::endl;
    int choice;
    while(true){
            std::cout << "Would you like to regenerate Team 1? (1->yes, 0->no keep as is)" << std::endl;
            std::cin >> choice;
            if(choice==1){
            std::string teamName = "";
            std::cout << "Team 1 being created...give in the name" << std::endl;
            std::cin >> teamName;
            _teamA = Team(teamName);
            generateCharacters(_teamA,Game::pickTeamMode());
            break;
            } else if(choice == 0) {
            break;
            }

    }

    while(true){
            std::cout << "Would you like to regenerate Team 2? (1->yes, 0->no keep as is)" << std::endl;
            std::cin >> choice;
            if(choice==1){
            std::string teamName = "";
            std::cout << "Team 2 being created...give in the name" << std::endl;
            std::cin >> teamName;
            _teamB = Team(teamName);
            generateCharacters(_teamB,Game::pickTeamMode());
            break;
            } else if(choice == 0) {
              break;
            }

    }
}
void Game::start(){
    bool running = true;

    while(running){
            GameRound round = GameRound(_teamA,_teamB);

            while(!round.getGameStatus()){
                round.executeTurn();
            }
            std::cout << "--- Final Stats ---" << std::endl;
            _teamA.showStats();
            _teamB.showStats();
              int choice;
            while(true){
                std::cout << "What next?" << std::endl;
                std::cout << "(1 -> Play again / Reset)"<< std::endl;
                std::cout << "(0 -> Exit)" << std::endl;
                std::cin >> choice;

                if(choice == 1){
                    this->reset();
                    break;
                } else if(choice == 0){
                    running = false;
                    break;
                } else {
                    std::cout << "Invalid input, try again.\n";
                }
            }

    }
}






