//
// Created by Riccardo Becciolini on 11/09/20.
//

#include "../ConcreteObserver.h"
#include <gtest/gtest.h>

TEST(TestObserver, testFileName_) {

    std::vector<File*> vector;
    vector.push_back(new File("file.h"));

    LoadFiles loader(vector);
    ConcreteObserver observer(&loader);


    loader.load();

    auto itr = observer.getSubject()->getVector().begin();

    ASSERT_EQ((*itr)->getFilename(), "file.h");
}
