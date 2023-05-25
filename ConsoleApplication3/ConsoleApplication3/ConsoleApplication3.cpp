#include <iostream>
#include <string>

using namespace std;

void removeEmptyRows(string** arr, int rows);
void printArray(string** arr, int rows);


int main() {

    const int rows = 5;
    string** arr = new string * [rows];

    for (int i = 0; i < rows; i++) {

        arr[i] = new string[3];
    }

    // Initialize the array
    arr[0][0] = "apple";
    arr[0][1] = "banana";
    arr[0][2] = "cherry";
    arr[1][0] = "";
    arr[1][1] = "";
    arr[1][2] = "";
    arr[2][0] = "grape";
    arr[2][1] = "";
    arr[2][2] = "";
    arr[3][0] = "";
    arr[3][1] = "kiwi";
    arr[3][2] = "";
    arr[4][0] = "";
    arr[4][1] = "";
    arr[4][2] = "orange";

    cout << "Original array:" << endl;
    printArray(arr, rows);

    removeEmptyRows(arr, rows);

    cout << "\nArray after removing empty rows:" << endl;
    printArray(arr, rows);

    // Deallocate memory for the array
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
// Function to remove empty rows from a two-dimensional string array
void removeEmptyRows(string** arr, int rows) {
    string** result = new string * [rows];
    int resultIndex = 0;

    for (int i = 0; i < rows; i++) {
        bool isEmpty = true;

        for (int j = 0; j < 3; j++) {
            if (!arr[i][j].empty()) {
                isEmpty = false;
                break;
            }
        }

        if (!isEmpty) {
            result[resultIndex] = new string[3];
            for (int j = 0; j < 3; j++) {
                result[resultIndex][j] = arr[i][j];
            }
            resultIndex++;
        }
    }

    // Copy the non-empty rows back to the original array
    for (int i = 0; i < resultIndex; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = result[i][j];
        }
        delete[] result[i];  // Deallocate memory for each row
    }

    delete[] result;  // Deallocate memory for the result array
}

// Function to print a two-dimensional string array
void printArray(string** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
