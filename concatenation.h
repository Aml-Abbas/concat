#include "join_iterator.h"

template<typename T>
class concatenation {
public:
    using value_type = typename T::value_type;
    using iter = join_iterator<typename T::iterator>;

    concatenation(T &a, T &b) : first(a.begin()), firstEnd(a.end()), second(b.begin()), secondEnd(b.end()) {}

    iter begin() {
        return join_iterator<typename T::iterator>(first, firstEnd, second, secondEnd);
    }

    //join_iterator where a and b are both at end
    iter end() {
        return join_iterator<typename T::iterator>(firstEnd, firstEnd, secondEnd, secondEnd);
    }

    //Start and end iterator for a and b
    typename T::iterator first;
    typename T::iterator firstEnd;
    typename T::iterator second;
    typename T::iterator secondEnd;
};
