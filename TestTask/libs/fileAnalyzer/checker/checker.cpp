#include "checker.h"


bool LetterChecker::check(char symbol)
{

    if(symbol >= ascii_symbol_A && symbol <= ascii_symbol_Z || symbol >= ascii_symbol_a && symbol <= ascii_symbol_z){
        return true;
    }

    return false;
}

bool WordChecker::check(char symbol)
{
    LetterChecker CheckLetter;

    if(CheckLetter.check(symbol) == true){

        if(!isWord){

            return isWord = true;

        }

    }

    else{

        isWord = false;

    }

    return false;
}

bool SentenceChecker::check(char symbol)
{
    LetterChecker CheckLetter;

    if (symbol != '!' && symbol != '?' && symbol != '.'){

        if(CheckLetter.check(symbol) == true){

            if(!isSentence){

                return isSentence = true;

            }
        }
    }

    else{

        isSentence = false;

    }

    return false;
}

std::unique_ptr<IChecker> CheckerFactory::createChecker (CheckerParam param) {

    if(param == CheckerParam::letter) {

        //std::unique_ptr<IChecker> checkLetter(new LetterChecker());
        return std::make_unique<LetterChecker>();

    }
    else if(param == CheckerParam::word){

        //std::unique_ptr<IChecker> checkWord(new WordChecker());
        return std::make_unique<WordChecker>();
    }

    else if(param == CheckerParam::sentence){

        //std::unique_ptr<IChecker> checkSentence(new SentenceChecker());
        return std::make_unique<SentenceChecker>();
    }

    else{
        return nullptr;
    }

}
