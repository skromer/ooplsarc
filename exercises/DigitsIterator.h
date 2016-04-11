// ---------------
// DigitsIterator.h
// ---------------

#ifndef DigitsIterator_h
#define DigitsIterator_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag, iterator

using namespace std;

template <typename T>
class Digits_Iterator : public iterator<input_iterator_tag, T> {
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
        Digits_Iterator (const T& v) :
                _v (v)
            {}

        bool operator == (const Digits_Iterator& rhs) const {
            return (_v == rhs._v);}

        bool operator != (const Digits_Iterator& rhs) const {
            return !(*this == rhs);}

        T operator * () const {
            return _v % 10;}

        Digits_Iterator& operator ++ () {
            _v /= 10;
            return *this;}

        Digits_Iterator operator ++ (int) {
            Digits_Iterator x = *this;
            ++*this;
            return x;}};

#endif // DigitsIterator_h
