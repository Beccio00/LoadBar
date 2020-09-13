//
// Created by Riccardo Becciolini on 28/08/20.
//


#include "gtest/gtest.h"
#include "../LoadFiles.h"

TEST(TestLoadResources, testNoFileNamesProvided) {
    std::vector<File*> vector;
    LoadFiles loader(vector);
    loader.load();
    ASSERT_EQ(loader.getNumberFile(), 0);

}

TEST(TestLoadResources, fileNamesProvided) {

    std::vector<File*> vector;
    vector.push_back(new File("esempio1"));
    vector.push_back(new File("esempio2"));
    vector.push_back(new File("esempio3"));
    LoadFiles loader(vector);
    loader.load();
    ASSERT_EQ(loader.getNumberFile(), 3);
}
