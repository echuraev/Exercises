#include <iostream>
#include <vector>

template <typename T>
class Node
{
public:
    Node(T val) : m_next(NULL), m_val(val)
    {}
    ~Node() {}
    inline T& getValue() {return m_val;}
    inline Node<T> *getNext() {return m_next;}
    inline void setNext(Node<T> *next) {m_next = next;}
private:
    Node<T> *m_next;
    T m_val;
};

template <typename T>
class Queue
{
public:
    virtual size_t size() = 0;
    virtual void push(const T& val) = 0;
    virtual void pop() = 0;
    virtual T& front() = 0;
    virtual T& back() = 0;
    virtual bool empty() = 0;
};

template <typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() : m_current(0), m_first(NULL), m_last(NULL)
    {}
    ~LinkedQueue() {}
    virtual inline size_t size() {return m_current;}
    virtual void push(const T& val)
    {
        if (m_first == NULL)
        {
            m_first = new Node<T>(val);
            m_last = m_first;
        }
        else
        {
            m_last->setNext(new Node<T>(val));
            m_last = m_last->getNext();
        }
        m_current++;
    }
    virtual void pop()
    {
        if (m_first != NULL)
        {
            Node<T> *tmp = m_first;
            m_first = m_first->getNext();
            delete tmp;
            m_current--;
        }
    }
    virtual inline T& front() {return m_first->getValue();}
    virtual inline T& back() {return m_last->getValue();}
    virtual inline bool empty() {return m_current == 0;}
private:
    unsigned int m_current;
    Node<T> *m_first;
    Node<T> *m_last;
};

template <typename T>
class VectorQueue : public Queue<T>
{
public:
    VectorQueue() {}
    ~VectorQueue() {}
    virtual inline size_t size() {return m_vector.size();}
    virtual inline void push(const T& val) {m_vector.push_back(val);}
    virtual inline void pop() {m_vector.erase(m_vector.begin());}
    virtual inline T& front() {return m_vector.front();}
    virtual inline T& back() {return m_vector.back();}
    virtual inline bool empty() {return m_vector.empty();}
private:
    std::vector<T> m_vector;
};

template <typename T>
void printAllQueue(Queue<T> *queue)
{
    if (queue->empty())
        return;
    std::cout << "Q1 size: " << queue->size() << ", first: " << queue->front() << ", last: " << queue->back() << std::endl;
    while (!queue->empty())
    {
        std::cout << queue->front() << '\t';
        queue->pop();
    }
    std::cout << std::endl;
}

int main()
{
    Queue<char> *q1 = new LinkedQueue<char>();
    Queue<int> *q2 = new VectorQueue<int>();

    q1->push('a');
    q1->push('b');
    q1->push('c');

    printAllQueue(q1);

    q2->push(1);
    q2->push(2);
    q2->push(3);
    q2->push(4);
    q2->push(5);

    printAllQueue(q2);

    return 0;
}