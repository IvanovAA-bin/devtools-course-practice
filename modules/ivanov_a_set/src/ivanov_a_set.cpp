// Copyright 2022 Ivanov Arkady

#include <vector>
#include "include/ivanov_a_set.h"

Set::Set() {
    size = 0;
    head = nullptr;
}

Set::Set(const Set& c) {
    size = 0;
    head = nullptr;

    Set::Node* cHead = c.head;
    Set::Node* prevCreatedNode = nullptr;
    Set::Node* thisHead = nullptr;
    while (cHead != nullptr) {
        Set::Node* newNode = new Set::Node(cHead->value);
        if (thisHead == nullptr)
            thisHead = newNode;
        newNode->prev = prevCreatedNode;
        if (prevCreatedNode != nullptr)
            prevCreatedNode->next = newNode;
        prevCreatedNode = newNode;
        cHead = cHead->next;
        ++size;
    }
    head = thisHead;
}

Set::Set(const std::vector<int>& c) {
    size = 0;
    head = nullptr;

    for (size_t i = 0; i < c.size(); i++)
        add(c.at(i));
}

Set::~Set() {
    size = 0;
    while (head != nullptr) {
        Set::Node* ptr = head;
        head = head->next;
        delete ptr;
    }
}

size_t Set::getSize() const {
    return size;
}


Set::Node* Set::nodeAt(const size_t index) const {
    Set::Node* tHead = head;
    if (index >= size)
        throw "Set size is less than needed";

    for (size_t i = 0; i < index; i++)
        tHead = tHead->next;
    return tHead;
}

int Set::getValueAt(const size_t index) const {
    return nodeAt(index)->value;
}

void Set::add(const int value) {
    if (head == nullptr) {
        head = new Set::Node(value);
        size = 1;
        return;
    }

    Set::Node* tHead = head;
    while (true) {
        if (value > tHead->value) {
            if (tHead->next == nullptr) {
                Set::Node* newNode = new Set::Node(value);
                newNode->prev = tHead;
                tHead->next = newNode;
                ++size;
                return;
            } else {
                if (value > tHead->next->value) {
                    tHead = tHead->next;
                } else if (value < tHead->next->value) {
                    Set::Node* newNode = new Set::Node(value);
                    Set::Node* tNext = tHead->next;
                    tHead->next = newNode;
                    tNext->prev = newNode;
                    newNode->prev = tHead;
                    newNode->next = tNext;
                    ++size;
                    return;
                } else {
                    throw "Value already exists in Set";
                }
            }
        } else if (value < tHead->value) {
            Set::Node* newNode = new Set::Node(value);
            newNode->next = tHead;
            tHead->prev = newNode;
            head = newNode;
            ++size;
            return;
        } else {
            throw "Value already exists in Set";
        }
    }
}

void Set::removeAt(const size_t index) {
    Set::Node* delNode = nodeAt(index);

    if (delNode == head) {
        if (head->next != nullptr) {
            Set::Node* next = head->next;
            next->prev = nullptr;
            delete head;
            head = next;
        } else {
            delete head;
            head = nullptr;
        }
        --size;
    } else {
        Set::Node* prevNode = delNode->prev;
        Set::Node* nextNode = delNode->next;
        delete delNode;
        prevNode->next = nextNode;
        if (nextNode != nullptr)
            nextNode->prev = prevNode;
        --size;
    }
}

void Set::removeValue(const int value) {
    if (head == nullptr)
        return;

    if (value < head->value)
        return;

    if (value == head->value) {
        removeAt(0);
        return;
    }

    Set::Node* tHead = head;
    while (true) {
        if (tHead == nullptr)
            return;
        if (value > tHead->value) {
            tHead = tHead->next;
            continue;
        }
        Set::Node* prevNode = tHead->prev;
        Set::Node* nextNode = tHead->next;
        delete tHead;
        prevNode->next = nextNode;
        if (nextNode != nullptr)
            nextNode->prev = prevNode;
        --size;
        return;
    }
}

Set Set::unionWith(const Set& c) const {
    Set res;
    Set::Node* tHead = head;
    Set::Node* cHead = c.head;

    while (tHead != nullptr && cHead != nullptr) {
        if (tHead->value < cHead->value) {
            res.add(tHead->value);
            tHead = tHead->next;
            continue;
        }
        if (tHead->value > cHead->value) {
            res.add(cHead->value);
            cHead = cHead->next;
            continue;
        }
        res.add(tHead->value);
        tHead = tHead->next;
        cHead = cHead->next;
    }
    while (tHead != nullptr) {
        res.add(tHead->value);
        tHead = tHead->next;
    }
    while (cHead != nullptr) {
        res.add(cHead->value);
        cHead = cHead->next;
    }
    return res;
}

Set Set::intersectWith(const Set& c) const {
    Set res;
    Set::Node* tHead = head;
    Set::Node* cHead = c.head;

    while (tHead != nullptr && cHead != nullptr) {
        if (tHead->value < cHead->value) {
            tHead = tHead->next;
            continue;
        }
        if (tHead->value > cHead->value) {
            cHead = cHead->next;
            continue;
        }
        res.add(tHead->value);
        tHead = tHead->next;
        cHead = cHead->next;
    }
    return res;
}

Set Set::differenceFrom(const Set& c) const {
    Set res;
    Set::Node* tHead = head;
    Set::Node* cHead = c.head;

    while (tHead != nullptr && cHead != nullptr) {
        if (tHead->value > cHead->value) {
            cHead = cHead->next;
            continue;
        }
        if (tHead->value < cHead->value) {
            res.add(tHead->value);
            tHead = tHead->next;
            continue;
        }
        tHead = tHead->next;
        cHead = cHead->next;
    }
    while (tHead != nullptr) {
        res.add(tHead->value);
        tHead = tHead->next;
    }
    return res;
}

bool Set::belongsTo(const Set& c) const {
    if (size > c.size)
        return false;
    Set::Node* tHead = head;
    Set::Node* cHead = c.head;
    size_t foundEqual = 0;
    while (tHead != nullptr && cHead != nullptr) {
        if (cHead->value < tHead->value) {
            cHead = cHead->next;
            continue;
        }
        if (cHead->value > tHead->value) {
            tHead = tHead->next;
            continue;
        }
        cHead = cHead->next;
        tHead = tHead->next;
        ++foundEqual;
    }
    return foundEqual == size;
}

bool Set::includes(const Set& c) const {
    return c.belongsTo(*this);
}

bool Set::operator==(const Set& c) const {
    if (size != c.size)
        return false;
    Set::Node* tHead = head;
    Set::Node* cHead = c.head;
    while (tHead != nullptr) {
        if (tHead->value != cHead->value)
            return false;
        tHead = tHead->next;
        cHead = cHead->next;
    }
    return true;
}

bool Set::strictlyBelongsTo(const Set& c) const {
    if (size >= c.size)
        return false;
    return belongsTo(c);
}

bool Set::strictlyIncludes(const Set& c) const {
    if (c.size >= size)
        return false;
    return c.belongsTo(*this);
}
