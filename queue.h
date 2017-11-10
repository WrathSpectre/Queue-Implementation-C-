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
    Queue();
    ~Queue();

    void push_back(const T data);
    void pop_front();

    T front() const;
    T back() const;
    
    const T &operator[](const unsigned index) const;

    unsigned size() const;
    unsigned isEmpty() const;
};

#endif
