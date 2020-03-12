#include <ostream>

template<class T>
class Node
{
    public:
        ~Node();
        T data;
        Node<T> *next;
        Node<T> *prev;
        Node(T data);
        Node(T data, Node *next, Node *prev);
};

template<class T>
Node<T>::Node(T data) : data {data}, next {nullptr}, prev {nullptr} {}

template<class T>
Node<T>::Node(T data, Node *next, Node *prev)
        : data {data}, next {next}, prev {prev} {}

template<class T>
Node<T>::~Node() {}

template<class T>
class LinkedList
{
    private:
        const char* const _LL_ERANGE = "Index out-of-bounds";
        unsigned int _size;
        Node<T> *_head;
        Node<T> *_tail;
        Node<T> *_get(unsigned int index);
        bool _outofrange(unsigned int index);
    public:
        LinkedList();
        ~LinkedList();
        unsigned int size();
        bool empty();
        void insert(T data, unsigned int index);
        void insert_first(T data);
        void insert_last(T data);
        void remove(unsigned int index);
        void remove_first();
        void remove_last();
        T get(unsigned int index);
        T get_first();
        T get_last();

        template<typename U>
        friend std::ostream& operator<<(std::ostream &strm, const LinkedList<U>& l);
};

template<class T>
bool LinkedList<T>::_outofrange(unsigned int index)
{
    return index < 0 || index > _size - 1;
}

template<class T>
Node<T> *LinkedList<T>::_get(const unsigned int index)
{
    unsigned int mid = _size / 2;
    if (index < 0 || index > _size - 1) {
        return nullptr;
    } else if (index == 0) {
        return _head;
    } else if (index == _size - 1) {
        return _tail;
    } else if (index < mid) {
        unsigned int count = 0;
        Node<T> *curr = this->_head;
        while (count != index) {
            curr = curr->next;
            count++;
        }
        return curr;
    } else {
        unsigned int count = _size - 1;
        Node<T> *curr = this->_tail;
        while (count != index) {
            curr = curr->prev;
            count--;
        }
        return curr;
    }
}

template<class T>
LinkedList<T>::LinkedList()
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* curr = _head;
    Node<T>* next;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

template<class T>
unsigned int LinkedList<T>::size()
{
    return _size;
}

template<class T>
bool LinkedList<T>::empty()
{
    return _size <= 0;
}

template<class T>
void LinkedList<T>::insert(T data, unsigned int index)
{
    if (_outofrange(index) && index > _size) {
        throw std::out_of_range(_LL_ERANGE);
    }

    if (_size == 0) {
        Node<T> *new_node = new Node<T>(data);
        _head = new_node;
        _tail = new_node;
    } else if (index == 0) {
        Node<T> *new_node = new Node<T>(data);
        _head->prev = new_node;
        new_node->next = _head;
        _head = new_node;
    } else if (index == _size) {
        Node<T> *new_node = new Node<T>(data);
        _tail->next = new_node;
        new_node->prev = _tail;
        _tail = new_node;
    } else {
        Node<T> *new_node = new Node<T>(data);
        Node<T> *at = _get(index);
        Node<T> *before = at->prev;
        before->next = new_node;
        at->prev = new_node;
        new_node->next = at;
        new_node->prev = before;
    }

    _size++;
}

template<class T>
void LinkedList<T>::insert_first(T data)
{
    insert(data, 0);
}

template<class T>
void LinkedList<T>::insert_last(T data)
{
    insert(data, _size);
}

template<class T>
void LinkedList<T>::remove(unsigned int index)
{
    if (_outofrange(index)) {
        throw std::out_of_range(_LL_ERANGE);
    }

    Node<T> *to_delete = _get(index);

    if (_size == 1) {
        delete _head;
        _head = nullptr;
        _tail = nullptr;
    } else if (index == 0) {
        Node<T> *new_head = to_delete->next;
        new_head->prev = nullptr;
        delete _head;
        _head = new_head;
    } else if (index == _size - 1) {
        Node<T> *new_tail = to_delete->prev;
        new_tail->next = nullptr;
        delete _tail;
        _tail = new_tail;
    } else {
        Node<T> *before = to_delete->prev;
        Node<T> *after = to_delete->next;
        delete to_delete;
        before->next = after;
        after->prev = before;
    }
    _size--;
}

template<class T>
void LinkedList<T>::remove_first()
{
    remove(0);
}

template<class T>
void LinkedList<T>::remove_last()
{
    remove(_size - 1);
}

template<class T>
T LinkedList<T>::get(const unsigned int index)
{
    return _get(index)->data;
}

template<class T>
T LinkedList<T>::get_first()
{
    return get(0);
}

template<class T>
T LinkedList<T>::get_last()
{
    return get(_size - 1);
}

template<typename U>
std::ostream& operator<<(std::ostream &strm, const LinkedList<U> &l)
{
    if (l._size <= 0) {
        return strm << "[]";
    }
    Node<U> *curr = l._head;
    std::string contents;
    contents = std::to_string(curr->data);

    while (curr->next != nullptr) {
        curr = curr->next;
        contents += ", " + std::to_string(curr->data);
    }

    return strm << "[" << contents << "]";
}
