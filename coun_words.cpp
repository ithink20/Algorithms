#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
typedef long long int lint;

void wordsinFile(string line, int &word_count, int &char_count) {
    line += '.';
    bool word = false;
    string delimiter = " ";
    char current_char;

    word_count = 0;
    for (char_count = 0; char_count < line.length(); ) {
        current_char = line[char_count];
        if (delimiter.find(current_char) == string::npos) {
            if (word) {
                char_count += 1;
            } else {
                word = true;
                char_count += 1;
                word_count += 1;
            }
        } else {
            if (word) {
                word = false;
                char_count += 1;
            } else {
                char_count += 1;
            }
        }
    }
    return;
}

int main() {
    ifstream file;
    file.open("/Users/vikaschaurasiya/Desktop/input_1.txt");
    if (file.fail()) {
        //pass
        cerr << "Error : " << strerror(errno) << endl;
        return 1;
    }
    int count_line = 0, word_count, char_count;
    string current_line;
    getline(file, current_line);
    while (file) {
        wordsinFile(current_line, word_count, char_count);
        cout << word_count << endl;
        count_line += 1;
        getline(file, current_line);
    }
    cout << count_line << endl;
    return 0;
}
