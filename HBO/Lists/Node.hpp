#pragma once
#ifndef NODE_H
#define NODE_H
template <class T>
class Node
{
private:
    T _element;
    Node<T> *_next;
    Node<T> *_before;
public:
    Node(const T newElement) : _element{ newElement }, _next{ nullptr }, _before{ nullptr } {}
    ~Node() { _next = nullptr; _before = nullptr; }
    void setNextNode(Node* newNode) { _next = newNode; }
    void setBeforeNode(Node* newNode) { _before = newNode; }
    Node* getNextNode() { return _next; }
    Node* getBeforeNode() { return _before; }
    T getElement() { return _element; }
    void setElement(T newElement) { _element = newElement; }
};
#endif // !NODE_H