#include "IntMatrix.h"
#include "Auxiliaries.h"
//#include <assert.h>

namespace mtm
{

    IntMatrix::IntMatrix(const Dimensions dimensions, const int init_val) : 
        dim(dimensions),
        element_num(dimensions.getRow() * dimensions.getCol()),
        data(new int[element_num])
    {
        for (int i = 0; i < element_num; i++)
        {
            data[i] = init_val;
        }
    }

    IntMatrix::IntMatrix(const IntMatrix &toCopy) : 
        dim(toCopy.dim),
        element_num(toCopy.element_num),
        data(new int[element_num])
    {
        for (int i = 0; i < element_num; i++)
        {
            data[i] = toCopy.data[i];
        }
    }

    IntMatrix::~IntMatrix()
    {
        delete[] data;//verify correctness
    }

    IntMatrix& IntMatrix::operator=(const IntMatrix &a)
    {
        dim = a.dim;
        element_num = a.element_num;
        {
            for (int i = 0; i < element_num; i++)
            {
                data[i] = a.data[i];
            }
        }
        return *this;
    }

    IntMatrix IntMatrix::Identity(int n)
    {   
        IntMatrix returnMat = IntMatrix({n, n});
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == j)
                {
                    returnMat(i , i) = 1;                    
                }
            }
        }
        return returnMat;
    }

    int IntMatrix::height() const
    {
        return this->dim.getRow();
    }

    int IntMatrix::width() const
    {
        return this->dim.getCol();
    }
    
    int IntMatrix::size() const
    {
        return this->element_num;
    }

    IntMatrix IntMatrix::transpose() const
    {
        Dimensions dim (this->dim.getCol(), this->dim.getRow());
        IntMatrix matrix = IntMatrix(dim);
        int height = this->IntMatrix::height();
        int width = this->IntMatrix::width();
        for(int n = 0; n < width*height; n++) 
        {
            int i = n / width;
            int j = n % width;
            matrix.data[n] = this->data[height*j + i];           
        }
        return matrix;
    }

    IntMatrix IntMatrix::operator-() const
    {
        IntMatrix matrix = IntMatrix(*this);
        int height = this->IntMatrix::height();
        int width = this->IntMatrix::width();
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                matrix(i, j) = -1*((*this)(i, j));
                            
            }
        }
        return matrix;
    }

    int& IntMatrix::operator() (const int row, const int col)
    {
        return this->data[this->width()*row + col];
    }

    const int& IntMatrix::operator() (const int row, const int col) const
    {
        return this->data[this->width()*row + col];
    }

    std::ostream& operator<<(std::ostream& os, const IntMatrix& mat)
    {
        os << printMatrix(mat.data, mat.dim) << std::endl;
        return os;
    }

    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b)
    {
        IntMatrix matrix = IntMatrix(Dimensions(a.height(), a.width()));
        int height = a.height();        
        int width = a.width();
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                matrix(i, j) = a(i, j) + b(i, j);
            }
        }
        return matrix;
    }

    IntMatrix operator-(const IntMatrix& a, const IntMatrix& b)
    {
        return a + (-b);
    }

    IntMatrix operator+(const IntMatrix& a, const int b)
    {
        IntMatrix matrix = IntMatrix(a);
        int height = a.height();
        int width = a.width();
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                matrix(i , j) += b;                
            }        
        }
        return matrix;
    }

    IntMatrix operator+(const int a, const IntMatrix& b)
    {
        return b + a;
    }

    IntMatrix& operator+= (IntMatrix& a, const int b)
    {
        a = (a + b);
        return a;
    }

    IntMatrix& operator+=(const int a, IntMatrix& b)
    {
        return b += a;
    }

    IntMatrix IntMatrix::operator<(const int b) const
    {
        int height = this->height();
        int width = this->width();
        IntMatrix matrix = IntMatrix(Dimensions(height, width));
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                matrix(i , j) = ((*this)(i , j) < b ? 1 : 0);
            }        
        }
        return matrix;
    }

    IntMatrix IntMatrix::operator==(const int b) const
    {
        int height = this->height();
        int width = this->width();
        IntMatrix matrix = IntMatrix(Dimensions(height, width));
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                matrix(i , j) = ((*this)(i , j) == b ? 1 : 0);                
            }        
        }
        return matrix;
    }

    IntMatrix IntMatrix::operator<=(const int b) const
    {
        int height = this->height();
        int width = this->width();
        IntMatrix matrix = IntMatrix(Dimensions(height, width));
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                matrix(i , j) = ((((*this)(i , j) == b) || (*this)(i , j) < b) ? 1 : 0);
            }        
        }
        return matrix;
    }

    IntMatrix IntMatrix::operator>(const int b) const
    {
        return ((*this) <= b).negateMatrix();
    }

    IntMatrix IntMatrix::operator>=(const int b) const
    {
        return ((*this) < b).negateMatrix();
    }

    IntMatrix IntMatrix::operator!=(const int b) const
    {
        return ((*this) == b).negateMatrix();
    }

    bool any(const IntMatrix& a)
    {
        int height = a.height();
        int width = a.width();
        bool res = false;
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                if(a(i , j) != 0)
                {
                    res = true;
                }
            }
        }
        return res;
    }

    bool all(const IntMatrix& a)
    {
        int height = a.height();
        int width = a.width();
        bool res = true;
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                if(a(i , j) == 0)
                {
                    res = false;
                }
            }
        }
        return res;
    }

    IntMatrix& IntMatrix::negateMatrix()
    {
        int height = this->height();
        int width = this->width();
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {               
                (*this)(i , j) = ((*this)(i , j) == 0 ? 1 : 0);
            }        
        }
        return *this;
    }
    
    const int* IntMatrix::getData() const
    {
        return this->data;
    }

    const mtm::Dimensions& IntMatrix::getDim() const
    {
        return this->dim;
    }


    //*************iterator********************************************************

    IntMatrix::iterator IntMatrix::begin()
    {
        return iterator(this, 0);
    }

    IntMatrix::iterator IntMatrix::end() 
    {
        return iterator(this,(*this).size());
    }

    IntMatrix::iterator::iterator(const IntMatrix* intMatrix, int index) :
        intMatrix(intMatrix),index(index){ }

    int& IntMatrix::iterator::operator*() const
    {
        return intMatrix->data[index];
    }

    IntMatrix::iterator& IntMatrix::iterator::operator++()
    {
        ++index;
        return *this;
    }

    IntMatrix::iterator IntMatrix::iterator::operator++(int)
    {
        iterator result = *this;
        ++*this;
        return result; 
    }

    bool IntMatrix::iterator::operator==(const iterator& i) const 
    {
        //assert(intMatrix == i.intMatrix);
        return index == i.index;
    }

    bool IntMatrix::iterator::operator!=(const iterator& i) const 
    {
        return !(*this == i);
    }

    //*************const_iterator********************************************************

    IntMatrix::const_iterator IntMatrix::begin() const
    {
        return const_iterator(this, 0);
    }

    IntMatrix::const_iterator IntMatrix::end() const
    {
        return const_iterator(this,(*this).size());
    }

    IntMatrix::const_iterator::const_iterator(const IntMatrix* intMatrix, int index) :
        intMatrix(intMatrix),index(index){ }

    const int& IntMatrix::const_iterator::operator*() const
    {
        return intMatrix->data[index];
    }

    IntMatrix::const_iterator& IntMatrix::const_iterator::operator++()
    {
        ++index;
        return *this;
    }

    IntMatrix::const_iterator IntMatrix::const_iterator::operator++(int)
    {
        const_iterator result = *this;
        ++*this;
        return result; 
    }

    bool IntMatrix::const_iterator::operator==(const const_iterator& i) const 
    {
        //assert(intMatrix == i.intMatrix);
        return index == i.index;
    }

    bool IntMatrix::const_iterator::operator!=(const const_iterator& i) const 
    {
        return !(*this == i);
    }

}// namespace mtm