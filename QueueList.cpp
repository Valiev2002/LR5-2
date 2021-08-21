#include "QueueList.h"
template<class T>
        QueueList_iterator<T>::QueueList_iterator(T *pos):_pos(pos) {}
template<class T>
QueueList_iterator<T>::~QueueList_iterator() = default;
//constructor
template<class T>
        QueueList<T>::QueueList(): ptr(nullptr),first(nullptr),last(nullptr),size_(0){}
        //destructor
        template<class T>
        QueueList<T>::~QueueList() {
            delete this;
        }
        //begin iterator
template<class T>
QueueList_iterator<T> QueueList<T>::begin() const {
    return QueueList_iterator<T>(first);
}
//end iterator
template<class T>
QueueList_iterator<T> QueueList<T>::end() const {
    return QueueList_iterator<T>(last);
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
        node* temp = reinterpret_cast<node *>(first);
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


