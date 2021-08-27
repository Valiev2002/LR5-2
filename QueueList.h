#pragma once
#include <iterator>
#include <iostream>
#include <memory>
template<class T>
class QueueList;

template<class T>
std::ostream &operator<<(std::ostream &out, const QueueList<T> &ql) {
    for (auto *node = ql.first; node != nullptr; node = node->next) {
        out << node->value << " ";
    }

    return out;
}

template<class T>
class QueueList {
    struct node {
        node *next;
        T value;
    };
private:
    node *first;
    node *last;
    friend std::ostream &operator
    <<<T>(
    std::ostream &out,
    const QueueList &ql
    );
    int size_;
public:
    class QueueList_iterator : public std::iterator<std::forward_iterator_tag, T> {
        node *_pos;
    public:
        explicit QueueList_iterator(node *pos) : _pos(pos) {}

        ~QueueList_iterator() = default;

        QueueList_iterator &operator=(const QueueList_iterator rhs) {
            _pos = rhs._pos;
            return *this;
        }

        QueueList_iterator &operator++() {
            _pos = _pos->next;
            return *this;
        }

        QueueList_iterator operator++(int) {
            QueueList_iterator temp = *this;
            ++(*this);
            return temp;
        }

        T operator*() const { return _pos->value; }

        T &operator*() { return _pos->value; }

        T *operator->() { return _pos; }

        bool operator==(const QueueList_iterator &rhs) const { return _pos == rhs._pos; }

        bool operator!=(const QueueList_iterator &rhs) const { return _pos != rhs._pos; }
    };

    const QueueList_iterator begin() const { return QueueList_iterator(first); };

    const QueueList_iterator end() const {
        return QueueList_iterator(nullptr);
    }

    QueueList_iterator begin() { return QueueList_iterator(first); }

    QueueList_iterator end() {
        return QueueList_iterator(nullptr);
    }

    QueueList() : first(nullptr), last(nullptr), size_(0) {};

    ~QueueList() { clear(); }

    T front() const { return first->value; }

    T back() const { return last->value; }

    bool empty() const { return first == nullptr; }

    size_t size() const { return size_; }

    void pop_front() {
        if (first != nullptr) {
            node *temp = first;
            first = first->next;
            delete temp;
        }
        if (first == nullptr) {
            last = nullptr;
        }
        --size_;
    }

    void push_back(const T &value) {
        node *element = new node{nullptr, value};
        if (empty()) {
            first = element;
        } else {
            last->next = element;
        }
        last = element;
        ++size_;
    }

    void clear() {
        while (first != nullptr) {
            pop_front();
        }
    }
};

template<class T>
void print(const QueueList<T> &lab) {
    for (const auto &e: lab) {
        std::cout << e << " <- ";
    }
    std::cout << "NULL" << std::endl;
}