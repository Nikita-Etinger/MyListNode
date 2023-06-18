#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
class List {
    Node<T>* head = nullptr;
    int counter = 0;

public:
    List() {}
    ~List() {
        while (head != nullptr) {
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>{ data };
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* iter = head;
            while (iter->next != nullptr) {
                iter = iter->next;
            }
            iter->next = newNode;
        }
        counter++;
    }

    void insert(T data, int index) {
        if (index <= counter) {
            Node<T>* newNode = new Node<T>{ data };
            if (index == 0) {
                newNode->next = head;
                head = newNode;
            }
            else {
                Node<T>* iter = head;
                for (int i = 0; i < index - 1; i++) {
                    iter = iter->next;
                }
                newNode->next = iter->next;
                iter->next = newNode;
            }
            counter++;
        }
    }

    void removeHead() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            counter--;
        }
    }

    void removeAt(int index) {
        if (index < counter) {
            if (index == 0) {
                removeHead();
            }
            else {
                Node<T>* iter = head;
                for (int i = 0; i < index - 1; i++) {
                    iter = iter->next;
                }
                Node<T>* temp = iter->next;
                iter->next = temp->next;
                delete temp;
                counter--;
            }
        }
    }

    void show() {
        Node<T>* iter = head;
        while (iter != nullptr) {
            std::cout << iter->data << " ";
            iter = iter->next;
        }
        std::cout << std::endl;
    }

    int size() {
        return counter;
    }

    bool empty() {
        return counter == 0;
    }
};