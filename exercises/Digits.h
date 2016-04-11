// ---------
// Digits.c++
// ---------

#ifndef Digits_h
#define Digits_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag, iterator

using namespace std;

template <typename T>
class Digits {
    private:
        T _v;

    public:
        class iterator : public std::iterator<input_iterator_tag, T> {
/*
            public:
                using iterator_category = input_iterator_tag;
                using value_type        = T;
                using difference_type   = ptrdiff_t;
                using pointer           = T*;
                using reference         = T&;
*/
            private:
                T _v;

            public:
                iterator (const T& v) :
                        _v (v)
                    {}

                bool operator == (const iterator& rhs) const {
                    return (_v == rhs._v);}

                bool operator != (const iterator& rhs) const {
                    return !(*this == rhs);}

                T operator * () const {
                    return _v % 10;}

                iterator& operator ++ () {
                    _v /= 10;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Digits (const T& v) :
                _v (v)
            {}

        iterator begin () const {
            return iterator(_v);}

        iterator end () const {
            return iterator(0);}};

#endif // Digits_h
