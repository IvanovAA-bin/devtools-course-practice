// Copyright 2022 Ustiuzhanin Nikita

#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "include/hashmap.h"

using std::string;

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, EMPTY) {
    Hashmap<string, int> h;
    ASSERT_EQ(h.size(), 0);
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, ASSERT_RESIZE) {
    Hashmap<string, int> h;
    ASSERT_ANY_THROW(h.resize(10));
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, CORRECT_INSERT) {
    Hashmap<string, int> h;
    string key = "myStr";
    int value = 1;

    h.insert(key, value);

    ASSERT_EQ(h[key], value);
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, INSERT_EXIST_KEY) {
    Hashmap<string, int> h;

    h.insert("string", 1);

    ASSERT_ANY_THROW(h.insert("string", 1));
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, CORRECT_ERASE) {
    Hashmap<string, int> h;

    h.insert("string", 1);

    ASSERT_NO_THROW(h.erase("string"));
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, ERASE_FROM_EMPTY) {
    Hashmap<string, int> h;

    ASSERT_ANY_THROW(h.erase("string"));
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, ERASE_NON_EXIST_KEY) {
    Hashmap<string, int> h;

    h.insert("string", 1);

    ASSERT_ANY_THROW(h.erase("String"));
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, GET_BY_NON_EXIST_KEY) {
    Hashmap<string, int> h;

    h.insert("string", 1);

    ASSERT_ANY_THROW(h["String"]);
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, DEL_THEN_ACCESS) {
    Hashmap<string, int> h;
    h.insert("str", 1);
    h.erase("str");
    ASSERT_ANY_THROW(h["str"]);
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, COPY) {
    Hashmap<string, int> h;
    h.insert("str", 1);
    h.insert("string", 11);
    Hashmap<string, int> hh;
    ASSERT_NO_THROW(hh = h);
}

TEST(USTIUZHANIN_NIKITA_HASHMAP_TESTS, RESIZE_BY_INSERT) {
    Hashmap<string, int> h(2);
    h.insert("str", 1);
    ASSERT_NO_THROW(h.insert("string", 11));
}
