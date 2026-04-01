#ifndef ISKILLUSER_H
#define ISKILLUSER_H

enum EffectType {
    DAMAGE,
    HEAL,
    REVIVE
};
class ISkillUser
{
    public:
        ISkillUser();
        virtual ~ISkillUser();
        virtual void recieveEffect(EffectType type, int amount) = 0;
        virtual bool isAlive() const =0;
        virtual void setHP(int amount) =0;
        virtual void setStatus(bool status) =0;
        virtual int getHP() const = 0;
    protected:
        int _hp;
        bool _isAlive;
    private:

};

#endif // ISKILLUSER_H
