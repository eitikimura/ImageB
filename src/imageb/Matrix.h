#include <assert.h>  // Defines the assert function.

//!A class for Matrix representation

class Matrix {

public:

//! Default Constructor. Creates a 1 by 1 matrix; sets value to zero. 
Matrix () {
  nRow_ = 1; nCol_ = 1;
  data_ = new double [1];  // Allocate memory
  set(0.0);                // Set value of data_[0] to 0.0
}

//! Regular Constructor. Creates an nR by nC matrix; sets values to zero.
/*! 
   If number of columns is not specified, it is set to 1.
*/
Matrix(long nR, long nC = 1) {
  assert(nR > 0 && nC > 0);    // Check that nC and nR both > 0.
  nRow_ = nR; nCol_ = nC;
  
  if ( nR != 0 && nC != 0  )
    {
      data_ = new double [nR*nC];  // Allocate memory
      assert(data_ != 0);          // Check that memory was allocated
      set(0.0);
    }    // Set values of data_[] to 0.0
}


//! Copy Constructor.
/*!
Used when a copy of an object is produced 
(e.g., passing to a function by value)
*/
Matrix(const Matrix& mat) {
  this->copy(mat);   // Call private copy function.
}

//! Destructor. Called when a Matrix object goes out of scope.
~Matrix() {
  delete [] data_;   // Release allocated memory
}

//! Assignment operator function.
/*!
 Overloads the equal sign operator to work with
 Matrix objects. */
Matrix& operator=(const Matrix& mat) {
  if( this == &mat ) return *this;  // If two sides equal, do nothing.
  delete [] data_;                  // Delete data on left hand side
  this->copy(mat);                  // Copy right hand side to l.h.s.
  return *this;
}

//! Simple "get" functions. Return number of rows.
long nRow() const { return nRow_; }

//! Simple "get" functions. Return number of columns.
long nCol() const { return nCol_; }

//! Parenthesis operator function.
/*!
  Allows access to values of Matrix via (i,j) pair.
  Example: a(1,1) = 2*b(2,3); 
  If column is unspecified, take as 1.
*/
double& operator() (long i, long j = 1) {
  assert(i > 0 && i <= nRow_);          // Bounds checking for rows
  assert(j > 0 && j <= nCol_);          // Bounds checking for columns
  return data_[ nCol_*(i-1) + (j-1) ];  // Access appropriate value
}

//! Parenthesis operator function (const version).
const double& operator() (long i, long j = 1) const{
  assert(i > 0 && i <= nRow_);          // Bounds checking for rows
  assert(j > 0 && j <= nCol_);          // Bounds checking for columns
  return data_[ nCol_*(i-1) + (j-1) ];  // Access appropriate value
}

//! Set function. Sets all elements of a matrix to a given value.
void set(double value) {
  long i, iData = nRow_*nCol_;
  for( i=0; i<iData; i++ )
    data_[i] = value;
}

//!set absolute value for all elements of a matrix
void abs()
{
  long i, iData = nRow_*nCol_;
  for( i=0; i<iData; i++ )
    data_[i] = abs(data_[i]);
}

//! find an element in matrix
int find( double val )
{
  long i, iData = nRow_*nCol_;
  
  for( i=0; i<iData; i++ )
  {
    if (data_[i] == val)
       return i; //retorna a posi��o do elemento
  }
  
  return -1;
}

//*********************************************************************
private:

// Matrix data.

//! Number of rows, columns
long nRow_, nCol_;  
//! Pointer used to allocate memory for data.
double* data_;     

//! Private copy function. Copies values from one Matrix object to another.
void copy(const Matrix& mat) {
  nRow_ = mat.nRow_;
  nCol_ = mat.nCol_;
  long i, iData = nRow_*nCol_;
  data_ = new double [iData];
  for(i = 0; i<iData; i++ )
    data_[i] = mat.data_[i];
}

double abs(double value)
{
  if (value < 0)
      value *= -1;
  
  return value;
}

}; // Class Matrix

