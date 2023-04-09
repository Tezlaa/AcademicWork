#include <iostream>
#include <fstream>

using namespace std;


int main() {
    int num;
    int count = 0;

    ifstream file("data.bin", ios::binary); // open file for reading

    while (file.read((char*)&num, sizeof(num))) { // read number from file
        cout << num << " "; // print number to screen
        if (num % 2 != 0) { // if number odd
            num *= 2; // doubled number 
            count++;
        }
    }

    file.close(); // close file

    cout << "\n\nCount: " << count << endl;

    return 0;
}