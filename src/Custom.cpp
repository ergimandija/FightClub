#include "Custom.h"

Custom::Custom()
{
    int choice;

    std::cout << "Choose 2 skills for your custom character:" << std::endl;

    for (int i = 0; i < 2; i++)
    {
        std::cout << std::endl;
        std::cout << "Select skill " << i + 1 << ":" << std::endl;
        std::cout << "0 -> Heal" << std::endl;
        std::cout << "1 -> Revive" << std::endl;
        std::cout << "2 -> FireBall" << std::endl;
        std::cout << "3 -> Lightning" << std::endl;
        std::cout << "4 -> Amputation" << std::endl;
        std::cout << "5 -> Slash" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
            case 0: skills[i] = new Heal(); break;
            case 1: skills[i] = new Revive(); break;
            case 2: skills[i] = new FireBall(); break;
            case 3: skills[i] = new Lightning(); break;
            case 4: skills[i] = new Amputation(); break;
            case 5: skills[i] = new Slash(); break;
            default:
                std::cout << "Invalid choice, defaulting to Slash." << std::endl;
                skills[i] = new Slash();
        }
    }
}

Custom::~Custom()
{
    //dtor
}
