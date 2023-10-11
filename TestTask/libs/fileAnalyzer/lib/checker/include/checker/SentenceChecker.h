#ifndef SENTENCECHECKER_H
#define SENTENCECHECKER_H

#include "checker/ichecker.h"

class SentenceChecker : public IChecker{
public:

    bool check (char symbol) override;

private:
    bool isSentence = false;

};
#endif // SENTENCECHECKER_H
