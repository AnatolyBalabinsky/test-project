#include "fileAnalyzer/fileAnalyzer.h"


fileAnalyzer::fileAnalyzer(std::string path)
{
        this->path = path;
}

int32_t fileAnalyzer::getLettersAmount() const{

    std::ifstream fin;
    fin.open(path);

    if(!fin.is_open()){

        std::cout << "Reading error!" << std::endl;
        return 0;

    }

    char ch;
    int32_t totalAmountL = 0;

    while (fin.get(ch)) {

        if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
            ++totalAmountL;

       }

    fin.close();
    return totalAmountL;


}

int32_t fileAnalyzer::getWordsAmount() const{

    return 0;
}

int32_t fileAnalyzer::getSentenceAmount() const{

    return 0;
}
