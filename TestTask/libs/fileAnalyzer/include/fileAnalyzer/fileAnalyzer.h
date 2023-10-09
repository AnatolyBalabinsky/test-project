#ifndef FILE_ANALYZER_H
#define FILE_ANALYZER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "checker/checker.h"

class fileAnalyzer{
public:

    struct FileData{

        uint32_t totalLettersAmount = 0;
        uint32_t totalWordsAmount = 0;
        uint32_t totalSentencesAmount = 0;

        friend void operator<<(std::ostream& os, const FileData& fd){
            os <<  "Number of letters: " << fd.totalLettersAmount << ";" << std::endl;
            os <<  "Number of words: " << fd.totalWordsAmount << ";" << std::endl;
            os <<  "Number of sentences: " << fd.totalSentencesAmount << ";" << std::endl;
        }
    };

    fileAnalyzer(std::string path);

    FileData getFileInfo();

private:
    uint32_t getLettersAmount();
    uint32_t getWordsAmount();
    uint32_t getSentenceAmount();

    void openFile ();
    void closeFile ();

    std::string path;
    std::ifstream myFile;

    std::unique_ptr<IChecker> checker;

};


#endif
