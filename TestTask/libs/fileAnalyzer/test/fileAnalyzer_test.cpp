#include <gtest/gtest.h>
#include "fileAnalyzer/fileAnalyzer.h"

TEST(fileAnalyzer_Test, Creating) {

    std::string filePath = "Hello world!";
    fileAnalyzer testedObject(filePath);
    ASSERT_EQ(testedObject.getPath(), filePath);

}

TEST(fileAnalyzer_Test, LettersAmount) {

    std::string filePath = "data/probeTexts/probeLettersAmount_10.txt";
    fileAnalyzer testedObject(filePath);
    ASSERT_EQ(testedObject.getLettersAmount(), 10);

}

TEST(fileAnalyzer_Test, WordsAmount) {

    std::string filePath = "data/probeTexts/probeWordsAmount_5.txt";
    fileAnalyzer testedObject(filePath);
    ASSERT_EQ(testedObject.getWordsAmount(), 5);

}

TEST(fileAnalyzer_Test, SentencesAmount) {

    std::string filePath = "data/probeTexts/probeSentencesAmount_4.txt";
    fileAnalyzer testedObject(filePath);
    ASSERT_EQ(testedObject.getSentenceAmount(), 4);

}
