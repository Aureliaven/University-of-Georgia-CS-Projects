#include <iostream>
typedef unsigned int uint;

using namespace std;

class Matrix {
  // private members here
  double * matrix;
  uint r;
  uint c;
  
 public:

  /**
   * Constructor, copy constructor, and destructor
   */
  Matrix(uint rows, uint cols);                 // constructor (all elements initialized to 0)
  Matrix(const Matrix & m);                     // copy constructor
  ~Matrix();                                    // destructor

  /**
   * Functions that allow arithmetic operations
   * on a Matrix, between either a Matrix and scalar
   * or a Matrix and a Matrix
   * Note that division between matrices is impossible
   */
  Matrix add(double s) const;                   // add scalar to this matrix
  Matrix add(const Matrix & m) const;           // add this matrix and another matrix
  Matrix subtract(double s) const;              // subtract scalar from this matrix
  Matrix subtract(const Matrix & m) const;      // subtract another matrix from this matrix
  Matrix multiply(double s) const;              // multiply this matrix by a scalar
  Matrix multiply(const Matrix & m) const;      // multiply this matrix by another matrix
  Matrix divide(double s) const;                // divide this matrix by a scalar

  /**
   * Returns a const for the number of rows or columns
   * in the Matrix
   */
  const uint numRows() const;                   // returns the number of rows
  const uint numCols() const;                   // returns the number of cols

  /**
   * Returns either a const reference or a reference
   * to the double at the given position in the Matrix
   */
  double & at(uint row, uint col);              // get/set element at row, col
  const double & at (uint row, uint col) const; // get element at row, col (when using a const object)

  /**
   * Operator overloads for members (Matrices)
   * between two Matrices or a Matrix and a scalar
   */
  void operator=(const Matrix & m);             // assignment operator overload
  double operator()(uint row, uint col);        // get/set element at row, col
  Matrix operator+(double s);                   // add Matrix to scalar
  Matrix operator+(const Matrix & m);           // add Matrix to Matrix
  Matrix operator-(double s);                   // subtract scalar from Matrix
  Matrix operator-(const Matrix & m);           // subtract Matrix from Matrix
  Matrix operator*(double s);                   // multiply Matrix by scalar
  Matrix operator*(const Matrix & m);           // multiply Matrix by Matrix
  Matrix operator/(double s);                   // divide Matrix by scalar
  Matrix operator-();                           // negate Matrix
   
}; // Matrix

/**
 * Operator overload for the stream insertion operator on a Matrix
 * @param os - the stream being returned
 * @param m - the matrix being inserted
 * @return - the stream post-insertion
 */
ostream & operator<<(ostream & os, const Matrix & m);
/**
 * Operator overloads for non-member scalars
 * @param s - the scalar to be operated with
 * @param m - the matrix to be operated with
 */
void operator+(double s, const Matrix & m);
void operator-(double s, const Matrix & m);
void operator*(double s, const Matrix & m);
void operator/(double s, const Matrix & m);
