#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string surname;
    int exams[4];
};

int create_file() {
    srand(time(NULL));

    int count_students;
    string surname;

    ofstream file("students.txt");

    cout << "Count students: "; cin >> count_students;

    string* surnames = new string[count_students];

    for (int i = 0; i < count_students; i++) {
        cout << "Write surname for " << i + 1 << " student: ";
        cin >> surname;
        surnames[i] = surname;
    }

    for (int i = 0; i < count_students; i++) { // Write the result on the exam random numbers
        file << surnames[i] << " ";
        for (int j = 0; j < 4; j++) {
            file << rand() % 2 << " ";
        }
        file << endl;
    }

    file.close();

    return 0;
}

int main() {
    Student student; // struct with Student
    bool allPassed; // passed exam

    create_file(); // create random scores for exam
    ifstream file("students.txt");
    while (file >> student.surname) {
        allPassed = true; // passed true by default
        for (int i = 0; i < 4; i++) { // check all exam
            file >> student.exams[i];
            if (student.exams[i] == 0) { // if exam is 0
                allPassed = false;
            }
        }
        if (allPassed) { // if all exam passed than show surname student
            cout << student.surname << endl;
        }
    }

    file.close();  //close file

    return 0;
}