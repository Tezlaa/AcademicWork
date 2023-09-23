#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;


void countingSort(int arr[], int n) {
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    int* countArray = new int[maxElement + 1]();

    for (int i = 0; i < n; i++) {
        countArray[arr[i]]++;
    }

    int outputIndex = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (countArray[i] > 0) {
            arr[outputIndex] = i;
            outputIndex++;
            countArray[i]--;
        }
    }

    delete[] countArray;
}


template <typename T>
int linearSearch(T* arr, int length, T target) {
    for (int i = 0; i < length; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int binarySearch(T* arr, int length, T target) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
int interpolationSearch(T* arr, int length, T target) {
    int left = 0;
    int right = length - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            left = pos + 1;
        }
        else {
            right = pos - 1;
        }
    }
    return -1;
}

template <typename T>
int binarySearchFromEdge(T* arr, int length, T target) {
    int left = 0;
    int right = length - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}


void generateRandomArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % length;
    }
}


int getRandomElementFromArray(int arr[], int length) {
    return arr[length / 2];
}


int main() {
    srand(time(0));

    for (int lengthArray = 50000; lengthArray <= 1000000; lengthArray += 50000) {
        int* randomArray = new int[lengthArray];
        generateRandomArray(randomArray, lengthArray);
        int target = getRandomElementFromArray(randomArray, lengthArray);

        auto start = chrono::high_resolution_clock::now();
        int result = interpolationSearch(randomArray, lengthArray, target);
        auto end = chrono::high_resolution_clock::now();
        
        double elapsedTime = chrono::duration<double>(end - start).count();
        cout << lengthArray << " - " << fixed << setprecision(8) << elapsedTime << endl;

        delete[] randomArray;
    }

    cout << "end" << endl;
    return 0;
}
