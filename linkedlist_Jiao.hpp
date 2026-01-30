#pragma once
#ifndef LINKEDLIST_JIAO_HPP
#define LINKEDLIST_JIAO_HPP

#include<iostream>
using namespace std;
template <typename T>class LinkedList;
//node class 
template<typename T>
class Node {
private:
    T data;
    Node<T>* next = nullptr;
    Node<T>* previous = nullptr;

public:
    //constructors
    Node() {

    }
    Node(T data) {
        this->data = data;
    }
    Node(T data, Node<T>* next, Node<T>* previous) {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
    //setters and getters
    T getData() {
        return this->data;
    }
    void setData(T data) {
        this->data = data;
    }
    Node<T>* getNext() {
        return this->next;
    }
    void setNext(Node<T>* next) {
        this->next = next;
    }
    Node<T>* getPrevious() {
        return this->previous;
    }
    void setPrevious(Node<T>* previous) {
        this->previous = previous;
    }
    //friend with LinkedList
    friend class LinkedList<T>;
};

//LinkedList class
template<typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

public:
    //constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        this->size = 0;
    }
    //destructor
    virtual~LinkedList() {
        Node<T>* newHead = head;
        while (newHead != nullptr) {
            Node<T>* temp = newHead;
            newHead = newHead->getNext();
            free(temp);
            temp = nullptr;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    //add a node to the front
    void AddToFront(T data) {
        Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
        newNode->setData(data);
        if (head == nullptr) {
            newNode->setNext(nullptr);
            newNode->setPrevious(nullptr);
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->setNext(head);
            newNode->setPrevious(nullptr);
            head->setPrevious(newNode);
            head = newNode;
        }
        size++;
    }
    //add a node to the end
    void AddToEnd(T data) {
        Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
        newNode->setData(data);
        if (tail == nullptr) {
            newNode->setNext(nullptr);
            newNode->setPrevious(nullptr);
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->setNext(nullptr);
            newNode->setPrevious(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
        size++;
    }
    //add a node to where we point
    void AddAtIndex(T data, int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Index is out of range.");
        }
        else if (index == 0) {
            AddToFront(data);
        }
        else if (index == size) {
            AddToEnd(data);
        }
        else {
        Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->getNext();
            }
            Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
            newNode->setData(data);
            newNode->setNext(current);
            newNode->setPrevious(current->getPrevious());
            current->getPrevious()->setNext(newNode);
            current->setPrevious(newNode);
            size++;
        }
    }
    //add a node before where we point
    void AddBefore(Node<T>* ptclNode, T data) {
        if (ptclNode->getPrevious() == nullptr) {
            AddToFront(data);
        }
        else {
            Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
            newNode->setData(data);
            newNode->setNext(ptclNode);
            newNode->setPrevious(ptclNode->getPrevious());
            ptclNode->getPrevious()->setNext(newNode);
            ptclNode->setPrevious(newNode);
            size++;
        }
    }
    //add a node after where we point
    void AddAfter(Node<T>* ptclNode, T data) {
        if (ptclNode->getNext() == nullptr) {
            AddToEnd(data);
        }
        else {
            Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
            newNode->setData(data);
            newNode->setNext(ptclNode->getNext());
            newNode->setPrevious(ptclNode);
            ptclNode->getNext()->setPrevious(newNode);
            ptclNode->setNext(newNode);
            size++;
        }
    }
    //move the front node
    T RemoveFromFront() {
        if (head == nullptr) {
            throw out_of_range("This LinkedList is empty!");
        }
        else {
            Node<T>* current = head;
            T data = current->getData();
            head = current->getNext();
            if (head != nullptr) {
                head->setPrevious(nullptr);
            }
            size--;
            free(current);
            current = nullptr;
            return data;
        }
    }
    //move the end node
    T RemoveFromEnd() {
        if (tail == nullptr) {
            throw std::out_of_range("This LinkedList is empty!");
        }
        Node<T>* current = tail;
        T data = current->getData();
        tail = current->getPrevious();
        if (tail != nullptr) {
            tail->setNext(nullptr);
        }
        size--;
        free(current);
        current = nullptr;
        return data;
    }
    //remove the first node which have the expected value
    void RemoveTheFirst(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == data) {
                if (current == head) {
                    RemoveFromFront();
                }
                else if (current == tail) {
                    RemoveFromEnd();
                }
                else {
                    current->getNext()->setPrevious(current->getPrevious());
                    current->getPrevious()->setNext(current->getNext());
                    free(current);
                    current = nullptr;
                    size--;
                }
                break;
            }
            current = current->getNext();
        }
    }
    //move all the node which have the expected value
    void RemoveAllOf(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == data) {
                Node<T>* temp = current;
                current = current->getNext();
                if (temp == head) {
                    RemoveFromFront();
                }
                else if (temp == tail) {
                    RemoveFromEnd();
                }
                else {
                    temp->getNext()->setPrevious(temp->getPrevious());
                    temp->getPrevious()->setNext(temp->getNext());
                    free(temp);
                    temp = nullptr;
                    size--;
                }
            }
            else current = current->getNext();
        }
    }
    //move the node before specific node
    T RemoveBefore(Node<T>* ptclNode) {
        if (ptclNode == head) throw out_of_range("Index is oout of range.");
        else{
            Node<T>* newNode = ptclNode->getPrevious();
            T data = newNode->getData();
            if (newNode != head) {
                newNode->getPrevious()->setNext(ptclNode);
                ptclNode->setPrevious(newNode->getPrevious());
            }
            else{
                ptclNode->setPrevious(newNode->getPrevious());
                head = ptclNode;
            }
            free(newNode);
            newNode = nullptr;
            size--;
            return data;
        }
    }
    //move the node after specific node
    T RemoveAfter(Node<T>* ptclNode) {
        if (ptclNode == tail) throw out_of_range("Index is out of range.");
        else{
            Node<T>* newNode = ptclNode->getNext();
            T data = newNode->getData();
            if (newNode != tail) {
                newNode->getNext()->setPrevious(ptclNode);
                ptclNode->setNext(newNode->getNext());
            }
            else {
                ptclNode->setNext(newNode->getNext());
                tail = ptclNode;
            }
            free(newNode);
            newNode = nullptr;
            size--;
            return data;
        }
    }
    //determine whether a node contains the specific value
    bool ElementExists(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == data)
                return true;
            current = current->getNext();
        }
        return false;
    }
    //find and return the first node which has the specific value
    Node<T>* Find(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == data)
                return current;
            current = current->getNext();
        }
        return nullptr;
    }
    //get the index the first node is which has the specific value
    int IndexOf(T data) {
        Node<T>* current = head;
        for (int i = 0; i < size; i++) {
            if (current->getData() == data)
                return i;
            current = current->getNext();
        }
        return -1;
    }
    //return the first node
    T RetrieveFront() {
        if(head==nullptr) throw out_of_range("This LinkedList is empty!");
        else return head->getData();
    }
    //return the end node
    T RetrieveEnd() {
        if(head==nullptr) throw out_of_range("This LinkedList is empty!");
        else return tail->getData();
    }
    //return the node we point
    T Retrieve(int index) {
        if (index < 0 || index > size - 1) {
            throw out_of_range("Index is out of range.");
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->getNext();
            }
            return current->getData();
        }
    }
    //just print the list when it is not empty
    void PrintList() {
        if (!isEmpty()) {
            Node<T>* current = head;
            cout << "Size: " << size << " :: ";
            while (current != nullptr) {
                cout << current->getData();
                if (current->getNext() != nullptr) {
                    cout << '=';
                }
                current = current->getNext();
            }
            cout << endl;
        }
        else return;
    }
    //determine the list is empty or nor
    bool isEmpty() {
        return (size == 0);
    }
    //delete each node
    void Empty(){
        while(size){
            RemoveFromFront();
        }
        head = nullptr;
        tail = nullptr;
    }
    //return the size of the list
    int Length() {
        return size;
    }
};

#endif
