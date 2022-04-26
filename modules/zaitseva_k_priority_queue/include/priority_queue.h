// Copyright 2022 Zaitseva Ksenia

#ifndef MODULES_ZAITSEVA_K_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_ZAITSEVA_K_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class PriorityQueue {
 private:
    std::vector<T> data;
    void heapify(int i);
 public:
    PriorityQueue() {}
    void push(T new_elem);
    T pop();
    int size() { return data.size(); }
    bool isEmpty() { return !data.size(); }
};

template<typename T>
void PriorityQueue<T>::heapify(int i) {
    std::size_t left = 2 * i + 1;
    std::size_t right = 2 * i + 2;
    if (left < data.size()) {
        if (data[i] < data[left]) {
            std::swap(data[i], data[left]);
            heapify(left);
        }
    }
    if (right < data.size()) {
        if (data[i] < data[right]) {
            std::swap(data[i], data[right]);
            heapify(right);
        }
    }
}

template<typename T>
void PriorityQueue<T>::push(T new_elem) {
    int i = static_cast<int>(data.size());
    data.push_back(new_elem);
    int parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (data[i] > data[parent]) {
            std::swap(data[i], data[parent]);
        }
        i = parent;
        parent = (i - 1) / 2;
    }
}

template<typename T>
T PriorityQueue<T>::pop() {
    if (data.size() != 0) {
        T res = data[0];
        data[0] = data[data.size() - 1];
        data = std::vector<T>(data.begin(), data.end() - 1);
        heapify(0);
        return res;
    } else {
        throw std::out_of_range("priority queue is empty");
    }
}

#endif  // MODULES_ZAITSEVA_K_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
