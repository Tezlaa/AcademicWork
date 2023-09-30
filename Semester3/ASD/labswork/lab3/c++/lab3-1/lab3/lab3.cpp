#include <iostream>

using namespace std;


class StackArray
{
private:
	int* array;
	int size;
	int lastIndex;

public:
	StackArray(int size = 5) {
		size = size;
		array = new int[size];
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


	int getTopElement() {
		if (isArrayEmpty()) {
			cout << "Stack is empty!" << endl;
			return -1;
		}
		return array[lastIndex];
	}

	void modificationArray(int newSize) {
		int* modify_array = new int[newSize];
		size = newSize;

		for (int i = 0; i <= lastIndex; ++i) {
			modify_array[i] = array[i];
		}
		delete[] array;
		array = modify_array;
	}

	void add(int element) {
		if (lastIndex == size - 1) {
			modificationArray(2 * size);
		}
		array[++lastIndex] = element;
	}

	int pop() {
		if (isArrayEmpty()) {
			cout << "Stack is empty!" << endl;
			return -1;
		}
		return array[lastIndex--];
	}
};

int main() {
	StackArray stack;

	stack.add(1);
	stack.add(2);
	stack.add(3);

	cout << "Stack size: " << stack.getSize() << endl;
	while (!stack.isArrayEmpty()) {
		cout << "Top of the stack: " << stack.pop() << endl;
	}

	return 0;
}
