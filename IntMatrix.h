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
        //to check:
        //to do:
    };
    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b);
    IntMatrix operator-(const IntMatrix& a, const IntMatrix& b);
    IntMatrix operator+(const IntMatrix& a, const int b);
    IntMatrix operator+(const int a, const IntMatrix& b);
    IntMatrix& operator+= (IntMatrix& a, const int b);
    IntMatrix& operator+=(const int a, IntMatrix& b);
    //to check:
    IntMatrix operator<(const IntMatrix& a, const int b);

    //to do:
    
    IntMatrix operator>(const IntMatrix& a, const int b);
    IntMatrix operator<=(IntMatrix& a, const int b);
    IntMatrix operator>=(IntMatrix& a, const int b);
    IntMatrix operator==(IntMatrix& a, const int b);
    IntMatrix operator!=(IntMatrix& a, const int b);
} // namespace mtm

#endif //EX3_INTMATRIX_H