#include "fileAnalyzer/fileAnalyzer.h"


fileAnalyzer::fileAnalyzer(std::string path) : path(path)
{
    //this->path = path;
}


void fileAnalyzer::openFile (){

    myFile.open(path);

    if(!myFile.is_open()){
        throw std::runtime_error("Can't open " + path);

    }

}

/*

friend void fileAnalyzer::FileData::operator<<(std::ofstream& os, const FileData& fd)
{
    os <<  "Number of letters: " << fd.totalLettersAmount << ";" << std::endl;
    os <<  "Number of words: " << fd.totalWordsAmount << ";" << std::endl;
    os <<  "Number of sentences: " << fd.totalSentencesAmount << ";" << std::endl;
}
*/

void fileAnalyzer::closeFile (){

    myFile.close();

}

uint32_t fileAnalyzer::getLettersAmount() {

    char ch;
    int32_t totalAmountL = 0;

    while (myFile.get(ch)) {

        if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
            ++totalAmountL;

       }

    closeFile();

    return totalAmountL;

}

uint32_t fileAnalyzer::getWordsAmount(){

    char ch;
    int32_t totalAmountW = 0;
    bool isWord = false;

    while (myFile.get(ch)) {

        if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122){
            if(!isWord){
                isWord = true;
                ++totalAmountW;
            }
        }

        else{

            isWord = false;

        }
    }

    return totalAmountW;

}

uint32_t fileAnalyzer::getSentenceAmount() {

    char ch;
    int32_t totalAmountS = 0;
    bool isSentence = false;

    while (myFile.get(ch)) {

        if (ch != '!' && ch != '?' && ch != '.'){

            if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122){

                if(!isSentence){

                    isSentence = true;
                    ++totalAmountS;

                }
            }
        }

        else{

            isSentence = false;

        }

    }

    return totalAmountS;
}

fileAnalyzer::FileData fileAnalyzer::getFileInfo() {

    FileData fileData;

    openFile();
    fileData.totalLettersAmount = getLettersAmount();
    closeFile();

    openFile();
    fileData.totalWordsAmount = getWordsAmount();
    closeFile();

    openFile();
    fileData.totalSentencesAmount = getSentenceAmount();
    closeFile();

    std::cout << "Number of letters: " << fileData.totalLettersAmount << std::endl;
    std::cout << "Number of words: " << fileData.totalWordsAmount << std::endl;
    std::cout << "Number of sentences: " << fileData.totalSentencesAmount << std::endl;

    closeFile();
    //std::cout << fileData << std::endl;

    return fileData;

}
