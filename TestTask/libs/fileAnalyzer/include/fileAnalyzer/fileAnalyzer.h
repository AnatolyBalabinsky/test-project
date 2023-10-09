#ifndef FILE_ANALYZER_H
#define FILE_ANALYZER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "checker/checker.h"

class FileAnalyzer{
public:

    struct FileData{

        uint32_t totalSymbolsAmount = 0;
        uint32_t totalLettersAmount = 0;
        uint32_t totalWordsAmount = 0;
        uint32_t totalSentencesAmount = 0;


        friend void operator<<(std::ostream& os, const FileData& fd){

            os <<  "Number of non-zero symbols: " << fd.totalSymbolsAmount << ";" << std::endl;
            os <<  "Number of letters: " << fd.totalLettersAmount << ";" << std::endl;
            os <<  "Number of words: " << fd.totalWordsAmount << ";" << std::endl;
            os <<  "Number of sentences: " << fd.totalSentencesAmount << ";" << std::endl;

        }
    };

    FileAnalyzer(std::string path);

    FileData getFileInfo();

private:

    uint32_t getSymbolsAmount();
    uint32_t getLettersAmount(uint32_t symbolsAmount);
    uint32_t getWordsAmount(uint32_t symbolsAmount);
    uint32_t getSentenceAmount(uint32_t symbolsAmount);

    void openFile ();
    void closeFile ();

    std::string path;
    std::ifstream myFile;

    std::unique_ptr<IChecker> checker;

};


#endif
