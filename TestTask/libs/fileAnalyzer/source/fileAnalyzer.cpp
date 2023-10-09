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

uint32_t FileAnalyzer::getSymbolsAmount(){

    myFile.seekg(0, std::ios::end);
    uint32_t fileSize = myFile.tellg();
    myFile.seekg(0, std::ios::beg);

    return fileSize-1;
}

uint32_t FileAnalyzer::getLettersAmount(uint32_t symbolsAmount) {

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::letter);

    char symbol;
    uint32_t totalAmountL = 0;
    uint32_t cursorPos = 0;

    while (cursorPos <= symbolsAmount) {

        myFile.get(symbol);

        if(checker->check(symbol) == true){++totalAmountL;}

        ++cursorPos;

    }

    myFile.seekg(0, std::ios::beg);
    return totalAmountL;
}

uint32_t FileAnalyzer::getWordsAmount(uint32_t symbolsAmount){

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::word);

    char symbol;
    uint32_t totalAmountW = 0;
    uint32_t cursorPos = 0;

    while (cursorPos <= symbolsAmount) {

        myFile.get(symbol);
        if(checker->check(symbol) == true){

            ++totalAmountW;

        }
        ++cursorPos;
    }

    myFile.seekg(0, std::ios::beg);
    return totalAmountW;
}

uint32_t FileAnalyzer::getSentenceAmount(uint32_t symbolsAmount) {

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::sentence);

    char symbol;
    uint32_t totalAmountS = 0;
    uint32_t cursorPos = 0;

    while (cursorPos <= symbolsAmount) {

        myFile.get(symbol);

        if (checker->check(symbol) == true){
            ++totalAmountS;
        }

        ++cursorPos;
    }

    myFile.seekg(0, std::ios::beg);
    return totalAmountS;
}

FileAnalyzer::FileData FileAnalyzer::getFileInfo() {

    FileData fileData;

    openFile();

    fileData.totalSymbolsAmount = getSymbolsAmount();
    fileData.totalLettersAmount = getLettersAmount(fileData.totalSymbolsAmount);
    fileData.totalWordsAmount = getWordsAmount(fileData.totalSymbolsAmount);
    fileData.totalSentencesAmount = getSentenceAmount(fileData.totalSymbolsAmount);

    closeFile();

    return fileData;

}
