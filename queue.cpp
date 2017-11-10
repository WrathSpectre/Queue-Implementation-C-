#include "queue.h"

template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete head;
}

template <typename T>
void Queue<T>::push_back(const T data) {
    if (tail == nullptr) {
        tail = new Node;
        tail->_data = data;
        tail->next = nullptr;

        head = new Node;
        head = tail;
    }

    else {
        Node *newNode = new Node;
        newNode->_data = data;
        newNode->next = nullptr;

        tail->next = newNode;
        tail = newNode;
    }

    _size++;
}

template <typename T>
void Queue<T>::pop_front() {
    if (tail == nullptr)
        throw std::runtime_error("error: empty queue");

    else if (tail == head) {
        delete tail;
        delete head;
        tail = nullptr;
        head = nullptr;
    }

    else {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    _size--;
}

template <typename T>
T Queue<T>::front() const {
    if(head == nullptr)
        throw std::runtime_error("error: empty queue");

    return head->_data;
}

template <typename T>
T Queue<T>::back() const {
    if (tail == nullptr)
        throw std::runtime_error("error: empty queue");

    return tail->_data;
}

template <typename T>
const T Queue<T>&operator[](const unsigned index) const {
   if (head == nullptr)
        throw std::runtime_error("error: empty queue");

    else if (index >= _size)
        throw std::out_of_range("error: out of scope");

    else {
        Node *temp = head;

        for (unsigned itr = 0; itr < index; ++itr)
            temp = temp->next;

        return temp->_data;
        delete temp;
    }
}

template <typename T>
unsigned Queue<T>::size() const {
    return _size;
}

template <typename T>
unsigned Queue<T>::isEmpty() const {
    return head == nullptr ? true : false;
}
