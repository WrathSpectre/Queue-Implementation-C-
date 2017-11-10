#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {

private:
    struct Node {
        T _data;
        Node *next;
    };

    Node *head, *tail;
    unsigned _size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    ~Queue() {
        delete head;
    }

    void push_back(const T data) {
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

    void pop_front() {
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

    T front() const {
        if(head == nullptr)
            throw std::runtime_error("error: empty queue");

        return head->_data;
    }

    T back() const {
      if(tail == nullptr)
          throw std::runtime_error("error: empty queue");

        return tail->_data;
    }

    const T &operator[](const unsigned index) const {
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

    unsigned size() const {
        return _size;
    }

    unsigned isEmpty() const {
        return head == nullptr ? true : false;
    }
};

#endif
