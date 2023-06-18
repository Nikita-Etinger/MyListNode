#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* prev = nullptr;
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
            newNode->prev = tail;
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
            head->prev = newNode;
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
                Node<T>* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            counter--;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            counter--;
        }
    }

    void removeAt(int index) {
        if (index >= 0 && index < counter) {
            if (index == 0) {
                pop_front();
            }
            else if (index == counter - 1) {
                pop_back();
            }
            else {
                Node<T>* iter = head;
                for (int i = 0; i < index; i++) {
                    iter = iter->next;
                }
                Node<T>* prevNode = iter->prev;
                Node<T>* nextNode = iter->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete iter;
                counter--;
            }
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
                newNode->prev = iter;
                newNode->next = iter->next;
                iter->next->prev = newNode;
                iter->next = newNode;
                counter++;
            }
        }
    }

    void insertList(List<T>& otherList, int index) {
        if (index >= 0 && index <= counter) {
            if (otherList.empty()) {
                return;
            }

            if (index == 0) {
                Node<T>* otherHead = otherList.head;
                Node<T>* otherTail = otherList.tail;
                while (otherHead != nullptr) {
                    push_front(otherHead->data);
                    otherHead = otherHead->next;
                }
            }
            else if (index == counter) {
                Node<T>* otherHead = otherList.head;
                Node<T>* otherTail = otherList.tail;
                while (otherHead != nullptr) {
                    push_back(otherHead->data);
                    otherHead = otherHead->next;
                }
            }
            else {
                Node<T>* iter = head;
                for (int i = 0; i < index - 1; i++) {
                    iter = iter->next;
                }

                Node<T>* otherHead = otherList.head;
                Node<T>* otherTail = otherList.tail;
                while (otherHead != nullptr) {
                    Node<T>* newNode = new Node<T>{ otherHead->data };
                    newNode->prev = iter;
                    newNode->next = iter->next;
                    iter->next->prev = newNode;
                    iter->next = newNode;
                    iter = newNode;
                    otherHead = otherHead->next;
                    counter++;
                }
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
        std::cout << std::endl;
    }
};