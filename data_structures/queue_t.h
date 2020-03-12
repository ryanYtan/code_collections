#include "linkedlist.h"

template<class T>
class queue_t
{
    private:
        linkedlist<T> *_internal_list;
    public:
        queue_t();
        ~queue_t();
        unsigned int size();
        bool empty();
        void enqueue(T data);
        void dequeue();
        T peek();
        T get(const unsigned int index);

        template<typename U>
        friend std::ostream& operator<<(std::ostream &strm, const queue_t<U>& q);
};

template<class T>
queue_t<T>::queue_t()
{
    _internal_list = new linkedlist<T>();
}

template<class T>
queue_t<T>::~queue_t()
{
    delete _internal_list;
}

template<class T>
unsigned int queue_t<T>::size()
{
    return _internal_list->size();
}

template<class T>
bool queue_t<T>::empty()
{
    return _internal_list->empty();
}

template<class T>
void queue_t<T>::enqueue(T data)
{
    _internal_list->insert_last(data);
}

template<class T>
void queue_t<T>::dequeue()
{
    _internal_list->remove_first();
}

template<class T>
T queue_t<T>::peek()
{
    return _internal_list->get_first();
}

template<class T>
T queue_t<T>::get(const unsigned int index)
{
    return _internal_list->get(index);
}

/**
 * Unsure how to get << operator overloading from _internal_list
 */
template<typename U>
std::ostream& operator<<(std::ostream &strm, const queue_t<U> &q)
{
    if (q._internal_list->size() <= 0) {
        return strm << "[]";
    }

    std::string contents = std::to_string(q._internal_list->get_first());

    // O(n^2) get, will fix
    for (unsigned int i = 1; i < q._internal_list->size(); i++) {
        contents += ", " + std::to_string(q._internal_list->get(i));
    }

    return strm << "[" << contents << "]";
}
