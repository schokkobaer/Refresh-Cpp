constexpr int Max_Size = 10;
class Stack
{
private:
    
    int m_data[Max_Size];
    int m_valueCounter{0};
    
public:
    Stack(/* args */): m_valueCounter(0){};
    ~Stack(){};
    /// @brief This function reset the size to 0
    void reset();

    /// @brief This funtion pushes a value on the stack. Return false if the array is already full,
    // true otherwise
    /// @param value Pushes the Value on to the stack
    bool push(int value);

    /// @brief This function takes a value away from the top of the stack and returns it.
    // If no value are on the stack it exits via an assert
    int pop();

    /// @brief Prints all the value in the stack 
    void print();
};

