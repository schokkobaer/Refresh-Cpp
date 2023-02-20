# define DEF_IntPair
# ifdef DEF_IntPair

class IntPair
{
    private:
        int m_p1{0};
        int m_p2{0};
    public:
        IntPair(int a = 0, int b = 0):m_p1(a), m_p2(b){};
        ~IntPair(){};
        void set(int p1, int p2);
        void print();


};
#endif