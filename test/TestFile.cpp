//
// Created by Riccardo Becciolini on 28/08/20.
//


#include "gtest/gtest.h"
#include "../File.h"

TEST(TestFile, testExistentResource) {
    ASSERT_NO_THROW(File file("../files/Cat.jpg"));
}

TEST(TestFile, testSizeForExistentFile) {
    File file("../files/Cat.jpg");
    ASSERT_FALSE(file.getFileSize() == 0);
}

