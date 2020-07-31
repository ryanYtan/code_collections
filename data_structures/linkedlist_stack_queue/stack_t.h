#include "linkedlist.h"

template<class T>
class stack_t
{
    private:
        linkedlist<T> *_internal_list;
    public:
        stack_t();
        ~stack_t();
        unsigned int size();
        bool empty();
        void push(T data);
        void pop();
        T peek();
        T get(const unsigned int index);

        template<typename U>
        friend std::ostream& operator<<(std::ostream &strm, const stack_t<U>& q);
};

template<class T>
stack_t<T>::stack_t()
{
    _internal_list = new linkedlist<T>();
}

template<class T>
stack_t<T>::~stack_t()
{
    delete _internal_list;
}

template<class T>
unsigned int stack_t<T>::size()
{
    return _internal_list->size();
}

template<class T>
bool stack_t<T>::empty()
{
    return _internal_list->empty();
}

template<class T>
void stack_t<T>::push(T data)
{
    _internal_list->insert_first(data);
}

template<class T>
void stack_t<T>::pop()
{
    _internal_list->remove_first();
}

template<class T>
T stack_t<T>::peek()
{
    return _internal_list->get_first();
}

template<class T>
T stack_t<T>::get(const unsigned int index)
{
    return _internal_list->get(index);
}

/**
 * Unsure how to get << operator overloading from _internal_list
 */
template<typename U>
std::ostream& operator<<(std::ostream &strm, const stack_t<U> &q)
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
