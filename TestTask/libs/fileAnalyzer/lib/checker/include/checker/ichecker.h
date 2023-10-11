#ifndef CHECKER_H
#define CHECKER_H

#include <iostream>
#include <memory>

class IChecker
{
public:

    virtual bool check (char symbol) = 0;

    virtual ~IChecker() = default;
protected:
    const char ascii_symbol_A = 65;
    const char ascii_symbol_Z = 90;

    const char ascii_symbol_a = 97;
    const char ascii_symbol_z = 122;
};

class CheckerFactory {

public:

    enum class CheckerParam{letter, word, sentence};
    static std::unique_ptr<IChecker> createChecker (CheckerParam param);
};

#endif // CHECKER_H
