#include <iostream>
#include <cmath>


template <typename T>
void printArray(T* array, int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << array[i] << " ";
    }
}

template <typename T>
int findMin(T* array, int n)
{
    T minElement{ 1000000000 };
    int index{ 0 };

    for (int i = 0; i < n; i++)
    {
        if (std::abs(array[i]) < minElement) {
            minElement = std::abs(array[i]);
            index = i;
        }
    }
    return index;
}


template <typename T>
T findSum(T* array, int n)
{
    int indexOFnegative{ 0 };
    T sum{ 0 };
    bool negFound{ 0 };

    for (int i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            if (negFound == 0)
                negFound = 1;
            else
                sum += array[i];
        }
        else
        {
            if (negFound)
                sum += array[i];
        }

    }
    if (sum)
        return sum;
    return 1;
}


template <typename T>
T* compressArray1(T* array, int n, T a, T b, bool print = false)
{
    int chosenNum{ 0 };
    int shift{ 0 }; // на сколько индексов идет сдвиг относительно i в arrat и в newArray во втором цикле

    for (int i = 0; i < n; i++)
    {
        if ((a <= array[i]) && (array[i] <= b))
            chosenNum += 1;
    }

    T* newArray = new T[n - chosenNum];

    for (int i = 0; i < n; i++)
    {
        if ((a <= array[i]) && (array[i] <= b))
            shift += 1; 
        else          
            newArray[i - shift] = array[i];
    }

    if (print)
        printArray(newArray, n - chosenNum);

    return newArray;
}


// implement the second way
template <typename T>
T* compressArray2(T* array, int n, T a, T b)
{
    T* tempArray = new T[n];
    int shift{ 0 };
     
    for (int i = 0; i < n; i++)
        tempArray[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if ((array[i] >= a) && (array[i] <= b))
            shift += 1; 
        else
            tempArray[i - shift] = array[i];
    }

    // add zero elements at the end of the temparray
    for (int i = (n - 1); i > shift; i--)
        tempArray[i] = 0;

    return tempArray;
}

int main()
{
    bool answer{ 0 };
    int length{ 0 };

    std::cout << "Would you like to work with interger (enter 1) or decimal (enter 0) numbers?\n";
    std::cin >> answer;

    std::cout << "Enter amount of numbers:\n";
    std::cin >> length;


    if (answer) {
        int* array = new int[length];
        std::cout << "Enter your numbers:\n";

        for (int i = 0; i < length; i++)
            std::cin >> array[i];

        int a{0};
        int b{0};
        std::cout << "Enter a and b:\n";
        std::cin >> a;
        std::cin >> b;

        std::cout << "The index of the modulo min element: " << findMin(array, length) << "\n";
        std::cout << "The sum after first negatie element: " << findSum(array, length) << "\n";
        compressArray1(array, length, a, b, true); // compresing the array with its printing out
        std::cout << "\n";
        printArray(compressArray2(array, length, a, b), length);

    }
    else 
    {
        double* array = new double[length];
        std::cout << "Enter your numbers:\n";

        for (int i = 0; i < length; i++)
            std::cin >> array[i];

        double a;
        double b;
        std::cout << "Enter a and b:\n";
        std::cin >> a;
        std::cin >> b;

        std::cout << "The index of the modulo min element: " << findMin(array, length) << "\n";
        std::cout << "The sum after first negative element: " << findSum(array, length) << "\n";
        compressArray1(array, length, a, b, true); // compresing the array with its printing out
        std::cout << "\n";
        printArray(compressArray2(array, length, a, b), length);
    }

    return 0;
}
