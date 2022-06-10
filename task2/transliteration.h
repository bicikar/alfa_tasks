#ifndef TRANSLITERATION_TRANSLITERATION_H
#define TRANSLITERATION_TRANSLITERATION_H
#include <map>
#include <fstream>

void rus_to_eng(std::ifstream &input_file, std::ofstream &out, std::map<std::string, std::string> transl);

void eng_to_rus(std::ifstream &input_file, std::ofstream &out, std::map<std::string, std::string> transl);

#endif //TRANSLITERATION_TRANSLITERATION_H
