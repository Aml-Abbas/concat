#include <iostream>
#include <vector>
#include <deque>
#include "concatenation.h"

void test_concatenation() {
    using IntVector = std::vector<int>;
    IntVector a{1, 2, 3, 4, 5, 6, 7, 8};
    IntVector b{11, 12, 13, 14, 15};
    concatenation<IntVector> j(a, b);
    auto first7 = std::find(j.begin(), j.end(), 7);
    auto first12 = std::find(first7, j.end(), 12);
    std::deque<int> result;
    std::copy(first7, first12, std::back_inserter(result));
//    result ska nu innehålla {7,8,11};
}


void test_join_iterator() {
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{6, 7, 8, 9};

    using iter_type = decltype(a.begin());
    join_iterator<iter_type> joinIterator{
            a.begin(), a.end(), b.begin(), b.end()
    };

    while (joinIterator.first_begin != b.end()) {
        std::cout << *joinIterator.first_begin << ", ";
        joinIterator++;
    }
    std::cout << std::endl;

    std::vector<int> res;
    std::copy(joinIterator.first_begin,
              joinIterator.second_end,
              res.begin());
    std::cout << "res size = " << res.size();
    for (int re : res) {
        std::cout << re << ", ";
    }
    std::endl(std::cout);
}

int main() {

    return 0;
}
