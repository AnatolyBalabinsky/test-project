#include "checker/LetterChecker.h"

bool LetterChecker::check(char symbol)
{

    if(symbol >= ascii_symbol_A && symbol <= ascii_symbol_Z || symbol >= ascii_symbol_a && symbol <= ascii_symbol_z){
        return true;
    }

    return false;
}
