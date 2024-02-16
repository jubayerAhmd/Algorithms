#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void transpose(int mat[][MAX_SIZE], int trans[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            trans[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[j][k];
            }
        }
    }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows1, cols1;
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> rows1 >> cols1;

    int mat1[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> mat1[i][j];
        }
    }

    int rows2, cols2;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible. Number of columns of the first matrix must be equal to the number of rows of the second matrix." << endl;
        return 1;
    }

    int mat2[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> mat2[i][j];
        }
    }

    int transMat1[MAX_SIZE][MAX_SIZE];
    transpose(mat1, transMat1, rows1, cols1);

    int transMat2[MAX_SIZE][MAX_SIZE];
    transpose(mat2, transMat2, rows2, cols2);

    int addResult[MAX_SIZE][MAX_SIZE];
    addMatrices(transMat1, transMat2, addResult, cols1, rows1);

    int subtractResult[MAX_SIZE][MAX_SIZE];
    subtractMatrices(transMat1, transMat2, subtractResult, cols1, rows1);

    int multiplyResult[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(transMat1, transMat2, multiplyResult, cols1, rows1, cols2, rows2);

    cout << "Transpose of the first matrix:" << endl;
    displayMatrix(transMat1, cols1, rows1);

    cout << "Transpose of the second matrix:" << endl;
    displayMatrix(transMat2, cols2, rows2);

    cout << "Addition of transpose matrices:" << endl;
    displayMatrix(addResult, cols1, rows1);

    cout << "Subtraction of transpose matrices:" << endl;
    displayMatrix(subtractResult, cols1, rows1);

    cout << "Multiplication of transpose matrices:" << endl;
    displayMatrix(multiplyResult, cols1, cols2);

    return 0;
}
