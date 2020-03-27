#include <vector>

template<class T>
class maxheap
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
        maxheap();
        maxheap(std::vector<T> v);
        ~maxheap();
        bool empty();
        int size();
        void push(T t);
        T peek();
        T extract_max();
};

template<class T>
void maxheap<T>::_swap(int i, int j)
{
    T tmp = _heap[i];
    _heap[i] = _heap[j];
    _heap[j] = tmp;
}

template<class T>
void maxheap<T>::_heapify(std::vector<T> list)
{
    for (T i : list) {
        _heap.push_back(i);
    }
    for (int i = _parent(_size - 1); i >= 0; i--) {
        _sift_down(i);
    }
}

template<class T>
int maxheap<T>::_parent(int index)
{
    return (index - 1) / 2;
}

template<class T>
int maxheap<T>::_left(int index)
{
    return (index * 2) + 1;
}

template<class T>
int maxheap<T>::_right(int index)
{
    return (index * 2) + 2;
}

template<class T>
void maxheap<T>::_sift_down(int index)
{
    T max = _heap[index];
    int max_index = index;
    if (_left(index) < _size && _heap[_left(index)] > max) {
        max_index = _left(index);
        max = _heap[_left(index)];
    }
    if (_right(index) < _size && _heap[_right(index)] > max) {
        max_index = _right(index);
        max = _heap[_right(index)];
    }
    if (max_index != index) {
        _swap(index, max_index);
        _sift_down(max_index);
    }
}

template<class T>
void maxheap<T>::_sift_up(int index)
{
    T parent = _heap[_parent(index)];
    T curr   = _heap[index];
    if (index > 0 && parent <= curr) {
        _swap(index, _parent(index));
        _sift_up(_parent(index));
    }
}

template<class T>
maxheap<T>::maxheap()
{
    _size = 0;
    _heap = std::vector<T>();
}

template<class T>
maxheap<T>::maxheap(std::vector<T> list)
{
    _size = 0;
    _heap = std::vector<T>();
    _heapify(list);
}

template<class T>
maxheap<T>::~maxheap()
{
}

template<class T>
bool maxheap<T>::empty()
{
    return _size <= 0;
}

template<class T>
int maxheap<T>::size()
{
    return _size;
}

template<class T>
void maxheap<T>::push(T t)
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
T maxheap<T>::peek()
{
    return _heap[0];
}

template<class T>
T maxheap<T>::extract_max()
{
    T max = _heap[0];
    _heap[0] = _heap[_size - 1];
    _size--;
    _sift_down(0);
    return max;
}
