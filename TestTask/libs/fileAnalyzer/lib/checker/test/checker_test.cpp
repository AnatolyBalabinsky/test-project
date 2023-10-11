#include <gtest/gtest.h>
#include "checker/LetterChecker.h"
#include "checker/WordChecker.h"
#include "checker/SentenceChecker.h"
#include <iostream>

TEST(checker_Test, LetterChecker) {

    char testSymbol;
    LetterChecker testedChecker;

    for(testSymbol = -128; testSymbol < 65; ++testSymbol){

        ASSERT_FALSE(testedChecker.check(testSymbol));

    }

    for(testSymbol = 65; testSymbol <= 90; ++testSymbol){

        ASSERT_TRUE(testedChecker.check(testSymbol));

    }

    for(testSymbol = 91; testSymbol < 97; ++testSymbol){

        ASSERT_FALSE(testedChecker.check(testSymbol));

    }

    for(testSymbol = 97; testSymbol <= 122; ++testSymbol){

        ASSERT_TRUE(testedChecker.check(testSymbol));
    }

    for(testSymbol = 123; testSymbol <= 127; testSymbol++){
        if(testSymbol < 0){break;}
        ASSERT_FALSE(testedChecker.check(testSymbol));
    }
}

TEST(checker_Test, WordChecker) {

    WordChecker testedObject;
    ASSERT_TRUE(testedObject.check('w'));
    ASSERT_FALSE(testedObject.check('o'));
    ASSERT_FALSE(testedObject.check('r'));
    ASSERT_FALSE(testedObject.check('k'));
    ASSERT_FALSE(testedObject.check(' '));
    ASSERT_TRUE(testedObject.check('w'));
}

TEST(checker_Test, SentenceChecker) {

    SentenceChecker testedObject;
    ASSERT_TRUE(testedObject.check('w'));
    ASSERT_FALSE(testedObject.check('o'));
    ASSERT_FALSE(testedObject.check('r'));
    ASSERT_FALSE(testedObject.check('k'));
    ASSERT_FALSE(testedObject.check(' '));
    ASSERT_FALSE(testedObject.check('w'));
    ASSERT_FALSE(testedObject.check('!'));
    ASSERT_TRUE(testedObject.check('w'));
}

TEST(checker_Test, CheckerFactory) {


    ASSERT_NE(CheckerFactory::createChecker(CheckerFactory::CheckerParam::letter), nullptr);

    ASSERT_NE(CheckerFactory::createChecker(CheckerFactory::CheckerParam::word), nullptr);

    ASSERT_NE(CheckerFactory::createChecker(CheckerFactory::CheckerParam::sentence), nullptr);

    CheckerFactory::CheckerParam param;
    ASSERT_EQ(CheckerFactory::createChecker(param), nullptr);
}

