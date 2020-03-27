#include <vector>

template<class T>
class minheap
{
    private:
        int _size;
        std::vector<T> _heap;

        void _swap(int i, int j);
        void _heapify(std::vector<T>);
        int _parent(int index);
        int _left(int index);
        int _right(int index);
        void _sift_down(int index);
        void _sift_up(int index);
    public:
        minheap();
        minheap(std::vector<T> v);
        ~minheap();
        bool empty();
        int size();
        void push(T t);
        T peek();
        T extract_min();
};

template<class T>
void minheap<T>::_swap(int i, int j)
{
    T tmp = _heap[i];
    _heap[i] = _heap[j];
    _heap[j] = tmp;
}

template<class T>
void minheap<T>::_heapify(std::vector<T> list)
{
    for (T i : list) {
        _heap.push_back(i);
    }
    for (int i = _parent(_size - 1); i >= 0; i--) {
        _sift_down(i);
    }
}

template<class T>
int minheap<T>::_parent(int index)
{
    return (index - 1) / 2;
}

template<class T>
int minheap<T>::_left(int index)
{
    return (index * 2) + 1;
}

template<class T>
int minheap<T>::_right(int index)
{
    return (index * 2) + 2;
}

template<class T>
void minheap<T>::_sift_down(int index)
{
    T min = _heap[index];
    int min_index = index;
    if (_left(index) < _size && _heap[_left(index)] < min) {
        min_index = _left(index);
        min = _heap[_left(index)];
    }
    if (_right(index) < _size && _heap[_right(index)] < min) {
        min_index = _right(index);
        min = _heap[_right(index)];
    }
    if (min_index != index) {
        _swap(index, min_index);
        _sift_down(min_index);
    }
}

template<class T>
void minheap<T>::_sift_up(int index)
{
    T parent = _heap[_parent(index)];
    T curr   = _heap[index];
    if (index > 0 && parent >= curr) {
        _swap(index, _parent(index));
        _sift_up(_parent(index));
    }
}

template<class T>
minheap<T>::minheap()
{
    _size = 0;
    _heap = std::vector<T>();
}

template<class T>
minheap<T>::minheap(std::vector<T> list)
{
    _size = 0;
    _heap = std::vector<T>();
    _heapify(list);
}

template<class T>
minheap<T>::~minheap()
{
}

template<class T>
bool minheap<T>::empty()
{
    return _size <= 0;
}

template<class T>
int minheap<T>::size()
{
    return _size;
}

template<class T>
void minheap<T>::push(T t)
{
    _size++;
    if (_size > _heap.size()) {
        _heap.push_back(t);
    } else {
        _heap[_size - 1] = t;
    }
    _sift_up(_size - 1);
}

template<class T>
T minheap<T>::peek()
{
    return _heap[0];
}

template<class T>
T minheap<T>::extract_min()
{
    T max = _heap[0];
    _heap[0] = _heap[_size - 1];
    _size--;
    _sift_down(0);
    return max;
}
