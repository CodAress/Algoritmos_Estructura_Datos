#pragma once
#include "Node.hpp"
#ifdef NODE_H
#define NODE_H
template <class T>
class Iterator {
public:
    Iterator(Node<T>* node): _node(node) {}
    // Sobrecarga ++
    void operator++(){
        if(this->_node == nullptr) throw "Cannot move a null node";
        this->_node = this->_node->next;
    }
    // Sobrecarga -- (opcional)
    void operator--(){
        if(this->_node == nullptr) throw "Cannot move a null node";
        this->_node = this->_node->before;
    }
    // Sobrecarga *
    T operator*() {
        if(this->_node == nullptr) throw "Cannot return value from null pointer";
        return this->_node->value;
    }
    // Sobrecarga !=
    bool operator!=(const Iterator& other) const {
        return _node != other._node;
    }
    // Sobrecarga ==
    bool operator==(const Iterator& other) const {
        return _node == other._node;
    }
    // Sobrecarga =
    Iterator& operator=(const Iterator& other) {
        _node = other._node;
        return *this;
    }
/*
    // Sobrecarga ->
    T* operator->() {
        if(this->_node == nullptr) throw "Cannot return value from null pointer";
        return &this->_node->value;
    }
    // Sobrecarga +
    Iterator operator+(int n) {
        Iterator it = *this;
        for(int i = 0; i < n; i++) {
            ++it;
        }
        return it;
    }
    // Sobrecarga -
    Iterator operator-(int n) {
        Iterator it = *this;
        for(int i = 0; i < n; i++) {
            --it;
        }
        return it;
    }
    // Sobrecarga +=
    Iterator& operator+=(int n) {
        for(int i = 0; i < n; i++) {
            ++(*this);
        }
        return *this;
    }
    // Sobrecarga -=
    Iterator& operator-=(int n) {
        for(int i = 0; i < n; i++) {
            --(*this);
        }
        return *this;
    }
    // Sobrecarga []
    T& operator[](int n) {
        Iterator it = *this;
        for(int i = 0; i < n; i++) {
            ++it;
        }
        return *it;
    }
    // Sobrecarga <
    bool operator<(const Iterator& other) const {
        return _node < other._node;
    }
    // Sobrecarga >
    bool operator>(const Iterator& other) const {
        return _node > other._node;
    }
    // Sobrecarga <=
    bool operator<=(const Iterator& other) const {
        return _node <= other._node;
    }

*/
private:
    // 1. Nodo guía
    Node<T>* _node;
};
#endif // !NODE_H