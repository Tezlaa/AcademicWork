#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Boat {
    string name;
    double speed;
    int capacity;
};

// doc:
//     function to fill struct Boat
// args:
//    & b (Boat types): takes struct which fills
void fillBoat(Boat& b)
{
    cout << "Enter boat name: ";
    getline(cin, b.name);

    cout << "Enter boat speed (in knots): "; cin >> b.speed;
    cout << "Enter boat capacity: "; cin >> b.capacity;

    cin.ignore(); // to clear the input buffer
}

// doc:
//     function for print all table, where id - "primary key",
//                                         Name - string name in struct Boat,
//                                         Speed - double speed in struct Boat
//                                         Capacity - int capacity in struct Boat
// args:
//    boats[] (Boat types): takes struct with which takes data
void print_table(Boat boats[], int n)
{
    // Print table header
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Speed" << setw(15) << "Capacity" << endl;
    cout << setfill('-') << setw(55) << "-" << endl;
    cout << setfill(' ');

    // Print table body
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << (i + 1) << setw(20) << boats[i].name << setw(10) << boats[i].speed << setw(15) << boats[i].capacity << endl;
    }
    cout << endl << setfill('-') << setw(55) << "-" << endl;
}

// doc:
//     func which search in struct Boat by name
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
//    name (string types): the name by which the search
// return:
//    i (index by which the item was found): if have item
//    -1:  if name not found
int search_by_name(Boat boats[], int n, string name)
{
    for (int i = 0; i < n; i++) {
        if (boats[i].name == name) {
            return i;
        }
    }
    return -1; // if name not found
}

// doc:
//     func which search in struct Boat by double
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
//    speed (double types): the speed by which the search
// return:
//    i (index by which the item was found): if have item
//    -1: if speed not found
int search_by_speed(Boat boats[], int n, double speed)
{
    for (int i = 0; i < n; i++) {
        if (boats[i].speed == speed) {
            return i;
        }
    }
    return -1; // if speed not found
}


// doc:
//     func which search in struct Boat by double
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
//    capacity (int types): the capacity by which the search
// return:
//    i (index by which the item was found): if have item
//    -1: if capacity not found
int search_by_capacity(Boat boats[], int n, int capacity)
{
    for (int i = 0; i < n; i++) {
        if (boats[i].capacity == capacity) {
            return i;
        }
    }
    return -1; // if capacity not found
}

// for bubble sort by name
bool compareByName(const Boat& b1, const Boat& b2)
{
    return b1.name < b2.name;
}

// for bubble sort by speed
bool compareBySpeed(const Boat& b1, const Boat& b2)
{
    return b1.speed < b2.speed;
}

// for bubble sort by capacity
bool compareByCapacity(const Boat& b1, const Boat& b2)
{
    return b1.capacity < b2.capacity;
}

// doc:
//     func that sorted boats by selected option
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
//    sort_option (int types): The argument responsible for sorting the type
//                             1 - bubble sort by name
//                             2 - bubble sort by speed
//                             3 - bubble sort by capacity
void sort_boats(Boat boats[], int n, int sort_option)
{
    switch (sort_option)
    {
    case 1: // bubble sort by name
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++) {
                if (compareByName(boats[j + 1], boats[j])) {
                    swap(boats[j], boats[j + 1]);
                }
            }
    }
    break;
    case 2: // bubble sort by speed
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (compareBySpeed(boats[j + 1], boats[j])) {
                    swap(boats[j], boats[j + 1]);
                }
            }
        }
        break;
    case 3: // bubble sort by capacity
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (compareByCapacity(boats[j + 1], boats[j])) {
                    swap(boats[j], boats[j + 1]);
                }
            }
        }
        break;
    default:
        cout << "Invalid option. Sort aborted." << endl;
        break;
    }
}


// doc:
//    func, which shows a menu with a choice of the type of search method
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
void search_menu(Boat boats[], int n)
{
    int select_type_search, name_index, search_index, capacity_index, search_capacity;
    double  search_speed;
    string search_name;

    while (true)
    {
        system("cls");
        print_table(boats, n);

        cout << "\tBy which to search\n\n1 - search by name\t2 - search by speed\t3 - search by capacity\t0 - exit\n\n >>> "; cin >> select_type_search;
        if (select_type_search == 1)
        {
            cin.ignore(); // to clear the input buffer
            cout << "Enter name to search for: ";
            getline(cin, search_name);

            name_index = search_by_name(boats, n, search_name);
            if (name_index != -1) {
                cout << "Boat fou_bd_: " << boats[name_index].name << ", " << boats[name_index].speed << " knots, " << boats[name_index].capacity << " persons" << endl;
            }
            else {
                cout << "Boat not found." << endl;
            }
        }
        else if (select_type_search == 2)
        {
            cout << "Enter speed to search for: "; cin >> search_speed;
            search_index = search_by_speed(boats, n, search_speed);
            if (search_index != -1) {
                cout << "Boat found: " << boats[search_index].name << ", " << boats[search_index].speed << " knots, " << boats[search_index].capacity << " persons" << endl;
            }
            else {
                cout << "Boat not found." << endl;
            }
        }
        else if (select_type_search == 3)
        {
            cout << "Enter capacity to search for: "; cin >> search_capacity;
            capacity_index = search_by_capacity(boats, n, search_capacity);
            if (capacity_index != -1) {
                cout << "Boat found: " << boats[capacity_index].name << ", " << boats[capacity_index].speed << " knots, " << boats[capacity_index].capacity << " persons" << endl;
            }
            else {
                cout << "Boat not found." << endl;
            }
        }
        else if (select_type_search == 0)
        {
            return;
        }
        system("pause");
    }
}

// doc:
//    func in which choice index to change and changing him
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
void edit_menu(Boat boats[], int n)
{
    int edit_index;

    cout << "Enter index of boat to edit: "; cin >> edit_index;
    cin.ignore(); // to clear the input buffer
    if (edit_index >= 0 && edit_index < n) {
        cout << "Editing boat #" << edit_index + 1 << ":" << endl;
        Boat& editBoat = boats[edit_index];
        fillBoat(editBoat);
        cout << "Boat #" << edit_index + 1 << " updated." << endl;
    }
    else {
        cout << "Invalid index. Edit aborted." << endl;
    }
}

// doc:
//    func in which selecting the sorting type option and sorting
// args:
//    boats[] (Boat types): takes struct with which takes data
//    n (int types): how many elements are in the struct Boat
void sort_menu(Boat boats[], int n)
{
    int sort_option;

    system("cls");
    print_table(boats, n);
    cout << "\tEnter sort option\n1 - name\t2 - speed\t3 - capacity\n\n >>>"; cin >> sort_option;
    sort_boats(boats, n, sort_option);
}

int main()
{
    int menu_choice, n;

    cout << "Enter number of boats: "; cin >> n;

    cin.ignore(); // to clear the input buffer
    Boat* boats = new Boat[n];

    for (int i = 0; i < n; i++) {
        cout << "Boat #" << i + 1 << ":" << endl;
        fillBoat(boats[i]);
    }

    cout << endl << "Boat list:" << endl;
    while (true)
    {
        system("cls");
        print_table(boats, n);
        cout << "1 - search\t2 - edit boat\t3 - sort\n\n >>> "; cin >> menu_choice;
        if (menu_choice == 1)   // if search
        {
            search_menu(boats, n);
        }
        else if (menu_choice == 2)  // if edit
        {
            edit_menu(boats, n);
        }
        else if (menu_choice == 3)  // if sort
        {
            sort_menu(boats, n);
        }
    }

    delete[] boats; // clear memory
    return 0;
}