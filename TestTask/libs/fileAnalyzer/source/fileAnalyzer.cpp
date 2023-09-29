#include "fileAnalyzer/fileAnalyzer.h"


fileAnalyzer::fileAnalyzer(std::string path)
{
        this->path = path;
}

std::string fileAnalyzer::getPath() const{

    return this->path;
}

int32_t fileAnalyzer::getLettersAmount() const{

    std::ifstream myFile;
    myFile.open(path);

    if(!myFile.is_open()){

        std::cout << "Reading error!" << std::endl;
        return 0;

    }

    char ch;
    int32_t totalAmountL = 0;

    while (myFile.get(ch)) {

        if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
            ++totalAmountL;

       }

    myFile.close();
    return totalAmountL;


}

int32_t fileAnalyzer::getWordsAmount() const{

    std::ifstream myFile;
    myFile.open(path);

    if(!myFile.is_open()){

        std::cout << "Reading error!" << std::endl;
        return 0;

    }

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

    myFile.close();
    return totalAmountW;

}

int32_t fileAnalyzer::getSentenceAmount() const{

    std::ifstream myFile;
    myFile.open(path);

    if(!myFile.is_open()){

        std::cout << "Reading error!" << std::endl;
        return 0;

    }

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

    myFile.close();
    return totalAmountS;
}
