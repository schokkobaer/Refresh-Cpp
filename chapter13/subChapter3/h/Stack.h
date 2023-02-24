constexpr int Max_Size = 10;
class Stack
{
private:
    
    int m_data[Max_Size];
    int m_valueCounter;
    
public:
    Stack(/* args */);
    ~Stack();
    /// @brief This function reset the size to 0
    void reset();

    /// @brief This funtion pushes a value on the stack. Return false if the array is already full,
    // true otherwise
    bool push(int value);

    /// @brief This function takes a value away from the top of the stack and returns it.
    // If no value are on the stack it exits via an asser
    int pop();

    /// @brief Prints all the value in the stack 
    void print();
};

