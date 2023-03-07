#include "Monster.h"
#include "Random.h"
#include <iostream>
std::string Monster::getTypeString(Type type)
{
    switch (type)
    {
    case Monster::Type::Dragon:  return "Dragon";
    case Monster::Type::Skeleton:  return "Skeleton";
    case Monster::Type::Goblin:  return "Goblin";
    case Monster::Type::Ogre :  return "Ogre";
    case Monster::Type::Orc :  return "Orc";
    case Monster::Type::Troll :  return "Troll";
    case Monster::Type::Vampire :  return "Vampire";
    case Monster::Type::Zombie :  return "Zombie";
    default:                      return "Unknown Type";
    }
}

Monster::Monster(Type type, std::string name, std::string roar, int hitPoints) : m_type(type), m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
{
}

void Monster::print()
{
    std::cout<< m_name <<" the " << getTypeString(m_type) << " has "<< m_hitPoints;
    std::cout << " hit points and says "<< m_roar <<".\n";
}

Monster MonsterGenarator::generateMonster()
{
    static std::uniform_int_distribution TypeGenerator{ 0, Monster::Max_monster_types-1 };
    Monster::Type randomType = static_cast<Monster::Type> (TypeGenerator(Random::mt));

    static std::uniform_int_distribution HitPointsGenerator{ 0, MAX_INI_HIT_POINTS};
    int initHitPoints  = HitPointsGenerator(Random::mt);

    static const char* randomNames[6] = {"Bubu", "Tom", "Gandalf", "Smog", "Zhao Lin", "Lulu"};
    static const char* randomRoars[6] = {"Tzzz", "Roarrrr", "*rattle*", "Wuff", "Miau", "Kikiriki"};
    static std::uniform_int_distribution die{ 0,5};

    std::string init_name = randomNames[die(Random::mt)];
    std::string init_roar = randomRoars[die(Random::mt)];

    return Monster(randomType, init_name, init_roar, initHitPoints);
}
