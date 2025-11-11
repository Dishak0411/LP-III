#include <bits/stdc++.h>
using namespace std;

// Randomized Lomuto Partition
int randomizedPartition(vector<int> &arr, int low, int high, int &comparisons, int &swaps) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // move random pivot to end
    swaps++;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

// Deterministic Lomuto Partition
int deterministicPartition(vector<int> &arr, int low, int high, int &comparisons, int &swaps) {
    int pivot = arr[high];  // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
        comparisons++;
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

// Randomized Quick Sort (Lomuto)
void randomizedQuickSort(vector<int> &arr, int low, int high, int &comparisons, int &swaps) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high, comparisons, swaps);
        randomizedQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        randomizedQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

// Deterministic Quick Sort (Lomuto)
void deterministicQuickSort(vector<int> &arr, int low, int high, int &comparisons, int &swaps) {
    if (low < high) {
        int pivotIndex = deterministicPartition(arr, low, high, comparisons, swaps);
        deterministicQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        deterministicQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// 🔹 Main Function
int main() {
    srand(time(0));
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> arrDet = arr, arrRand = arr;

    int ch;
    cout << "\n1. Deterministic Quick Sort\n2. Randomized Quick Sort\nEnter your choice: ";
    cin >> ch;

    int comparisons = 0, swaps = 0;
bb
    switch (ch) {
        case 1:
            cout << "\nOriginal array: ";
            printArray(arrDet);
            deterministicQuickSort(arrDet, 0, n - 1, comparisons, swaps);
            cout << "Sorted array: ";
            printArray(arrDet);
            cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
            break;

        case 2:
            cout << "\nOriginal array: ";
            printArray(arrRand);
            randomizedQuickSort(arrRand, 0, n - 1, comparisons, swaps);
            cout << "Sorted array: ";
            printArray(arrRand);
            cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
            break;

        default:
            cout << "Exiting..." << endl;
            break;
    }

    return 0;
}
