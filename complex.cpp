/* complex.cpp */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include <cassert>
#include <cmath>

#include "complex.h"

using namespace std;

//Constructor
MyComplex::MyComplex (const double & real, const double & imag)
{

  this->dataPtr = new double[2];
  this->dataPtr[ 0 ] = real;
  this->dataPtr[ 1 ] = imag;
};

MyComplex::MyComplex(){
   this->dataPtr = new double[2];
};

//Copy-Constructor
MyComplex::MyComplex( const MyComplex & c ){

    this->dataPtr[ 0 ] = c.dataPtr[ 0 ];
    this->dataPtr[ 1 ] = c.dataPtr[ 1 ];
};

//Destructor
MyComplex::~MyComplex (){

  delete [] this->dataPtr;

};

//Return real-part of MyComplex
const double MyComplex::real() const{

  return this->dataPtr[0];
};
//Return imag-part of MyComplex
const double MyComplex::imag() const{

  return this->dataPtr[1];
};  

//Return norm of MyComplex
const double MyComplex::norm() const{

   return (sqrt((this->dataPtr[0]*this->dataPtr[0])+(this->dataPtr[1]*this->dataPtr[1])));
   };  


//Copy Operator
MyComplex & MyComplex::operator= ( const MyComplex & c ){

      delete[] this->dataPtr;
      // try to allocate memory and catch an exception
      
      this->dataPtr = new double[ 2 ];

  // do the copying
  
    this->dataPtr[ 0 ] = c.dataPtr[ 0 ];
    this->dataPtr[ 1 ] = c.dataPtr[ 1 ];

  return *this; //*this warum *
  
};

//MyComplex-Addition
const MyComplex MyComplex::operator+ ( const MyComplex & c2) const{
 
  const MyComplex tmp; 
  for (std::size_t m=0; m<2; m++)
    tmp.dataPtr[m] = this->dataPtr[m] + c2.dataPtr[m];
  
  return tmp;

};

const MyComplex MyComplex::operator+ (const double & skal) const{

  const MyComplex tmp;
      tmp.dataPtr[0] = this->dataPtr[0] + skal;
      tmp.dataPtr[1]= this->dataPtr[1];
  
  return tmp;

};


//MyComplex-Substraktion
const MyComplex MyComplex::operator- ( const MyComplex & c2) const{
 
  const MyComplex tmp; 
  for (std::size_t m=0; m<2; m++)
    tmp.dataPtr[m] = this->dataPtr[m] - c2.dataPtr[m];
  
  return tmp;

};

//MyComplex-Unäres
const MyComplex MyComplex::operator-() const{
 
  const MyComplex tmp; 
  for (std::size_t m=0; m<2; m++)
    tmp.dataPtr[m] = -(this->dataPtr[m]);
  
  return tmp;

};



//Multiplikation mit Skalar
const MyComplex MyComplex::operator* ( const double & lambda) const{

  const MyComplex tmp;
	
	tmp.dataPtr[0] = lambda*this->dataPtr[0];
 	tmp.dataPtr[1] = lambda*this->dataPtr[1];

  
  return tmp;
}; 

//Skalarprodukt
const MyComplex MyComplex::operator* ( const MyComplex & c2) const{

  const MyComplex tmp; 
  
    tmp.dataPtr[0] =(this->dataPtr[0]*c2.dataPtr[0])-(this->dataPtr[1]*c2.dataPtr[1]); 
   
    tmp.dataPtr[1] =(this->dataPtr[0]*c2.dataPtr[1])+(this->dataPtr[1]*c2.dataPtr[0]);

	
  
  return tmp;



};
