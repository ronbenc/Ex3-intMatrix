#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm
{
    class IntMatrix
    {
        private:
        Dimensions dim;
        int element_num;
        int* data;
        const int* getData() const;
        const mtm::Dimensions& getDim() const;
        IntMatrix& negateMatrix();

        public:
        IntMatrix(const Dimensions dimensions, const int init_val = 0);
        IntMatrix(const IntMatrix &IntMatrix);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& a);
        static IntMatrix Identity(int n);
        int height() const;
        int width() const;
        int size() const;
        IntMatrix transpose() const;
        IntMatrix operator-() const;
        const int& operator() (const int row, const int col) const;
        int& operator() (const int row, const int col);
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix& mat);
        IntMatrix operator< (const int b) const;
        IntMatrix operator==(const int b) const;
        IntMatrix operator<=(const int b) const;
        IntMatrix operator>(const int b) const;//negate <=
        IntMatrix operator>=(const int b) const;//negate <
        IntMatrix operator!=(const int b) const;//negate ==
 
        class iterator;//Capital i?
        
        iterator begin();
        iterator end(); 

        class const_iterator;//Capital i? 
        const_iterator begin() const;
        const_iterator end() const; 

    };

    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b);
    IntMatrix operator-(const IntMatrix& a, const IntMatrix& b);
    IntMatrix operator+(const IntMatrix& a, const int b);
    IntMatrix operator+(const int a, const IntMatrix& b);
    IntMatrix& operator+=(IntMatrix& a, const int b);
    IntMatrix& operator+=(const int a, IntMatrix& b);
    bool any(const IntMatrix&);
    bool all(const IntMatrix&);
    
    //*************iterator********************************************************

    class IntMatrix::iterator //Capital i?
    {
        const IntMatrix* intMatrix;
        int index;
        iterator(const IntMatrix* intMatrix, int index);
        friend class IntMatrix;

    public:
        int& operator*() const;
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
        iterator(const iterator&) = default;
        iterator& operator=(const iterator&) = default;
        ~iterator() = default;
    };

    //*************const_iterator********************************************************
    class IntMatrix::const_iterator //Capital i?
    {
        const IntMatrix* const intMatrix;
        int index;
        const_iterator(const IntMatrix* const intMatrix, int index);
        friend class IntMatrix;

    public:
        const int& operator*() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& it) const;
        bool operator!=(const const_iterator& it) const;
        const_iterator(const const_iterator&) = default;
        const_iterator& operator=(const const_iterator&) = default;
        ~const_iterator() = default;
    };


} // namespace mtm


#endif //EX3_INTMATRIX_H