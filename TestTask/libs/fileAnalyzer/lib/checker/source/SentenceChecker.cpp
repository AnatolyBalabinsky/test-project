#include "checker/LetterChecker.h"
#include "checker/SentenceChecker.h"

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
