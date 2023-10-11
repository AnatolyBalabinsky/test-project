#ifndef WORDCHECKER_H
#define WORDCHECKER_H

#include "checker/ichecker.h"

class WordChecker : public IChecker{
public:

    bool check (char symbol) override;

private:
    bool isWord = false;

};

#endif // WORDCHECKER_H
