//
// Created by Riccardo Becciolini on 28/08/20.
//


#include "gtest/gtest.h"
#include "../LoadFiles.h"
#include "../Window.h"


TEST(TestWindow, testFileName) {

    std::vector<File*> vector;
    vector.push_back(new File("file.h"));

    LoadFiles loader(vector);
    Window observer(&loader);


    loader.load();

    auto it = observer.getFiles()->getVector().begin();

    ASSERT_EQ((*it)->getFilename(), "file.h");
}

TEST(TestWindow, testFileSize) {

    std::vector<File*> vector;
    vector.push_back(new File("files/Cat.jpg"));

    LoadFiles loader(vector);
    Window observer(&loader);


    loader.load();

    auto it = observer.getFiles()->getVector().begin();

    ASSERT_EQ((*it)->getFileSize(), 27574);
}

TEST(TestWindow, testLoaded) {

    std::vector<File*> vector;
    vector.push_back(new File("/files/Cat.jpg"));

    LoadFiles loader(vector);
    Window observer(&loader);


    loader.load();

    auto it = observer.getFiles()->getVector().begin();

    ASSERT_EQ((*it)->isUploaded(), true);
}
