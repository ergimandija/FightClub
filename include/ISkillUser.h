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
    protected:

    private:
};

#endif // ISKILLUSER_H
