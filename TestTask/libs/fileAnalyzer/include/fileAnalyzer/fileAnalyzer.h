#ifndef FILE_ANALYZER_H
#define FILE_ANALYZER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>

class fileAnalyzer{
public:

    fileAnalyzer(std::string path);
    std::string getPath() const;

    int32_t getLettersAmount() const;
    int32_t getWordsAmount() const;
    int32_t getSentenceAmount() const;
    void printData() const;

private:

    std::string path;

};

#endif
