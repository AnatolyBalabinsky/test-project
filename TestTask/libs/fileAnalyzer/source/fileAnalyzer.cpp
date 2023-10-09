#include "fileAnalyzer/fileAnalyzer.h"

FileAnalyzer::FileAnalyzer(std::string path) : path(path)
{
}


void FileAnalyzer::openFile (){

    myFile.open(path);
    if(!myFile.is_open()){
        throw std::runtime_error("Can't open " + path);

    }

}

void FileAnalyzer::closeFile (){

    myFile.close();

}

uint32_t FileAnalyzer::getLettersAmount() {

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::letter);
    char symbol;
    uint32_t totalAmountL = 0;

    while (myFile.get(symbol)) {

        if(checker->check(symbol) == true)
            ++totalAmountL;

       }

    return totalAmountL;

}

uint32_t FileAnalyzer::getWordsAmount(){

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::word);
    char symbol;
    uint32_t totalAmountW = 0;

    while (myFile.get(symbol)) {

        if(checker->check(symbol) == true){

            ++totalAmountW;

        }
    }

    return totalAmountW;

}

uint32_t FileAnalyzer::getSentenceAmount() {

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::sentence);
    char symbol;
    uint32_t totalAmountS = 0;

    while (myFile.get(symbol)) {

        if (checker->check(symbol) == true){
            ++totalAmountS;
        }

    }

    return totalAmountS;
}

FileAnalyzer::FileData FileAnalyzer::getFileInfo() {

    FileData fileData;

    openFile();
    fileData.totalLettersAmount = getLettersAmount();
    //myFile.seekg(0, std::ios::beg);
    closeFile();

    openFile();
    fileData.totalWordsAmount = getWordsAmount();
    //myFile.seekg(0, std::ios::beg);
    closeFile();

    openFile();
    fileData.totalSentencesAmount = getSentenceAmount();
    //myFile.seekg(0, std::ios::beg);
    closeFile();

    return fileData;

}
