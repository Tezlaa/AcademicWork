#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& array) {
    int n = array.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}

// Counting Sort
vector<int> countingSort(vector<int>& array) {
    int maxElement = *max_element(array.begin(), array.end());
    int countArrayLength = maxElement + 1;
    vector<int> countArray(countArrayLength, 0);

    for (int el : array) {
        countArray[el]++;
    }

    for (int i = 1; i < countArrayLength; i++) {
        countArray[i] += countArray[i - 1];
    }

    vector<int> outputArray(array.size());
    for (int i = array.size() - 1; i >= 0; i--) {
        int currentEl = array[i];
        countArray[currentEl]--;
        int newPosition = countArray[currentEl];
        outputArray[newPosition] = currentEl;
    }

    return outputArray;
}

// Merge Sort
void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    srand(time(0));

    for (int lengthArray = 50000; lengthArray <= 1050000; lengthArray += 50000) {
        vector<int> array(lengthArray);
        for (int i = 0; i < lengthArray; i++) {
            array[i] = rand() % 100001;
        }

        clock_t startTime = clock();
        bubbleSort(array);

        double elapsedTime = double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << lengthArray << " - " << elapsedTime << endl;
    }

    cout << "bubble end" << endl;

    return 0;
}
