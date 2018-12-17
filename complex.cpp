/* complex.cpp */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include <cassert>

#include "complex.h"

using namespace std;

//Constructor
MyComplex::MyComplex (){

  //this->N = dim;
  this->dataPtr = new double[2];
};

//Copy-Constructor
MyComplex::MyComplex( const MyComplex & c ){

  //this->N = c.N;
  //this->dataPtr = new double[ this->N ];
  //kopiere komponentenweise den Vektor c
  //for (std::size_t nx=0; nx<c.N; ++nx)
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



            /*Ausgabe aller Einträge
            void MyComplex::print(const string title, const int w) const{

            for(std::size_t nx=0; nx<this->N; nx++)

                cout << title<< "(" << nx << ")=" << setw(w) << this->dataPtr[nx] << " " << endl;

            cout << endl;

            }; */

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

//Initialisierung mit 2 Skalaren
MyComplex & MyComplex::operator=(double c[]){
 //MyComplex & MyComplex::operator=(double){

    this->dataPtr[0]=c[0];
    this->dataPtr[1]=c[1];

  return *this;

}; 

                /*Index Operator Reading
                const double  MyComplex::operator() ( std::size_t n ) const{
                // index check with assert: index check takes time 
                assert(n<this->N) ;

                return this->dataPtr[n];
                }; 

                //Index Operator Writing
                double & Vector::operator() ( std::size_t n ){
                // index check with assert: index check takes time 
                assert(n<this->N) ;
                
                return this->dataPtr[n];
                }; */

//MyComplex-Addition
const MyComplex MyComplex::operator+ ( const MyComplex & c2) const{
 
  const MyComplex tmp; 
  for (std::size_t nx=0; nx<2; nx++)
    tmp.dataPtr[nx] = this->dataPtr[nx] + c2.dataPtr[nx];
  
  return tmp;

};

const MyComplex MyComplex::operator+ (const double skal) const{

  const MyComplex tmp;
      tmp.dataPtr[0] = this->dataPtr[0] + skal;
      tmp.dataPtr[1]= this->dataPtr[1];
  
  return tmp;

};


//MyComplex-Substraktion
const MyComplex MyComplex::operator- ( const MyComplex & c2) const{
 
  const MyComplex tmp; 
  for (std::size_t nx=0; nx<2; nx++)
    tmp.dataPtr[nx] = this->dataPtr[nx] - c2.dataPtr[nx];
  
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
