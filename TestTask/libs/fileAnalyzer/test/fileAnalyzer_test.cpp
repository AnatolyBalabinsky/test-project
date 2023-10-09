#include <gtest/gtest.h>
#include "fileAnalyzer/fileAnalyzer.h"

TEST(fileAnalyzer_Test, Creating) {

    std::string filePath = "data/probeTexts/probeLettersAmount_10.txt";
    FileAnalyzer testedObject(filePath);

    try{
    testedObject.getFileInfo();
    }

    catch(std::exception& e){
        ASSERT_STREQ(e.what(), "Uncorrect path");
    }

}

TEST(fileAnalyzer_Test, LettersAmount)
{
    std::string filePath = "data/probeTexts/probeLettersAmount_10.txt";
    FileAnalyzer testedObject(filePath);

    ASSERT_EQ(testedObject.getFileInfo().totalLettersAmount, 10);

}

TEST(fileAnalyzer_Test, WordsAmount)
{
    std::string filePath = "data/probeTexts/probeWordsAmount_5.txt";
    FileAnalyzer testedObject(filePath);

    ASSERT_EQ(testedObject.getFileInfo().totalWordsAmount, 5);

}

TEST(fileAnalyzer_Test, SentencesAmount)
{
    std::string filePath = "data/probeTexts/probeSentencesAmount_4.txt";
    FileAnalyzer testedObject(filePath);

    ASSERT_EQ(testedObject.getFileInfo().totalSentencesAmount, 4);

}
