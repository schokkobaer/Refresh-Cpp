#pragma once
#include <string>
class Monster
{
    //Nested Type as this type belongs to the Monster class
    public: 
        enum Type
        {
            Dragon,
            Goblin,
            Ogre,
            Orc,
            Skeleton,
            Troll,
            Vampire,
            Zombie,
            Max_monster_types
        };
        std::string getTypeString(Type type);
    //The actual monster class 
    private:
        Type m_type;
        std::string m_name;
        std::string m_roar;
        int m_hitPoints;

    public:
        Monster(Type type, std::string name, std::string roar, int hitPoint);
        
        void print();
};
constexpr int MAX_INI_HIT_POINTS = 100;
namespace MonsterGenarator
{
    Monster generateMonster();
}
