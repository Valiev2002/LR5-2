#pragma once
#include "QueueList_iterator.h"
#include <iterator>
#include <iostream>
#include <memory>
template<class T>
class QueueList;
template<class T>
        std::ostream &operator<<(std::ostream &out,const QueueList <T> &ql) {
    for (auto *node = ql.first; node != nullptr; node = node->next) {
        out <<  node->value;
    }
    return out;
}
template<class T>
        class QueueList {
            struct node{
                node *next;
                T value;
            };
    private:
            node *first;
            node *last;
            friend std::ostream &operator<<<T>(std::ostream &out, const QueueList &ql);
            int size_;
        public:
         class QueueList_iterator{
                node* _pos;
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = int; // Тип значения
                using difference_type = int; // Тип расстояния
                using pointer = int*; // Тип указателя
                using reference = int&;// Тип ссылки
                using const_reference = const int&;
                explicit QueueList_iterator(node* pos):_pos(pos) {}
             ~QueueList_iterator() = default;
         };
         QueueList_iterator begin() const{return QueueList_iterator(first);};
         QueueList_iterator end() const{return QueueList_iterator(last);}
         QueueList():first(nullptr),last(nullptr),size_(0){};
         ~QueueList(){clear();}
         T front() {return first->value;}
         T back() {return last->value;}
            bool empty() const {return first==nullptr;}
            int size() {return size_;}
            void pop_front() {
             if (first) {
                 node* temp = first;
                 first = first->next;
                 delete temp;
             }
             if (!first) {
                 last = nullptr;
             }
             --size_;
            }
            void push_back(const T &value) {
             node *element = new node{nullptr, value};
             if (empty()) {
                 first = element;
             }
             else
             {
                 last->next = element;
             }
             last = element;
             ++size_;
            }
            void clear() {
             while (first) {
                 pop_front();
             }
            }
        };
