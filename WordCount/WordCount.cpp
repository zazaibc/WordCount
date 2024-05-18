#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// 函数用于统计字符数
int countCharacters(const string& filename) {
    ifstream file(filename);
    char c;
    int count = 0;
    while (file.get(c)) {
        count++;
    }
    return count;
}

// 函数用于统计单词数
int countWords(const string& filename) {
    ifstream file(filename);
    string word;
    int count = 0;
    while (file >> word) {
        count++;
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " [-c | -w] [input_file_name]" << endl;
        return 1;
    }

    string parameter = argv[1];
    string filename = argv[2];

    int count = 0;

    if (parameter == "-c") {
        count = countCharacters(filename);
        cout << "字符数：" << count << endl;
    }
    else if (parameter == "-w") {
        count = countWords(filename);
        cout << "单词数：" << count << endl;
    }
    else {
        cout << "Invalid parameter. Please use -c or -w." << endl;
        return 1;
    }

    return 0;
}
