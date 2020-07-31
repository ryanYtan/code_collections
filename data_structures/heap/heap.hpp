#include <vector>

// default minheap
template<class T>
class Heap
{
    private:
        size_t _size;
        std::vector<T> _heap;

        template<class Container>
        void _heapify(const Container& container);

        template<class Container, class Predicate>
        void _heapify(const Container& container, Predicate comparator);

        size_t _parent(size_t index)
        {
            return (index - 1) / 2;
        }

        size_t _left(size_t index)
        {
            return (index * 2) + 1;
        }

        size_t _right(size_t index)
        {
            return (index * 2) + 2;
        }

        void _sift_down(size_t index);
        void _sift_up(size_t index);

    public:
        Heap()
            : _size(0)
            , _heap(std::vector<T>())
        {}

        template<class Container>
        Heap(const Container& container)
            : _size(0)
        {
            Heap();

        }

        template<class Container>
        Heap(Container container);

        bool empty()        { return _size <= 0; }
        int size()          { return _size; }
        T peek()            { return _heap[0]; }

        void pop();
        void push(T t);
};
