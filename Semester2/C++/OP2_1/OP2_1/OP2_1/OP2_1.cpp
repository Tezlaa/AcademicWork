#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T max_element_on_diagonal(T** matrix, int rows, int cols)
{
    // function for search max element on diagonal
    int size = rows < cols ? rows : cols; // if rows < cols then size = rows else size = cols 
    
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
    // function for search min element on diagonal
    int size = rows < cols ? rows : cols;  // if rows < cols then size = rows else size = cols 

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
    // sort rows
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
    // sort columns
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
void printMatrix(T** matrix, int rows, int cols)
{
    // function that shows the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(8) << matrix[i][j];
        }
        cout << endl;
    }
}

template<typename T>
T** create_matrix(int rows, int columns, int way)
{
    // way: 1- random matrix, 2- input matrix
    // function creating input matrix

    int counstant;
    int type_T = sizeof(T);
    switch (type_T)
    {
    case 1:  // if type T is char
        counstant = 1;
        break;
    case 4:  // if type T is int
        counstant = 1000;
        break;
    case 8:  // if type T is double
        counstant = 1000;
        break;
    default:
        counstant = 0;
        break;
    }

    // create matrix
    T** matrix = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[columns];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
        {
            if (way == 1)   // if way_writing selected 1 (generation)
            {
                matrix[i][j] = static_cast<T>(rand()) / counstant;
            }
            else if (way == 2)   // if way_writing selected 2 (writing)
            {
                cout << i << ", " << j << " - "; cin >> matrix[i][j];
            }
        }
    }
    return matrix;
}

template <typename T>
void result_info(T** matrix, int row, int colm)
{
    cout << "Your matrix: \n";
    printMatrix(matrix, row, colm);
    
    cout << "\n---------------------------------------";
    cout << "\n\nMax element on diagonal: " << max_element_on_diagonal(matrix, row, colm) << endl;
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
    rows - row matrix,
    cols - columns matrix, 
    matrix_type - type matix(char, int, double),
    way_writing - writing type(hand write or random matrix)
    */
    int rows, cols, matrix_type, way_writing;

    while (true)
    {
        cout << "Enter the number of rows in the matrix: "; cin >> rows;
        cout << "Enter the number of columns in the matrix: "; cin >> cols;
        cout << "\nEnter the type of the matrix:\n1 - char\n2 - int\n3 - double:   >>> "; cin >> matrix_type;
        cout << "\nEnter the way writing matrix:\n1 - generation\n2 - input:\t>>> "; cin >> way_writing;

        if (matrix_type == 1)  // if char
        {
            char** matrix = create_matrix<char>(rows, cols, way_writing);
            result_info(matrix, rows, cols);
        }
        else if (matrix_type == 2)  // if int
        {
            int** matrix = create_matrix<int>(rows, cols, way_writing);
            result_info(matrix, rows, cols);
        }
        else if (matrix_type == 3)  // in double
        {
            double** matrix = create_matrix<double>(rows, cols, way_writing);
            result_info(matrix, rows, cols);
        }
        else // if wrong
        {
            cout << "Invalid matrix type." << endl;
            break;
        }
        
        // pause and clear console for reboot
        system("PAUSE");
        system("cls");
    }
    return 0;
}