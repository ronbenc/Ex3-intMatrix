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
 
        //an itertor class to iterate over matrices elements
        class iterator;

        //set iterator to the first element in matrix
        iterator begin();

        //set iterator to the end of a matrix
        iterator end(); 

        //an itertor class to iterate over constant matrices elements
        class const_iterator;

        //set iterator to the first element in a constant matrix
        const_iterator begin() const;

        //set iterator to the end of a cnstant matrix
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
    class IntMatrix::iterator
    {
        const IntMatrix* intMatrix;
        int index;
        iterator(const IntMatrix* intMatrix, int index);
        friend class IntMatrix;

    public:
        //dereference current element to access element
        int& operator*() const;

        //advance iterator to next element in a matrix (prefix)
        iterator& operator++();

        //advance iterator to next element in a matrix (postfix)
        iterator operator++(int);

        //true if iterator are equal iterators. false otherwise
        bool operator==(const iterator& it) const;

        //true if iterator are not equal iterators. false otherwise
        bool operator!=(const iterator& it) const;

        //iterator constructor
        iterator(const iterator&) = default;

        //iterator assigment operator
        iterator& operator=(const iterator&) = default;

        //iterator destructor
        ~iterator() = default;
    };

    //*************const_iterator********************************************************
    class IntMatrix::const_iterator
    {
        const IntMatrix* const intMatrix;
        int index;
        const_iterator(const IntMatrix* const intMatrix, int index);
        friend class IntMatrix;

    public:
        //dereference current element to access element (read-only)
        const int& operator*() const;

        //advance iterator to next element in a matrix (prefix)
        const_iterator& operator++();

        //advance iterator to next element in a matrix (postfix)
        const_iterator operator++(int);

        //true if iterator are equal iterators. false otherwise
        bool operator==(const const_iterator& it) const;

        //true if iterator are not equal iterators. false otherwise
        bool operator!=(const const_iterator& it) const;

        //iterator constructor
        const_iterator(const const_iterator&) = default;

        //iterator assigment operator
        const_iterator& operator=(const const_iterator&) = default;

        //iterator destructor
        ~const_iterator() = default;
    };
} // namespace mtm


#endif //EX3_INTMATRIX_H