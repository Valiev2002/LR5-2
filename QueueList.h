#pragma once
#include "QueueList_iterator.h"
#include <iterator>
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
         class QueueList_iterator{
                node* _pos;
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = int; // Тип значения
                using difference_type = int; // Тип расстояния
                using pointer = int*; // Тип указателя
                using reference = int&; // Тип ссылки
                explicit QueueList_iterator(node* pos):_pos(pos) {}
             ~QueueList_iterator();
            };
         QueueList_iterator begin() const{return QueueList_iterator(first);};
         QueueList_iterator end() const{return QueueList_iterator(last);}
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

//constructor
template<class T>
        QueueList<T>::QueueList(): ptr(nullptr),first(nullptr),last(nullptr),size_(0){}
        //destructor
        template<class T>
                QueueList<T>::~QueueList() {
                    delete this;
                }
                                template<class T>
                                        int QueueList<T>::front() {
                                            return first->item;
                                        }
                                        template<class T>
                                                int QueueList<T>::back() {
                                                    return last->item;
                                                }
                                                template<class T>
                                                        bool QueueList<T>::empty() const {
                                                            if(first==nullptr){
                                                                return true;
                                                            }
                                                        }
                                                        template<class T>
                                                                int QueueList<T>::size() {
                                                                    return size_;
                                                                }
                                                                template<class T>
                                                                        void QueueList<T>::pop_front() {
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
                                                                        template<class T>
                                                                                void QueueList<T>::clear() {
                                                                                    while (first) {
                                                                                        pop_front();
                                                                                    }
                                                                                }
                                                                                template<class T>
                                                                                        void QueueList<T>::push_back(QueueList <T> &list, T value) {
                                                                                            node* elm = new node;
                                                                                            if (!first) {
                                                                                                first = elm;
                                                                                                last = elm;
                                                                                            }
                                                                                            else {
                                                                                                elm->previous = last;
                                                                                                last->next = elm;
                                                                                                last = elm;
                                                                                            }
                                                                                            size_++;
                                                                                        }
