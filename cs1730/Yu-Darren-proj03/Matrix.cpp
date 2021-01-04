#include "Matrix.h"

Matrix::Matrix(uint rows, uint cols) {
  r = rows;
  c = cols;
  matrix = new double[r*c];
}

Matrix::Matrix(const Matrix & m) {
  r = m.r;
  c = m.c;
  matrix = new double[r*c];
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(matrix + j + (c*i)) = *(m.matrix + j + (c*i));
    }
  }
}

Matrix::~Matrix(){
  delete [] matrix;
}

Matrix Matrix::add(double s) const{
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) += s;
    }
  }
  return temp;
}

Matrix Matrix::add(const Matrix & m) const{
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) += *(this->matrix + j + (c*i));
    }
  }
  return temp;
}

Matrix Matrix::subtract(double s) const{
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) -= s;
    }
  }
  return temp;
}

Matrix Matrix::subtract(const Matrix & m) const{
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) -= *(this->matrix + j + (c+i));
    }
  }
  return temp;
}

Matrix Matrix::multiply(double s) const{
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) *= s;
    }
  }
  return temp;
}

Matrix Matrix::multiply(const Matrix & m) const{
  Matrix temp(r, m.c);
  for (uint i = 0; i < temp.r; i++) {
    for (uint j = 0; j < temp.c; j++) {
      double result = 0;
      for (uint x = 0; x < c; x++) {
	result +=
	  *(this->matrix + x + (i*c)) * *(m.matrix + j + (x*m.c));
      }
      *(temp.matrix + j + (m.c*i)) = result;
    }
  }
  return temp;
}

Matrix Matrix::divide(double s) const{
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) /= s;
    }
  }
  return temp;
}

const uint Matrix::numRows() const{
  return r;
}

const uint Matrix::numCols() const{
  return c;
}

double & Matrix::at(uint row, uint col){
  return *(matrix + col + (c*row));
}

const double & Matrix::at(uint row, uint col) const{
  return *(matrix + col + (c*row));
}

void Matrix::operator=(const Matrix & m){
  delete this->matrix;
  
}

double Matrix::operator()(uint row, uint col){
  return this->at(row, col);
}

Matrix Matrix::operator+(double s){
  Matrix temp = this->add(s);
  return temp;
}

Matrix Matrix::operator+(const Matrix & m) {
  Matrix temp = this->add(m);
  return temp;
}

Matrix Matrix::operator-(double s){
  Matrix temp = this->subtract(s);
  return temp;
}

Matrix Matrix::operator-(const Matrix & m) {
  Matrix temp = this->subtract(m);
  return temp;
}

Matrix Matrix::operator*(double s){
  Matrix temp = this->multiply(s);
  return temp;
}

Matrix Matrix::operator*(const Matrix & m) {
  Matrix temp = this->multiply(m);
  return temp;
}

Matrix Matrix::operator/(double s){
  Matrix temp = this->divide(s);
  return temp;
}

Matrix Matrix::operator-(){
  Matrix temp(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      *(temp.matrix + j + (c*i)) = -*(temp.matrix + j + (c*i));
    }
  }
  return temp;
}

ostream & operator<<(ostream & os, const Matrix & m) {
  for (uint i = 0; i < m.numRows(); i++) {
    os << "[ ";
    for (uint j = 0; j < m.numCols(); j++) {
      os << m.at(i, j) << " ";
    }
    os << "]" << endl;
  }
  return os;
}
