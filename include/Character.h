#ifndef CHARACTER_H
#define CHARACTER_H
#include "CharacterClass.h"
#include "ISkillUser.h"
#include <iostream>
#include "BattleContext.h"
#include <SFML/Graphics.hpp>

class Character: public ISkillUser
{
    public:
        Character(std::string name, int hp, CharacterClass* chclass);
        virtual ~Character();
        virtual void performSkill(BattleContext& ctx);
        void recieveEffect(EffectType type, int amount) override;
        bool isAlive() const override;
        std::string getName() const;
        void setHP(int amount) override;
        void setStatus(bool status) override;
        int getHP() const override;
        CharacterClass* getClass() const;
        void setTexture(sf::Texture texture);
        sf::Texture& getTexture();
        CharacterClass* _class;
        std::string _name;
        void setDefaultTexture();

    private:

        int _hp;
        bool _isAlive;
        sf::Texture _texture;

};

#endif // CHARACTER_H
