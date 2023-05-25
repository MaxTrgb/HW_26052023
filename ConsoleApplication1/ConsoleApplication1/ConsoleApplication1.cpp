/*Write a function to convert a one-dimensional int array to a two-dimensional array. 
The number that is contained in the one-dimensional array should be replaced by a pointer, 
and the array to which it will point will have the size of the number that was contained in the original array. 
The two-dimensional array must be of char/string type and filled with stars.*/

#include <iostream>
#include <cstring>
using namespace std;

// Function to convert a one-dimensional int array to a two-dimensional array
void convertToTwoD(int* arr, int size, char*** output) {

    // Allocate memory for the two-dimensional array
    *output = new char* [size];

    for (int i = 0; i < size; i++) {

        int num = arr[i];  // Get the number from the one-dimensional array

        // Allocate memory for the row in the two-dimensional array
        (*output)[i] = new char[num + 1];

        // Fill the row with stars ('*')
        memset((*output)[i], '*', num);

        // Add null-terminator at the end of the row
        (*output)[i][num] = '\0';
    }
}

int main() {

    int arr[] = { 1, 5, 4, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);
    char** output = nullptr;

    convertToTwoD(arr, size, &output);  // Convert the array

    for (int i = 0; i < size; i++) {

        cout << output[i] << endl;  // Print each row of the two-dimensional array
        delete[] output[i];  // Deallocate memory for each row
    }

    delete[] output;  // Deallocate memory for the two-dimensional array

    return 0;
}
