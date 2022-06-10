#include "transliteration.h"

/*
 * Function: rus_to_eng
 *
 * Use for russian text
 *
 * Read symbols from the input stream and write them to the
 * output stream according to transliteration rules
 *
 */
void rus_to_eng(std::ifstream &input_file, std::ofstream &out,
                std::map<std::string, std::string> transl) {
    char symbol;
    std::string str;
    int shift = 0;
    while (input_file.get(symbol)) {
        if (symbol > shift) {
            out << symbol;
        } else {
            str = "";
            str += symbol;
            input_file.get(symbol);
            str += symbol;
            out << transl[str];
        }
    }
}

/*
 * Function: eng_to_rus
 *
 * Use for english text
 *
 * Read symbols from the input stream and write them to the
 * output stream according to transliteration rules
 *
 */
void eng_to_rus(std::ifstream &input_file, std::ofstream &out,
                std::map<std::string, std::string> transl) {
    char symbol;
    std::string str;
    while (input_file.get(symbol)) {
        str = "";
        str += symbol;
        if (transl.find(str) == transl.end()) {
            out << symbol;
        } else {
            out << transl[str];
        }
    }
}
