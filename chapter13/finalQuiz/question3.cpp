#include "Monster.h"
int main()
{
	Monster m{ MonsterGenarator::generateMonster() };
	m.print();

	return 0;
}