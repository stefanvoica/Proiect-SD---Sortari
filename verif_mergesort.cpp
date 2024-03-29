#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

void readNumbers (const string& filename, vector<int>& numbers) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
}

// Funcție care afișează vectorul
void printVector(const vector<int>& numbers) {
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

// Funcție care verifică dacă un vector este sortat corect
bool isSorted(const vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[i - 1]) {
            return false;
        }
    }
    return true;
}

// Funcție care sortează un vector folosind algoritmul MergeSort
void mergeSort(vector<int>& numbers) {
    if (numbers.size() <= 1) {
        return;
    }

    vector<int> left, right;
    int mid = numbers.size() / 2;

    for (int i = 0; i < mid; ++i) {
        left.push_back(numbers[i]);
    }

    for (int i = mid; i < numbers.size(); ++i) {
        right.push_back(numbers[i]);
    }

    mergeSort(left);
    mergeSort(right);

    int i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            numbers[k++] = left[i++];
        } else {
            numbers[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        numbers[k++] = left[i++];
    }

    while (j < right.size()) {
        numbers[k++] = right[j++];
    }
}

int main() {
    const int num_tests = 8;
    const string test_names[] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt",
                                  "test5.txt", "test6.txt", "test7.txt", "test8.txt"};

    for (int i = 0; i < num_tests; ++i) {
        // Citirea numerelor din fișierul de intrare
        vector<int> numbers;
        readNumbers(test_names[i], numbers);
        cout << "Read numbers for test " << i + 1 << ": ";
        printVector(numbers);

        // Sortați vectorul folosind MergeSort
        auto start = chrono::high_resolution_clock::now();
        mergeSort(numbers);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        // Afișați vectorul sortat
        cout << "Sorted numbers for test " << i + 1 << ": ";
        printVector(numbers);

        // Verificați dacă vectorul este sortat corect
        if (isSorted(numbers)) {
            cout << "Test " << i + 1 << " sortat corect." << endl;
        } else {
            cout << "Eroare: Test " << i + 1 << " nu este sortat corect!" << endl;
        }

        // Afișați timpul de sortare
        cout << "MergeSort time for test " << i + 1 << ": " << elapsed_seconds.count() << " seconds" << endl;
    }

    return 0;
}
