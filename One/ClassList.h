#pragma once

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
class List {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int counter = 0;

public:
    List() {}
    ~List() {
        clear();
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>{ data };
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>{ data };
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        counter++;
    }

    void pop_back() {
        if (head != nullptr) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node<T>* iter = head;
                while (iter->next != tail) {
                    iter = iter->next;
                }
                delete tail;
                tail = iter;
                tail->next = nullptr;
            }
            counter--;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            counter--;
        }
    }

    void insert(T data, int index) {
        if (index <= counter) {
            if (index == 0) {
                push_front(data);
            }
            else if (index == counter) {
                push_back(data);
            }
            else {
                Node<T>* newNode = new Node<T>{ data };
                Node<T>* iter = head;
                for (int i = 0; i < index - 1; i++) {
                    iter = iter->next;
                }
                newNode->next = iter->next;
                iter->next = newNode;
                counter++;
            }
        }
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
        tail = nullptr;
        counter = 0;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return counter;
    }

    T front() {
        if (head != nullptr) {
            return head->data;
        }

    }

    T back() {
        if (tail != nullptr) {
            return tail->data;
        }

    }

    void show() {
        Node<T>* iter = head;
        while (iter != nullptr) {
            std::cout << iter->data << " ";
            iter = iter->next;
        }
         std::cout <<  std::endl;
    }
};