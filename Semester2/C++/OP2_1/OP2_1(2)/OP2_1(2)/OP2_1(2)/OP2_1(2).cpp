#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//  doc:
//      Function for search max element in one-dimensional a array
//  args:
//      T* array (different types): takes one-dimensional array
//      size (int): takes size array which select the user
//  return:
//      maxElement(T types): max element in T* array
//
template <typename T>
T get_max_element_one_dimen(T* array, int size)
{

    T maxElement = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > maxElement)
        {
            maxElement = array[i];
        }
    }
    return maxElement;
}

//  doc:
//      Function for search max element in two-dimensional a array
//  args:
//      T** array (different types): takes two-dimensional array
//      size (int): takes size array which select the user
//  return:
//      maxElement(T types): max element in T** array
//
template <typename T>
T get_max_element_two_dimen(T** array, int size)
{

    T max_element = array[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] > max_element)
            {
                max_element = array[i][j];
            }
        }
    }
    return max_element;
}

//  doc:
//      Function for search max element in three-dimensional a array
//  args:
//      T*** array (different types): takes three-dimensional array
//      size (int): takes size array which select the user
//  return:
//      maxElement(T types): max element in T*** array
//
template <typename T>
T get_max_element_three_dimen(T*** array, int size)
{
    T max_element = array[0][0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int z = 0; z < size; z++) {
                if (array[i][j][z] > max_element)
                {
                    max_element = array[i][j][z];
                }
            }
        }
    }
    return max_element;
}

//  doc:
//      Function for print array and output the max element in the array 
//  args:
//      T* array (different types): takes one-dimensional array
//      size (int): takes size array which select the user
//  
template <typename T>
void print_result_one_dimen(T* array, int size)
{
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(8) << array[i];
    }

    T max_element = static_cast<T>(get_max_element_one_dimen(array, size));

    cout << "\nThe maximum element in the array is " << max_element << endl;
}

//  doc:
//      Function for print array and output the max element in the array 
//  args:
//      T** array (different types): takes two-dimensional array
//      size (int): takes size array which select the user
//  
template <typename T>
void print_result_two_dimen(T** array, int size)
{
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(8) << array[i][j];
        }
        cout << endl;
    }

    T max_element = static_cast<T>(get_max_element_two_dimen(array, size));

    cout << "\nThe maximum element in the array is " << max_element << endl;
}

//  doc:
//      Function for print array and output the max element in the array 
//  args:
//      T*** array (different types): takes three-dimensional array
//      size (int): takes size array which select the user
//  
template <typename T>
void print_result_three_dimen(T*** array, int size)
{
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int z = 0; z < size; z++) {
                cout << setw(8) << array[i][j][z];
            }
            cout << endl;
        }
        cout << endl;
    }

    T max_element = static_cast<T>(get_max_element_three_dimen(array, size));

    cout << "\nThe maximum element in the array is " << max_element << endl;
}


//  doc:
//      Function for create one-dimensional array. 
//      Question in the console -> the user choice manual and random way filling array ->
//      -> m - manual way filling / r - random filling
//  args:
//      size (int): takes size array which select the user
//  return:
//      array(T types): result array
//  
template <typename T>
T* create_array_one_dimen(int size)
{
    char choice;
    int separator;

    T* array = new T[size];

    while (true)
    {
        cout << "\nHow do you want to create the array? \nm - manual\nr - random\n\t>>>"; cin >> choice;

        // if manual input
        if (choice == 'm')
        {
            for (int i = 0; i < size; i++) {
                cout << i << " - ";
                cin >> array[i];
            }
            break;
        }
        // if random geniration
        else if (choice == 'r')
        {
            // find type. If T is char then divide by one, else divide by 1000
            if (sizeof(T) == 1)
                separator = 1;
            else
                separator = 1000;

            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                array[i] = static_cast<T>(rand()) / separator;
            }
            break;
        }
    }
    return array;
}


//  doc:
//      Function for create two-dimensional array. 
//      Question in the console -> the user choice manual and random way filling array ->
//      -> m - manual way filling / r - random filling
//  args:
//      size (int): takes size array which select the user
//  return:
//      array(T types): result array
//  
template <typename T>
T** create_array_two_dimen(int size)
{
    char choice;
    int separator;

    T** array = new T* [size];
    for (int i = 0; i < size; i++) {
        array[i] = new T [size];
    }


    while (true)
    {
        cout << "\nHow do you want to create the array? \nm - manual\nr - random\n\t>>>"; cin >> choice;

        // if manual input
        if (choice == 'm')
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) {
                    cout << i << ", " << j << " - ";
                    cin >> array[i][j];
                }

            break;
        }
        // if random geniration
        else if (choice == 'r')
        {
            // find type. If T is char then divide by one, else divide by 1000
            if (sizeof(T) == 1)
                separator = 1;
            else
                separator = 1000;

            srand(time(NULL));
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    array[i][j] = static_cast<T>(rand()) / separator;

            break;
        }
    }
    return array;
}


//  doc:
//      Function for create three-dimensional array. 
//      Question in the console -> the user choice manual and random way filling array ->
//      -> m - manual way filling / r - random filling
//  args:
//      size (int): takes size array which select the user
//  return:
//      array(T types): result array
//  
template <typename T>
T*** create_array_three_dimen(int size)
{
    char choice;
    int separator;

    T*** array = new T** [size];
    for (int i = 0; i < size; i++) {
        array[i] = new T*[size];

        for (int j = 0; j < size; j++)
            array[i][j] = new T[size];
    }

    while (true)
    {
        cout << "\nHow do you want to create the array ? \nm - manual\nr - random\n\t >> >"; cin >> choice;

        // if manual input
        if (choice == 'm')
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    for (int z = 0; z < size; z++)
                    {
                        cout << i << ", " << j << " - ";
                        cin >> array[i][j][z];
                    }

            break;
        }
        // if random geniration
        else if (choice == 'r')
        {
            // find type. If T is char then divide by one, else divide by 100 
            if (sizeof(T) == 1)
                separator = 1;
            else
                separator = 1000;

            srand(time(NULL));
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    for (int z = 0; z < size; z++)
                        array[i][j][z] = static_cast<T>(rand()) / separator;
                  
            break;
        }
    }
    return array;
}


int main()
{
    /*
    array_type - type array (one-dimensional, two-dimensional, three-dimensional) which select the user in the console
    size - size array
    type - type array (integer, double, char) which select in the console
    */
    int array_type, size, type;

    while (true)
    {
        cout << "What type of array do you want to create? \n1 - one-dimensional \n2 - two-dimensional \n3 - three-dimensional\n\t>>> ";  cin >> array_type;

        cout << "\nWhat type of array do you want to create? \n1 - int\n2 - double\n3 - char\n\t>>> "; cin >> type;
        cout << "\nHow many elements does the array have? "; cin >> size;

        if (array_type == 1)      // if the user selected a one-dimensional
        {
            if (type == 1) //if int
                print_result_one_dimen(create_array_one_dimen<int>(size), size);

            else if (type == 2) // if double
                print_result_one_dimen(create_array_one_dimen<double>(size), size);

            else if (type == 3) // if char
                print_result_one_dimen(create_array_one_dimen<char>(size), size);

        }
        else if (array_type == 2)     // if the user selected a two-dimensional
        {
            if (type == 1) //if int
                print_result_two_dimen(create_array_two_dimen<int>(size), size);

            else if (type == 2) // if double
                print_result_two_dimen(create_array_two_dimen<double>(size), size);

            else if (type == 3) // if char
                print_result_two_dimen(create_array_two_dimen<char>(size), size);
        }
        else if (array_type == 3)     // if the user selected a three-dimensional
        {
            if (type == 1) //if int
                print_result_three_dimen(create_array_three_dimen<int>(size), size);

            else if (type == 2) // if double
                print_result_three_dimen(create_array_three_dimen<double>(size), size);

            else if (type == 3) // if char
                print_result_three_dimen(create_array_three_dimen<char>(size), size);
        }
        else {
            system("cls");  // Сlear console
            continue;   // Back to the top
        }

        cout << "\n\nDouble-press any key to start again!\n";
        system("PAUSE");
        system("PAUSE");
        system("cls");   // Сlear console
    }
    return 0;
}