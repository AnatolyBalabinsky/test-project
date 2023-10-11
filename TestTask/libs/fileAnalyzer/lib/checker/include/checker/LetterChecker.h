#ifndef LETTERCHECKER_H
#define LETTERCHECKER_H

#include "checker/ichecker.h"

class LetterChecker : public IChecker{
public:

    bool check (char symbol) override;

};

#endif // LETTERCHECKER_H
