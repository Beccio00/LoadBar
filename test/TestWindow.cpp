//
// Created by Riccardo Becciolini on 28/08/20.
//


#include "gtest/gtest.h"
#include "../LoadFiles.h"
#include "../Window.h"


TEST(TestObserver, testFileName) {

    LoadFiles loader;
    Window observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("file.h");
    loader.load(vector);

    ASSERT_EQ(observer.getFiles()->getFileName(), "file.h");
}

TEST(TestObserver, testFileSize) {

    LoadFiles loader;
    Window observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("../files/Cat.jpg");
    loader.load(vector);

    ASSERT_EQ(observer.getFiles()->getSize(), 27574);
}

TEST(TestObserver, testLoaded) {

    LoadFiles loader;
    Window observer(&loader);

    std::vector<const char*> vector;
    vector.push_back("../files/Cat.jpg");
    loader.load(vector);

    ASSERT_EQ(observer.getFiles()->isLoaded(), true);
}
