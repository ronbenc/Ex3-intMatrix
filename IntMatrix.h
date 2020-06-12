#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm
{
    class IntMatrix
    {
        Dimensions dim;
        int element_num;
        int* data;

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

        //to check:
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix& mat);

        //to do:
        

        const int* getData() const;//debug
        const mtm::Dimensions& getDim() const;//debug

        class iterator;//Capital i? 
        iterator begin();
        iterator end(); 

        class const_iterator;//Capital i? 
        iterator begin() const;
        iterator end() const; 

    };


    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b);
    
    //to check:
    
    IntMatrix operator-(const IntMatrix& a, const IntMatrix& b);
    IntMatrix operator+(const IntMatrix& a, const int b);
    IntMatrix operator+(const int a, const IntMatrix& b);
    void operator+=(IntMatrix& a, const int b);
    void operator+=(const int a, IntMatrix& b);

    //to do:    
    
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

} // namespace mtm


#endif //EX3_INTMATRIX_H