#include "checker/LetterChecker.h"
#include "checker/WordChecker.h"
#include "checker/SentenceChecker.h"

std::unique_ptr<IChecker> CheckerFactory::createChecker (CheckerParam param) {

    if(param == CheckerParam::letter) {

        return std::make_unique<LetterChecker>();

    }
    else if(param == CheckerParam::word){

        return std::make_unique<WordChecker>();
    }

    else if(param == CheckerParam::sentence){

        return std::make_unique<SentenceChecker>();
    }

    else{
        return nullptr;
    }

}
