#include <iostream>
#include <iterator>
#include <utility>

void printArray(int array[], int lengthOfArray)
{
    for (int i = 0; i < lengthOfArray; i++)
    {
        std::cout <<  array[i]<<" ";
    }
    std::cout << '\n';
}

void bubbleSort(int array[], int lengthArray)
{
    
    for (int endIndex = lengthArray -1; endIndex >0 ; endIndex--)
    {
        bool arrayIsSorted = true;
        for (int internalIndex = 0; internalIndex < endIndex; internalIndex++)
        {
            if (array[internalIndex ] < array[internalIndex+1 ])
            {
                std::swap(array[internalIndex +1 ], array[internalIndex ]);
                arrayIsSorted = false;
            }
                
        }
        printArray(array, lengthArray); 
        if (arrayIsSorted)
        {
            std::cout << "Early termination\n";
            return;
        }
            
        
    }
}
int main(int argc, char const *argv[])
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    int arraySize = (sizeof(array)/sizeof(array[0]));
    std::cout << "Before sorting: ";
    printArray(array, arraySize);
    std::cout << "--------------"<<std::endl;
    std::cout << "After sorting: ";
    bubbleSort(array, arraySize);
    printArray(array, arraySize);

    return 0;
}
