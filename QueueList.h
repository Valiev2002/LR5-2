#pragma once
#include <iterator>
#include <iostream>
#include <memory>
class QueueList {
public:
    struct node {
        node *next;
        int value;
    };
private:
    node *first;
    node *last;
    friend std::ostream &operator<<(std::ostream &out, const QueueList &ql) {
        for (auto *node = ql.first; node != nullptr; node = node->next) {
            out << node->value << " ";
        }
        return out;
    }
    int size_;
public:
    class QueueList_iterator {
        node *_pos;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = int;
        using pointer = int*;
        using reference = int&;

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

        difference_type operator*() const { return _pos->value; }

        reference operator*() { return _pos->value; }
        node* operator->() { return _pos; }

        bool operator==(const QueueList_iterator &other) const { return _pos == other._pos; }

        bool operator!=(const QueueList_iterator &other) const { return _pos != other._pos; }
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

    int front() const { return first->value; }

    int back() const { return last->value; }

    bool empty() const { return first == nullptr; }

    size_t size() const { return size_; }

    void pop_front() {
        if (first != nullptr) {
            node *temp = first;
            first = first->next;
            delete temp;
            --size_;
        }

        else {
            last = nullptr;
            std::cout<<"QueueList is empty"<<std::endl;
        }
    }

    void push_back(const int &value) {
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

void print(const QueueList&lab) {
    for (const auto &e: lab) {
        std::cout << e << " <- ";
    }
    std::cout << "NULL" << std::endl;
}