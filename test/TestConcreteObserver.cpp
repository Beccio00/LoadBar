//
// Created by Riccardo Becciolini on 11/09/20.
//

#include "../ConcreteObserver.h"
#include <gtest/gtest.h>

TEST(TestObserver, testFileName) {

    std::vector<QString> vector;
    vector.push_back("file.h");

    LoadFiles loader(vector);
    ConcreteObserver observer(&loader);


    loader.load();

    ASSERT_EQ(observer.getSubject()->getFileName(), "file.h");
}
