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
        IntMatrix& negateMatrix();

        public:
        //default c'tor - given matrix dimensions, default value 0
        IntMatrix(const Dimensions dimensions, const int init_val = 0);
        //copy c'tor - construct new copy of a given matrix
        IntMatrix(const IntMatrix &IntMatrix);
        //default d'tor
        ~IntMatrix();
        //assignment operator between two intMatrix types
        IntMatrix& operator=(const IntMatrix& a);
        //create new matrix which it's diagonal elements initialized to n, else 0
        static IntMatrix Identity(int n);
        //get a matrix height
        int height() const;
        //get a matrix width
        int width() const;
        //get number of elements in matrix
        int size() const;
        //returns a new matrix set to a given matrix
        IntMatrix transpose() const;
        //returns a new matrix with the negative elements of a given matrix
        IntMatrix operator-() const;
        //read a given matrix (i , j) element
        const int& operator() (const int row, const int col) const;
        //access (with write permission) a given matrix (i , j) element
        int& operator() (const int row, const int col);
        //output operator
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix& mat);
        //returns a new boolean matrix, that contains for each element boolean variable defining whether each element meets condition < b
        IntMatrix operator< (const int b) const;
        //returns a new boolean matrix, that contains for each element boolean variable defining whether each element meets condition == b
        IntMatrix operator==(const int b) const;
        //returns a new boolean matrix, that contains for each element boolean variable defining whether each element meets condition <= b
        IntMatrix operator<=(const int b) const;
        //returns a new boolean matrix, that contains for each element boolean variable defining whether each element meets condition > b
        IntMatrix operator>(const int b) const;
        //returns a new boolean matrix, that contains for each element boolean variable defining whether each element meets condition >= b
        IntMatrix operator>=(const int b) const;
        //returns a new boolean matrix, that contains for each element boolean variable defining whether each element meets condition != b
        IntMatrix operator!=(const int b) const;
 
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

    //returns a new matrix - sum of two matrix
    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b);
    //returns a new matrix - subtraction of two matrix
    IntMatrix operator-(const IntMatrix& a, const IntMatrix& b);
    //returns a new matrix - sum of a and static matrix which all objects initialized to b
    IntMatrix operator+(const IntMatrix& a, const int b);
    //returns a new matrix - sum of a and static matrix which all objects initialized to b
    IntMatrix operator+(const int a, const IntMatrix& b);
    //returns a by reference - sum of a and static matrix which all objects initialized to b
    IntMatrix& operator+=(IntMatrix& a, const int b);
    //returns a by reference - sum of a and static matrix which all objects initialized to b
    IntMatrix& operator+=(const int a, IntMatrix& b);
    //returns true if and only if at least one of elements is 0, false otherwise
    bool any(const IntMatrix&);
    //returns true if and only if all elements are 0, false otherwise
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