//
// Created by Riccardo Becciolini on 28/08/20.
//


#include "gtest/gtest.h"
#include "../LoadFiles.h"
#include "../Window.h"


TEST(TestWindow, testFileName) {

    std::vector<QString> vector;
    vector.push_back("file.h");

    LoadFiles loader(vector);
    Window observer(&loader);


    loader.load();

    ASSERT_EQ(observer.getFiles()->getFileName(), "file.h");
}

TEST(TestWindow, testFileSize) {

    std::vector<QString> vector;
    vector.push_back("files/Cat.jpg");

    LoadFiles loader(vector);
    Window observer(&loader);


    loader.load();

    ASSERT_EQ(observer.getFiles()->getSize(), 27574);
}

TEST(TestWindow, testLoaded) {

    std::vector<QString> vector;
    vector.push_back("/files/Cat.jpg");

    LoadFiles loader(vector);
    Window observer(&loader);


    loader.load();

    ASSERT_EQ(observer.getFiles()->isLoaded(), true);
}
