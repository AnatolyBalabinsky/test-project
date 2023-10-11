#include "checker/LetterChecker.h"
#include "checker/WordChecker.h"

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

