#include<iostream>
#include<bits/stdc++.h>
#include<array>
using namespace std;

vector<vector<int>> convertArray(int n, int m, vector<vector<int>> sparseMatrix) {
    int size = 0;
    // Calculating the number of non-zero elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sparseMatrix[i][j] != 0) {
                size += 1;
            }
        }
    }

    // Initialize the compressed matrix to have 'size' rows and 3 columns
    vector<vector<int>> compressed;
    
    // Compressing the sparse matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sparseMatrix[i][j] != 0) {
                vector<int> row;  // Create a new row for each non-zero element
                row.push_back(i);  // Row index
                row.push_back(j);  // Column index
                row.push_back(sparseMatrix[i][j]);  // Value
                compressed.push_back(row);  // Add the row to the compressed matrix
            }
        }
    }

    return compressed;
}

int main() {
    vector<vector<int>> sparseMatrix =
    {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    vector<vector<int>> compressed = convertArray(4, 5, sparseMatrix);

    // Correctly calculating the number of rows in the compressed matrix
    int size = compressed.size();
    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            cout << "Row:    ";
        }
        else if (j == 1) {
            cout << "Column: ";
        }
        else {
            cout << "Value:  ";
        }
        for (int i = 0; i < size; i++) {
            cout << compressed[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
