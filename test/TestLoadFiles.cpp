//
// Created by Riccardo Becciolini on 28/08/20.
//


#include "gtest/gtest.h"
#include "../LoadFiles.h"

TEST(TestLoadResources, testNoFileNamesProvided) {
    std::vector<const char*> vector;
    LoadFiles loader;
    loader.load(vector);
    ASSERT_EQ(loader.getNumberFile(), 0);

}

TEST(TestLoadResources, fileNamesProvided) {

    std::vector<const char*> vector;
    vector.push_back("esempio1");
    vector.push_back("esempio2");
    vector.push_back("esempio3");
    LoadFiles loader;
    loader.load(vector);
    ASSERT_EQ(loader.getNumberFile(), 3);
}
