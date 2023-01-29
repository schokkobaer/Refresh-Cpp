#include <algorithm> // std::shuffle
#include <array>
#include <ctime>
#include <iostream>
#include <numeric> // std::reduce
#include <random>

enum ItemType
{
    healthPotion,
    torch,
    arrow,
    maxItems
};

class Player
{
    private:
        std::array<int, static_cast<int>(ItemType::maxItems)> m_items;
    public:
        Player()
        {
            m_items[ItemType::healthPotion] = 2;
            m_items[ItemType::torch] = 5;
            m_items[ItemType::arrow] = 10;
        }

        int countTotalItems()const
        {
            return std::accumulate(m_items.begin(), m_items.end(), 0);
        }
        int getNumItem(ItemType itemtype)
        {
            return m_items[itemtype];
        }

};

int main()
{
 //Create a player
 Player p1 = Player();

 std::cout << "The player has a total of "<< p1.countTotalItems()<< " items.\n";
 std::cout << "He/ She has "<< p1.getNumItem(torch)<< " torche(s) in his inventory\n"; 

  return 0;
}