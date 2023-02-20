#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T max_element_on_diagonal(T** matrix, int rows, int cols)
{
    int size = rows < cols ? rows : cols;
    T max_element = matrix[0][0];
    for (int i = 1; i < size; i++)
    {
        if (matrix[i][i] > max_element)
        {
            max_element = matrix[i][i];
        }
    }
    return max_element;
}

template <typename T>
T min_element_on_diagonal(T** matrix, int rows, int cols)
{
    int size = rows < cols ? rows : cols;
    T min_element = matrix[0][0];
    for (int i = 1; i < size; i++)
    {
        if (matrix[i][i] < min_element)
        {
            min_element = matrix[i][i];
        }
    }
    return min_element;
}

template <typename T>
void sort_rows_in_ascending_order(T** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            for (int k = j + 1; k < cols; k++)
            {
                if (matrix[i][k] < matrix[i][j])
                {
                    T temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
}

template <typename T>
void sort_columns_in_descending_order(T** matrix, int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows - 1; j++)
        {
            for (int k = j + 1; k < rows; k++)
            {
                if (matrix[k][i] > matrix[j][i])
                {
                    T temp = matrix[j][i];
                    matrix[j][i] = matrix[k][i];
                    matrix[k][i] = temp;
                }
            }
        }
    }
}

template <typename T>
void printMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(8) << matrix[i][j];
        }
        cout << endl;
    }
}


template<typename T>
T** create_random_matrix(int rows, int columns)
{
    int counstant;

    int type_T = sizeof(T);
    switch (type_T)
    {
    case 1:  // if char
        counstant = 1;
        break;
    case 4:  // if int
        counstant = 1000;
        break;
    case 8:  //if double
        counstant = 1000;
        break;
    default:
        counstant = 0;
        break;
    }

    srand(time(nullptr));
    T** matrix = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[columns];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = static_cast<T>(rand()) / counstant;
        }
    }

    return matrix;
}

template <typename T>
void result_info(T** matrix, int row, int colm)
{
    cout << "\nMax element on diagonal: " << max_element_on_diagonal(matrix, row, colm) << endl;
    cout << "Min element on diagonal: " << min_element_on_diagonal(matrix, row, colm) << endl;

    cout << "\nSorted rows in ascending order: " << endl;
    sort_rows_in_ascending_order(matrix, row, colm);
    printMatrix(matrix, row, colm);

    cout << "\nSorted columns in descending order:" << endl;
    sort_columns_in_descending_order(matrix, row, colm);
    printMatrix(matrix, row, colm);

    cout << "\n\n";
}

int main()
{
    /*
    * printMatrix - function that shows the matrix
    * result_info - shows all necessary parameters.
                    Max/min element into matrix and
                    sort element into matrix descending/ascending
      
    */
    
    int ROWS, COLUMS;
    cout << "Rows matrix: "; cin >> ROWS;
    cout << "Colums matrix: "; cin >> COLUMS;

    //int example
    int** int_matrix = create_random_matrix<int>(ROWS, COLUMS);

    cout << "--------------------------------------";
    cout << "\n\nStart random matrix INTEGER:" << endl;
    printMatrix(int_matrix, ROWS, COLUMS);
    result_info(int_matrix, ROWS, COLUMS);

    //double example
    double** double_matrix = create_random_matrix<double>(ROWS, COLUMS);

    cout << "--------------------------------------";
    cout << "\n\nStart random matrix DOUBLE:" << endl;
    printMatrix(double_matrix, ROWS, COLUMS);
    result_info(double_matrix, ROWS, COLUMS);

    //char example
    char** char_matrix = create_random_matrix<char>(ROWS, COLUMS);

    cout << "--------------------------------------";
    cout << "\n\nStart random matrix CHAR:" << endl;
    printMatrix(char_matrix, ROWS, COLUMS);
    result_info(char_matrix, ROWS, COLUMS);

    return 0;
}