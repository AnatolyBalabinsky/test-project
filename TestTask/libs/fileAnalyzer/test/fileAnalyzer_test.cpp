#include <gtest/gtest.h>
#include "fileAnalyzer/fileAnalyzer.h"

TEST(fileAnalyzer_Test, Creating) {

    std::string filePath = "data/probeTexts/probeLettersAmount_10.txt";
    fileAnalyzer testedObject(filePath);

    try{
    testedObject.getFileInfo();
    }

    catch(std::exception& e){
        ASSERT_STREQ(e.what(), "Uncorrect path");
    }

}

TEST(fileAnalyzer_Test, FileForCheckingLettersAmount) {

    std::string filePath = "data/probeTexts/probeLettersAmount_10.txt";
    fileAnalyzer testedObject(filePath);
    testedObject.getFileInfo();
}

TEST(fileAnalyzer_Test, FileForCheckingWordsAmount) {

    std::string filePath = "data/probeTexts/probeWordsAmount_5.txt";
    fileAnalyzer testedObject(filePath);
    testedObject.getFileInfo();

}

TEST(fileAnalyzer_Test, FileForCheckingSentencesAmount) {

    std::string filePath = "data/probeTexts/probeSentencesAmount_4.txt";
    fileAnalyzer testedObject(filePath);
    testedObject.getFileInfo();

}

/*
TEST(fileAnalyzer_Test, dataTest) {

    std::string filePath = "data/probeTexts/probeSentencesAmount_4.txt";
    fileAnalyzer testedObject(filePath);
    testedObject.getLettersAmount();
    testedObject.getWordsAmount();
    testedObject.getSentenceAmount();
    testedObject.printData();
}
*/
