#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

void generateTest(const string& filename, int num_numbers, int min_value, int max_value) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min_value, max_value);
    ofstream file(filename);
    srand(time(0));
    file << num_numbers << ' ' << max_value << '\n';
    for (int i = 0; i < num_numbers; ++i)
        file << dis(gen) << ' ';
    file.close();
}

int main() {
    int num_numbers[] = {1000, 1000, 1000, 1000, 1000, 1000,
                    10000, 10000,  10000, 10000, 10000, 10000,
                    100000, 100000,  100000, 100000, 100000, 100000,
                    1000000, 1000000, 1000000, 1000000,1000000, 1000000,
                    10000000, 10000000, 10000000, 10000000, 10000000, 10000000,
                    100000000,100000000,100000000,100000000,100000000,100000000};
    int max_values[] = {1000, 10000, 100000, 1000000, 10000000, 100000000,
        1000, 10000, 100000, 1000000, 10000000, 100000000,
        1000, 10000, 100000, 1000000, 10000000, 100000000,
        1000, 10000, 100000, 1000000, 10000000, 100000000,
        1000, 10000, 100000, 1000000, 10000000, 100000000,
        1000, 10000, 100000, 1000000, 10000000, 100000000};

    for (int i = 0; i < 36; ++i)
    {
        string filename = "test" + to_string(i + 1) + ".txt";
        generateTest(filename, num_numbers[i], 0, max_values[i]);
    }
    cout << "S-au generat toate testele cu succes!" << '\n';
    return 0;
}
