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
        delete data;
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
                    returnMat.data[n*i+j] = 1;
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
        for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                matrix.data[height*i + j] = this->data[width*j + i];
                            
            }
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
                matrix.data[height*(i - 1) + j] = -1*(this->data[height*(i - 1) + j]);
                            
            }
        }
        return matrix;
    }

    int& IntMatrix::operator() (const int row, const int col)
    {
        return this->data[(this->width())*(row - 1) + col];
        //return this->data[row*this->width() + col - 1];
    }

    const int& IntMatrix::operator() (const int row, const int col) const
    {
        return this->data[(this->width())*(row - 1) + col];
    }


    /*const int& IntMatrix::operator() (const int row, const int col) const
    {
        return this(row, col);
    }*/

    std::ostream& operator<<(std::ostream& os, const IntMatrix& mat)
    {
        os << printMatrix(mat.data, mat.dim) << std::endl;
        return os;
    }

    IntMatrix operator+(const IntMatrix& a, const IntMatrix& b)
    {
        IntMatrix matrix = IntMatrix(a.getDim());
        int height = a.height();        
        int width = a.width();
        for(int i = 0 ; i < height ; ++i)
        {
            for(int j = 0 ; j < width ; ++j)
            {
                std::cout << "sum of " << a(i, j) << " and " << b(i, j) << std::endl;
                matrix(i, j) = a(i, j) + b(i, j);
                std::cout << "matrix (" << i << ", " << j << ") equals " << matrix(i, j) << std::endl;
                if((i == 4) && (j == 1))
                {
                    std::cout << printMatrix(matrix.getData(), matrix.getDim());
                }
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
        for(int i = 0 ; i < width ; i++)
        {
            for(int j = 0 ; j < height ; j++)
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

    void operator+= (IntMatrix& a, const int b)
    {
        a = (a + b);
    }

    void operator+=(const int a, IntMatrix& b)
    {
        b += a;
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

    IntMatrix::iterator IntMatrix::begin() const
    {
        return iterator(this, 0);
    }

    IntMatrix::iterator IntMatrix::end() const
    {
        return iterator(this,(*this).size());
    }

}// namespace mtm