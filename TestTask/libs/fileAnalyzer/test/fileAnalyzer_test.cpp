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

TEST(fileAnalyzer_Test, SymbolsAmount)
{
    std::string filePath = "data/probeTexts/probeSymbols_8.txt";
    FileAnalyzer testedObject(filePath);

    ASSERT_EQ(testedObject.getFileInfo().totalSymbolsAmount, 8);

}

TEST(fileAnalyzer_Test, EmptyFile)
{
    std::string filePath = "data/probeTexts/emptyFile.txt";
    FileAnalyzer testedObject(filePath);

    ASSERT_EQ(testedObject.getFileInfo().totalSymbolsAmount, 0);
    ASSERT_EQ(testedObject.getFileInfo().totalLettersAmount, 0);
    ASSERT_EQ(testedObject.getFileInfo().totalWordsAmount, 0);
    ASSERT_EQ(testedObject.getFileInfo().totalSentencesAmount, 0);
}

TEST(fileAnalyzer_Test, FinalTestAndOperatorTest)
{
    std::string filePath = "data/probeTexts/FinalCheckFile_50_41_8_2.txt";
    FileAnalyzer testedObject(filePath);

    ASSERT_EQ(testedObject.getFileInfo().totalSymbolsAmount, 50);
    ASSERT_EQ(testedObject.getFileInfo().totalLettersAmount, 41);
    ASSERT_EQ(testedObject.getFileInfo().totalWordsAmount, 8);
    ASSERT_EQ(testedObject.getFileInfo().totalSentencesAmount, 2);
    std::cout << testedObject.getFileInfo();
}

