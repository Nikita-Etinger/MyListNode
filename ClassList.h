#pragma once

template <typename T>

struct Node {
	T data;
	Node<T>* next=nullptr;



};
template <typename T>
class List {
	Node<T>*head=nullptr;
	int counter = 0;
public:
	List(){}
	~List() {
		Node<T>* next = head->next;
		while(next!=nullptr) {
			delete[] head;
			head = next;
			next = head->next;
		}
		delete[]head;
	}
	void push(T data) {
		Node<T>* newNode= new Node<T>{data};
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
	void insert(T data,int index) {
		if (index < counter) {
			Node<T>* newNode{ data };
			int iters = 0;
			Node<T>* iter = head;
			for (int i = 0; i < index; i++) {
				iter = iter->next;
			}
			Node<T>* buf = iter->next;
			iter->next = newNode;
			newNode = buf;
			counter++;
		}
	}
	void deleteHead(int index) {
		if (counter != 0) {
			Node<T>* buf = head;
			head = buf->next;
			delete[]buf;
		}
	}

	//void deleteIndex(int index) {
	//	if (index < counter) {
	//		int iters = 0;
	//		Node<T>* iter = head;
	//		for (int i = 0; i < index; i++) {
	//			iter = iter->next;
	//		}
	//		Node<T>* inter2 = iter->next;
	//		delete[]
	//		iter->next = newNode;
	//		newNode = buf;

	//		counter--;
	//	}


	//}

	void show() {
		if (head != nullptr) {
			Node<T>* iter = head;
			while (iter->next != nullptr) {
				std::cout << iter->data << " ";
				iter = iter->next;
			}
			std::cout << iter->data << " ";

		}


	}

};
