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
