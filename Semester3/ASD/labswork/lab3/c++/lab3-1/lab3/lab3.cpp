#include <iostream>

using namespace std;


template <typename T>
class StackArray {
private:
    T* array;
    int capacity;
    int lastIndex;

public:
    StackArray(int size = 5) {
        capacity = size;
        array = new T[capacity];
        lastIndex = -1;
    }

    ~StackArray() {
        delete[] array;
    }

    bool isArrayEmpty() {
        return lastIndex == -1;
    }

    int getSize() {
        return lastIndex + 1;
    }

    T getTopElement() {
        if (isArrayEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return array[lastIndex];
    }

    void modificationArray(int newSize) {
        T* modify_array = new T[newSize];
        capacity = newSize;

        for (int i = 0; i <= lastIndex; ++i) {
            modify_array[i] = array[i];
        }
        delete[] array;
        array = modify_array;
    }

    void add(const T& element) {
        if (lastIndex == capacity - 1) {
            modificationArray(2 * capacity);
        }
        array[++lastIndex] = element;
    }

    T pop() {
        if (isArrayEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return array[lastIndex--];
    }
};


bool validInstance(string inctance) {
    int stringLength = inctance.length();
    int errorPosition = -1;
    StackArray<char> brackets;

    if (inctance[stringLength - 1] != ';') {
        errorPosition = stringLength;
    }

    for (int i = 0; i <= stringLength; i++) {
        char currentChar = inctance[i];
        char cC = currentChar;

        if (cC == '(' ||
            cC == '{' ||
            cC == '[') {

            brackets.add(cC);
        }
        else if (
            cC == ')' ||
            cC == '}' ||
            cC == ']') {
            if (brackets.isArrayEmpty()) {
                errorPosition = i;
                break;
            }
            char bracketFromStack = brackets.getTopElement();
            char bFS = bracketFromStack;

            brackets.pop();
        
            if (cC == ')' && bFS != '(' ||
                cC == '}' && bFS != '{' ||
                cC == ']' && bFS != '[') {

                errorPosition = i;
                break;
            }

        }
    }

    if (brackets.isArrayEmpty() && errorPosition == -1) {
        cout << endl << inctance << "\nBrackets are placed correctly." << endl;
    }
    else {
        cout << endl << inctance << "\nBrackets are not placed correctly." << endl;
        if (errorPosition != -1) {
            cout << "Error in position " << errorPosition << ": " << inctance.substr(0, errorPosition + 1) << endl;
        }
    }

    return brackets.isArrayEmpty() && errorPosition == -1;
}


int main3() {
    StackArray<char> intStack;
    intStack.add('{');
    intStack.add('{');
    intStack.add('}');

    cout << "Stack size: " << intStack.getSize() << endl;
    while (!intStack.isArrayEmpty()) {
        cout << "Top of the stack: " << intStack.pop() << endl;
    }

    StackArray<string> stringStack;
    stringStack.add("Hello");
    stringStack.add("World");

    cout << "\nStack size: " << stringStack.getSize() << endl;
    while (!stringStack.isArrayEmpty()) {
        cout << "Top of the stack: " << stringStack.pop() << endl;
    }

    return 0;
}


int main() {

    string instance1 = "({x-y-z}*[x+2y]-(z+4x));";
    string instance2 = "([x-y-z}*[x+2y)-{z+4x)].";
    string instance3 = "[(((())))]()[]{};";

    validInstance(instance1);
    validInstance(instance2);
    validInstance(instance3);
}