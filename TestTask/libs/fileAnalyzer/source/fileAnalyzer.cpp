#include "fileAnalyzer/fileAnalyzer.h"


fileAnalyzer::fileAnalyzer(std::string path) : path(path)
{
}


void fileAnalyzer::openFile (){

    myFile.open(path);
    if(!myFile.is_open()){
        throw std::runtime_error("Can't open " + path);

    }

}

void fileAnalyzer::closeFile (){

    myFile.close();

}

uint32_t fileAnalyzer::getLettersAmount() {

    checker = CheckerFactory::createChecker(CheckerFactory::CheckerParam::letter);
    char symbol;
    uint32_t totalAmountL = 0;

    while (myFile.get(symbol)) {

        if(checker->check(symbol) == true)
            ++totalAmountL;

       }

    return totalAmountL;

}

uint32_t fileAnalyzer::getWordsAmount(){

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

uint32_t fileAnalyzer::getSentenceAmount() {

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

fileAnalyzer::FileData fileAnalyzer::getFileInfo() {

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
