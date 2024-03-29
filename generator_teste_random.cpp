#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateTest(const string& filename, int num_numbers, int max_value) {
    ofstream file(filename);
    srand(time(0));
    file << num_numbers << '\n';
    for (int i = 0; i < num_numbers; ++i)
        file << rand() % (max_value + 1) << ' ';
    file.close();
}

int main() {
    const int num_tests = 8;
    int num_numbers[] = {1000, 10000, 10000, 100000, 100000, 100000, 10000, 1000000};
    int max_values[] = {1000000, 1000, 1000000, 100, 1000000, 100000000, 1000000, 1000000000};

    for (int i = 0; i < num_tests; ++i)
    {
        string filename = "test" + to_string(i + 1) + ".txt";
        generateTest(filename, num_numbers[i], max_values[i]);
    }
    cout << "S-au generat toate testele cu succes!" << '\n';
    return 0;
}
