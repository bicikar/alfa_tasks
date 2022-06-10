#include <iostream>
#include <string>
#include "transliteration.h"


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    if (argc != 4) {
        std::cout << "Incorrect number of arguments\n";
        exit(1);
    }

    std::ifstream map_file(argv[1]);
    if (!map_file.is_open()) {
        std::cout << "Unable to open map file\n";
        exit(1);
    }

    std::ifstream input_file(argv[2]);
    if (!input_file.is_open()) {
        std::cout << "Unable to open map file\n";
        exit(1);
    }

    std::map<std::string, std::string> transl;

    std::string key, value;
    while (map_file >> key) {
        map_file >> value;
        transl[key] = value;
    }
    map_file.close();

    bool dir_flag;
    std::string dir(argv[3]);
    if (dir == "0" || dir == "1") {
        dir_flag = atoi(argv[3]);
    } else {
        std::cout << "Incorrect flag given\n";
        exit(1);
    }

    char tmp_name[] = "tmp.txt";
    std::ofstream out(tmp_name);

    if (dir_flag) {
        rus_to_eng(input_file, out, transl);
    } else {
        eng_to_rus(input_file, out, transl);
    }
    input_file.close();
    out.close();

    // Move and rename output file
    remove(argv[2]);
    if (rename(tmp_name, argv[2]) != 0) {
        std::cout << "Error";
        exit(1);
    } else {
        std::cout << "Transliteration done";
    }

    return 0;
}