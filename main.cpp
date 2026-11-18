#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 29;

// Mid-square hashing:
// 1. Square the key.
// 2. Pad the square to at least four digits.
// 3. Extract the middle two digits.
// 4. Take modulo 29.
int hashFunction(int key) {
    int square = key * key;
    string s = to_string(square);

    while (s.length() < 4) {
        s = "0" + s;
    }

    int middle = stoi(s.substr(1, 2));
    return middle % TABLE_SIZE;
}

int main() {
    // PRN: 202501100155
    // Scenario: Student Marks
    // Dataset formula: v[i] = (155 + 13*i) % 100
    int marks[20] = {
        55, 68, 81, 94, 7,
        20, 33, 46, 59, 72,
        85, 98, 11, 24, 37,
        50, 63, 76, 89, 2
    };

    vector<vector<int>> table(TABLE_SIZE);

    cout << "PRN: 202501100155\n";
    cout << "Scenario: Student Marks\n";
    cout << "Hash function: Mid-square\n";
    cout << "Collision handling: Separate chaining\n\n";

    cout << "Insertion process:\n";
    for (int key : marks) {
        int index = hashFunction(key);

        cout << "Key: " << setw(2) << key
             << "  Hash index: " << index;

        if (!table[index].empty()) {
            cout << "  Collision occurred";
        }

        table[index].push_back(key);
        cout << "  Inserted\n";
    }

    cout << "\nFinal hash table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << setw(2) << i << " -> ";

        if (table[i].empty()) {
            cout << "Empty";
        } else {
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (j > 0) cout << " -> ";
                cout << table[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}
