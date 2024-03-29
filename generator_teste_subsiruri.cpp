/*
In acest program se genereaza teste in care elementele de pe indicii pari sunt sortate crescator,
iar cei de pe indicii impari sunt sortate descrestor.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
const int dim_max = 1000000;

int v[dim_max + 1];


void generateTest(const string& filename, int num_numbers, int max_value) {
    ofstream file(filename);
    srand(time(0));
    file << num_numbers << '\n';

    for (int i = 0; i < num_numbers; i++)
        v[i] = rand() % (max_value + 1);
    sort(v, v + num_numbers);
    for (int i = 0, j = num_numbers - 1; i < j; i++, j--)
        file << v[i] << ' ' << v[j];
    if (num_numbers % 2 == 1)
        file << v[num_numbers / 2];
    file.close();
}

int main() {
    const int num_tests = 10;
    int num_numbers[] = {1000, 10000, 10000, 100000, 100000, 100000, 10000, 1000000, 10000000, 100000000};
    int max_values[] = {1000000, 1000, 1000000, 100, 1000000, 100000000, 1000000, 1000000000, 10000000, 1000000000};

    for (int i = 0; i < num_tests; ++i)
    {
        string filename = "testsubsir" + to_string(i + 1) + ".txt";
        generateTest(filename, num_numbers[i], max_values[i]);
    }
    cout << "S-au generat toate testele cu succes!" << '\n';
    return 0;
}

