/*
* Semester program
* task 1.4
* 
* 
* TEST
* C2 := (+01020, -00108, -00079);X8 := (-35001, +00102, -03041);AB := C2 * X8;BA := X8 ∧ C2;XY := X8 ∨ C2; 
* 
* C2 := (+01020, -00108, -00079);X8 := (-35001, +00102, -03041);AB := C2 * X8;BA := X8 ^ C2;XY := X8 ∨ C2; 
* XY := X8 ∨ C2;C2 := (+01020, -00108, -00079);AB := C2 * X8;X8 := (-35001, +00102, -03041);BA := X8 ^ C2; 
* XY := X8 ∨ C2;AB := C2 * X8;BA := X8 ^ C2;X8 := (-00213, -00345, +00054);C2 := (-00002, +53086, +99999); 
* BA := X8 ^ C2;C2 := (+00011, -00018, +00005);AB := C2 * X8;X8 := (-00034, +00021, +00342);XY := X8 ∨ C2; 
*/


#include <iostream>
#include <cmath>
#include <string>
using namespace std;


long* create_vector(int r)
{
    long* vector = new long[r];
    for (int i = 0; i < r; i++)
        vector[i] = 0;
    return vector;
}


long long sum_square(long* X, long* Y, int r)
{
	long long sum{ 0 };
    for (int i = 0; i < r; i++)
        sum += pow(X[i] - Y[i], 2);

	return sum;
}


long long max_deviation(long* X, long* Y, int r) 
{
	long long MAX{ -1 };

	for (int i = 0; i < r; i++)
	{
		if (MAX < abs(X[i] - Y[i]))
			MAX = abs(X[i] - Y[i]);
	}
	return MAX;
}


long long scolar_product(long* X, long* Y, int r)
{
	long long sum{ 0 };

	for (int i = 0; i < r; i++)
		sum += (X[i] * Y[i]);

	return sum;
}


int main()
{
    string input{""};
    int i{ 0 }; // number of commands
    getline(cin, input);

    string* commands{ new string[input.length()] };
    string command{ "" };

    for (int j = 0; j < input.length(); j++)
    {
        if (input[j] == ';')
        {
            commands[i] = command;
            i++;
            command = "";
        }
        else
        {
            command += input[j];
        }
    }

    if (command != "")
        commands[i] = command;


    // output of all commands
    cout << "-------- your commands -------\n";
    for (int j = 0; j < i; j++)
        cout << commands[j] << endl;
    cout << "------------------------------\n";


    // implementation of the program
    int vector_len{ 1 };


    // find out how many numbers one vector contains
    for (int j = 0; j < i; j++)
    {
        int len = commands[j].length();
        if ((commands[j][1] <= '9') && (commands[j][1] >= '1')) // it is a vector
        {
            for (int u = 8; u < len; u++) // index 8 - the beginning of the first number
            {
                // check how many numbers a vector contains
                if (commands[j][u] == ',')
                    vector_len++;
            }
            break; // no need to operate another vector
        }
    }

    // find out what numbers vectors contain
    long* first_var{ create_vector(vector_len) };
    long* second_var{ create_vector(vector_len) };
    int commandJ{ 0 }; // from what index need to search the second vector


    // completing the first vector
    for (int j = 0; j < i; j++) // command j
    {
        bool first_completed = 0;
        int len = commands[j].length();
        if ((commands[j][1] <= '9') && (commands[j][1] >= '0')) // is it a vector?
        {
            first_completed = 1;
            commandJ = j + 1;
            bool negative{ 0 }; // a sign of the first number of the vector

            for (int u = 7; u < len; u++) // numbers in the vector 
            {
                if (commands[j][u] == '-')
                    negative = 1;
                else if (commands[j][u] == '+')
                    negative = 0;
 
                if ((commands[j][u] <= '9') && (commands[j][u] >= '0'))
                    first_var[(u / 8) - 1] += int(commands[j][u] - '0') * pow(10, 4 - (u % 8));   

                if (u % 8 == 4) // it is the last digit of a number
                {
                    if (negative)
                        first_var[(u / 8) - 1] *= (-1); // the number goes with minus
                        
                }
            }
        }
        if (first_completed)
            break;    
    }


    for (int j = commandJ; j < i; j++) // command j
    {
        bool second_completed{0};
        int len = commands[j].length();
        if ((commands[j][1] <= '9') && (commands[j][1] >= '0')) // is it a vector?
        {
            second_completed = 1;
            bool negative{ 0 }; // a sign of the first number of the vector

            for (int u = 7; u < len; u++) // numbers in the vector 
            {
                if (commands[j][u] == '-')
                    negative = 1;
                if (commands[j][u] == '+')
                    negative = 0;


                if ((commands[j][u] <= '9') && (commands[j][u] >= '0'))
                    second_var[(u / 8) - 1] += int(commands[j][u] - '0') * pow(10, 4 - (u % 8));

                if (u % 8 == 4) // it is the last digit of a number
                {
                    if (negative)
                        second_var[(u / 8) - 1] *= (-1); // the number goes with minus
                }
            }
        }
        if (second_completed)
            break;
    }

    //// recognize operations
    for (int j = 0; j < i; j++) // command j
    {
        
        if (commands[j].find('^') != std::string::npos)
            std::cout << "^: " << max_deviation(first_var, second_var, vector_len) << '\n';

        else if (commands[j].find('∨') != std::string::npos)
            std::cout << "∨: " << sum_square(first_var, second_var, vector_len) << '\n';

        else if (commands[j].find('*') != std::string::npos)
            std::cout << "*: " << scolar_product(first_var, second_var, vector_len) << '\n';
    }


    // printing out
    std::cout << "\nThe elements\n";
    for (int o = 0; o < vector_len; o++)
        std::cout << first_var[o] << "  ";
    std::cout << "\n";
    for (int o = 0; o < vector_len; o++)
        std::cout << second_var[o] << "  ";

    delete[] commands;

    return 0;
}
