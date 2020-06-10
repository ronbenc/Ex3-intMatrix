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
    };


    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b);
    
    //to check:
    
    IntMatrix operator-(const IntMatrix& a, const IntMatrix& b);
    IntMatrix operator+(const IntMatrix& a, const int b);
    IntMatrix operator+(const int a, const IntMatrix& b);
    void operator+=(IntMatrix& a, const int b);
    void operator+=(const int a, IntMatrix& b);

    //to do:    
    

} // namespace mtm

#endif //EX3_INTMATRIX_H