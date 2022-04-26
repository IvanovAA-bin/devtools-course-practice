// Copyright 2022 Ivanov Arkady

#ifndef MODULES_IVANOV_A_SET_INCLUDE_IVANOV_A_SET_H_
#define MODULES_IVANOV_A_SET_INCLUDE_IVANOV_A_SET_H_

#include <cstdlib>
#include <iostream>
#include <vector>

class Set {
 private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node() :value(0), next(nullptr), prev(nullptr) {}
        Node(int _value, Node* _next, Node* _prev) :
            value(_value), next(_next), prev(_prev) {}
        explicit Node(const int _value) : value(_value), next(nullptr), prev(nullptr) {}
    };

    Set::Node* head;
    size_t size;

    Set::Node* nodeAt(const size_t index) const;

 public:
    Set();
    Set(const Set& c);
    explicit Set(const std::vector<int>& c);
    ~Set();

    size_t getSize() const;
    int getValueAt(const size_t index) const;
    void add(const int value);
    void removeAt(const size_t index);
    void removeValue(const int value);


    Set unionWith(const Set& c);
    Set intersectWith(const Set& c);
    Set differenceFrom(const Set& c);

    bool belongsTo(const Set& c) const;
    bool includes(const Set& c) const;
    bool operator==(const Set& c) const;
    bool strictlyBelongsTo(const Set& c) const;
    bool strictlyIncludes(const Set& c) const;

    friend std::ostream& operator<< (std::ostream& o, const Set& c);
};


#endif  // MODULES_IVANOV_A_SET_INCLUDE_IVANOV_A_SET_H_
