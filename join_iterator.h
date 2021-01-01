//
// Created by Dell on 2020-12-20.
//

#include <iostream>

template<typename Iterator>
class join_iterator {
public:
    join_iterator(Iterator first_begin, Iterator first_end, Iterator second_begin, Iterator second_end) :
            second{false}, first_begin{first_begin}, first_end{first_end}, second_begin{second_begin},
            second_end{second_end} {}

    using value_type = typename Iterator::value_type;
    using iterator_category = std::output_iterator_tag;
    using difference_type = typename Iterator::difference_type;
    using pointer = value_type *;
    using reference = value_type &;

    Iterator &operator++() {
        if (!second) {
            ++first_begin;
            if (first_begin != first_end) {
                return first_begin;
            }
            second = true;
            first_begin = second_begin;
            return first_begin;
        } else {
            ++first_begin;
            if (first_begin != second_end) {
                return first_begin;
            }
        }
    }

    Iterator operator++(int n) {
        Iterator itr = first_begin;
        if (second) {
            itr = second_begin;
        }
        operator++();
        return itr;
    }

    bool operator==(join_iterator &other) const {
        return *this->first_begin == *other.first_begin;
    }

    bool operator!=(join_iterator &other) const {
        return *this->first_begin != *other.first_begin;
    }

    join_iterator &operator*() {
        return this;
    }

    bool second;
    Iterator first_begin;
    Iterator first_end;
    Iterator second_begin;
    Iterator second_end;
};
