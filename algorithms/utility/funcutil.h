#include <algorithm>

template<class T,
         template <class, class...> class Container,
         class UnaryOperator,
         class... Args>
auto
fmap(Container<T, Args...> con, UnaryOperator op)
        -> Container<decltype(op(std::declval<T>()))> // Container<op(T)>
{
    using ReturnType = decltype(op(std::declval<T>()));

    Container<ReturnType> ret;

    if (con.empty()) {
        return ret;
    }

    auto ins = std::inserter(ret, ret.begin());
    std::transform(con.begin(), con.end(), ins, [&op](T t) { return op(t); });

    return ret;
}

template<class T,
         template <class, class...> class Container,
         class BinaryOperator,
         class... Args>
auto
reduce(Container<T, Args...> con, T init, BinaryOperator bop)
        -> T
{
    if (con.empty()) {
        return init;
    }

    T ret = init;
    for (const auto& element : con) {
        ret = bop(ret, element);
    }

    return ret;
}
