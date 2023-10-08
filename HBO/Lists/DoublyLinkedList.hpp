#pragma once
#include "Node.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <functional>
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/*
template<class T>
class DoublyLinkedList
{
private:
    Node<T> *_head;
    Node<T> *_tail;
    int _size;
public:
    DoublyLinkedList() : _head{ nullptr }, _tail{ nullptr }, _size{ 0 } {}
    ~DoublyLinkedList();
    void insertAtHead(T newElement);
    void insertAtTail(T newElement);
    void insertAt(T newElement, int position);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAt(int position);
    void printList();
    int getSize() { return _size; }
    bool isEmpty() { return _size == 0; }
    Node<T>* getHead() { return _head; }
    Node<T>* getTail() { return _tail; }
    Node<T>* getNodeAt(int position);
    void setHead(Node<T>* newHead) { _head = newHead; }
    void setTail(Node<T>* newTail) { _tail = newTail; }
};

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T> *currentNode = _head;
    Node<T> *nextNode = nullptr;
    while (currentNode != nullptr)
    {
        nextNode = currentNode->getNextNode();
        delete currentNode;
        currentNode = nextNode;
    }
}

template<class T>
void DoublyLinkedList<T>::insertAtHead(T newElement)
{
    Node<T> *newNode = new Node<T>(newElement);
    if (isEmpty())
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        newNode->setNextNode(_head);
        _head->setBeforeNode(newNode);
        _head = newNode;
    }
    _size++;
}

template<class T>
void DoublyLinkedList<T>::insertAtTail(T newElement)
{
    Node<T> *newNode = new Node<T>(newElement);
    if (isEmpty())
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        newNode->setBeforeNode(_tail);
        _tail->setNextNode(newNode);
        _tail = newNode;
    }
    _size++;
}

template<class T>
void DoublyLinkedList<T>::insertAt(T newElement, int position)
{
    if (position < 0 || position > _size)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    if (position == 0)
    {
        insertAtHead(newElement);
        return;
    }
    if (position == _size)
    {
        insertAtTail(newElement);
        return;
    }
    Node<T> *newNode = new Node<T>(newElement);
    Node<T> *currentNode = getNodeAt(position);
    Node<T> *beforeNode = currentNode->getBeforeNode();
    beforeNode->setNextNode(newNode);
    newNode->setBeforeNode(beforeNode);
    newNode->setNextNode(currentNode);
    currentNode->setBeforeNode(newNode);
    _size++;
}

template<class T>
void DoublyLinkedList<T>::deleteAtHead()
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node<T> *currentNode = _head;
    _head = _head->getNextNode();
    if (_head != nullptr)
    {
        _head->setBeforeNode(nullptr);
    }
    delete currentNode;
    _size--;
}

template<class T>
void DoublyLinkedList<T>::deleteAtTail()
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node<T> *currentNode = _tail;
    _tail = _tail->getBeforeNode();
    if (_tail != nullptr)
    {
        _tail->setNextNode(nullptr);
    }
    delete currentNode;
    _size--;
}

template<class T>
void DoublyLinkedList<T>::deleteAt(int position)
{
    if (position < 0 || position >= _size)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    if (position == 0)
    {
        deleteAtHead();
        return;
    }
    if (position == _size - 1)
    {
        deleteAtTail();
        return;
    }
    Node<T> *currentNode = getNodeAt(position);
    Node<T> *beforeNode = currentNode->getBeforeNode();
    Node<T> *nextNode = currentNode->getNextNode();
    beforeNode->setNextNode(nextNode);
    nextNode->setBeforeNode(beforeNode);
    delete currentNode;
    _size--;
}

template<class T>
void DoublyLinkedList<T>::printList()
{
    Node<T> *currentNode = _head;
    while (currentNode != nullptr)
    {
        std::cout << currentNode->getElement() << " ";
        currentNode = currentNode->getNextNode();
    }
    std::cout << std::endl;
}

template<class T>
Node<T>* DoublyLinkedList<T>::getNodeAt(int position)
{
    if (position < 0 || position >= _size)
    {
        std::cout << "Invalid position" << std::endl;
        return nullptr;
    }
    Node<T> *currentNode = _head;
    for (int i = 0; i < position; i++)
    {
        currentNode = currentNode->getNextNode();
    }
    return currentNode;
}
*/
template<class T>
class DoublyLinkedList
{
private:
    Node<T>* _inicio;
    Node<T>* _final;
    unsigned int _size;
    void _swap(Node<T>* a, Node<T>* b) {
        T temp = a->getElement();
        a->setElement(b->getElement());
        b->setElement(temp);
    }
public:
    DoublyLinkedList(): _inicio{ nullptr }, _final{ nullptr }, _size{ 0 } {}
    ~DoublyLinkedList() {
        while (_inicio)
        {
            pop_front();
            _inicio = _inicio->getNextNode();
        }
    }
    void push_back(T newElement) {
        Node<T>* newNode = new Node<T>(newElement);
        if (_inicio == nullptr) {
            _inicio = newNode;
            _final = newNode;
        }
        else {
            _final->setNextNode(newNode);
            newNode->setBeforeNode(_final);
            _final = newNode;
        }
        _size++;
    }

    void push_front(T newElement) {
        Node<T>* newNode = new Node<T>(newElement);
        if (_inicio == nullptr) {
            _inicio = newNode;
            _final = newNode;
        }
        else {
            newNode->setNextNode(_inicio);
            _inicio->setBeforeNode(newNode);
            _inicio = newNode;
        }
        _size++;
    }

    void pop_back() {
        if (_inicio == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node<T>* currentNode = _final;
        _final = _final->getBeforeNode();
        if (_final != nullptr) {
            _final->setNextNode(nullptr);
        }
        delete currentNode;
        _size--;
    }

    void pop_front() {
        if (_inicio == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node<T>* currentNode = _inicio;
        _inicio = _inicio->getNextNode();
        if (_inicio != nullptr) {
            _inicio->setBeforeNode(nullptr);
        }
        delete currentNode;
        _size--;
    }

    void insert(T newElement, int position) {
        if (position < 0 || position > _size) {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        if (position == 0) {
            push_front(newElement);
            return;
        }
        if (position == _size) {
            push_back(newElement);
            return;
        }
        Node<T>* newNode = new Node<T>(newElement);
        Node<T>* currentNode = getNodeAt(position);
        Node<T>* beforeNode = currentNode->getBeforeNode();
        beforeNode->setNextNode(newNode);
        newNode->setBeforeNode(beforeNode);
        newNode->setNextNode(currentNode);
        currentNode->setBeforeNode(newNode);
        _size++;
    }

    void erase(int position) {
        if (position < 0 || position >= _size) {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        if (position == 0) {
            pop_front();
            return;
        }
        if (position == _size - 1) {
            pop_back();
            return;
        }
        Node<T>* currentNode = getNodeAt(position);
        Node<T>* beforeNode = currentNode->getBeforeNode();
        Node<T>* nextNode = currentNode->getNextNode();
        beforeNode->setNextNode(nextNode);
        nextNode->setBeforeNode(beforeNode);
        delete currentNode;
        _size--;
    }

    void printList(std::function<void(Node<T>*)> printNode) {
        Node<T>* aux = _inicio;
        while (aux)
        {
	        printNode(aux);
	        aux = aux->getNextNode();
        }
        /*
        Node<T>* currentNode = _inicio;
        while (currentNode != nullptr) {
            std::cout << currentNode->getElement() << " ";
            currentNode = currentNode->getNextNode();
        }
        std::cout << std::endl;
        */
    }

    Node<T>* getNodeAt(int position) {
        if (position < 0 || position >= _size) {
            std::cout << "Invalid position" << std::endl;
            return nullptr;
        }
        Node<T>* currentNode = _inicio;
        for (int i = 0; i < position; i++) {
            currentNode = currentNode->getNextNode();
        }
        return currentNode;
    }

    void bubleSort(std::function<bool(T,T)> compare) {
        Node<T>* aux = this->_inicio;
        if(aux == nullptr) throw "Cannot sort an empty list";
        while(aux != this->_final) {
            if(compare(aux->getElement(),aux->getNextNode()->getElement())){
                this->_swap(aux,aux->getNextNode());//el intercambio debe depender de cada caso
                if(aux != this->_inicio)
                    aux = aux->getBeforeNode();
                continue;
            }
            aux = aux->getNextNode();
        }
    }

    Iterator<T> begin() {
        return Iterator<T>(_inicio);
    }

    Iterator<T> end() {
        return Iterator<T>(nullptr);
    }

    int getSize() { return _size; }
    bool isEmpty() { return _size == 0; }
    //Node<T>* getHead() { return _inicio; }
    //Node<T>* getTail() { return _final; }
    //void setHead(Node<T>* newHead) { _inicio = newHead; }
    //void setTail(Node<T>* newTail) { _final = newTail; }
};

#endif // !DOUBLY_LINKED_LIST_H