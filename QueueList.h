#pragma once
#include "QueueList_iterator.h"
#include <iterator>
  template<class T>
  class QueueList_iterator{
    int* _pos;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T; // Тип значения
    using difference_type = int; // Тип расстояния
    using pointer = T*; // Тип указателя
    using reference = T&; // Тип ссылки
    explicit QueueList_iterator(T* pos);
    ~QueueList_iterator();
  };
template<class T>
class QueueList {
private:
    struct node{
        node *next;
        node *previous;
       int item;
    };
    node *first;
    node *last;
    int size_;
        node *ptr;
    public:
        QueueList_iterator<T> begin() const;
        QueueList_iterator<T> end() const;
        QueueList();
        ~QueueList();
        int front();
        int back();
        bool empty() const;
        int size();
        void pop_front();
        void push_back(QueueList <T> &list, T value);
        void clear();
};