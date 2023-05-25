/*Write a program that element-by-element sums two dynamic two-dimensional arrays 
filled with random numbers and stores the result in the third array. 
The sizes of the output arrays are set by the user*/

#include <iostream>
#include <cstring>

using namespace std;

// Function to initialize the arrays with random values
void initializeArr(int** first_array, int size_first);

// Function to sum two arrays element-wise and return the result
int** sumArrays(int** first_array, int size_first, int** second_array, int size_second);

// Function to print the content of an array
void printArray(int** arr, int size);

int main()
{
    srand(time(NULL));

    int size_first = 5, size_second = 5;

    int** first_array = new int* [size_first];
    int** second_array = new int* [size_second];

    // Initializing the first array with random values
    initializeArr(first_array, size_first);

    // Initializing the second array with random values
    initializeArr(second_array, size_second);

    // Summing the two arrays and storing the result in a new array
    int** result_array = sumArrays(first_array, size_first, second_array, size_second);

    // Printing the result array
    printArray(result_array, size_first);

}

void initializeArr(int** first_array, int size_first) {
    // Allocating memory for each row in the 2D array
    for (int i = 0; i < size_first; i++)
    {
        first_array[i] = new int[size_first];
    }

    // Filling the array with random values
    for (int i = 0; i < size_first; i++)
    {
        for (int j = 0; j < size_first; j++) {
            first_array[i][j] = rand() % 10;
            printf("%d   ", first_array[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int** sumArrays(int** first_array, int size_first, int** second_array, int size_second) {
    // Creating a new array to store the sum of the two input arrays
    int** result_array = new int* [size_first];

    for (int i = 0; i < size_first; i++)
    {
        // Allocating memory for each row in the result array
        result_array[i] = new int[size_first];

        for (int j = 0; j < size_first; j++)
        {
            // Summing the corresponding elements from the input arrays
            result_array[i][j] = first_array[i][j] + second_array[i][j];
        }
    }

    return result_array;
}

void printArray(int** arr, int size)
{
    // Printing the content of the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}
