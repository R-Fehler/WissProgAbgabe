/* complex.h */

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <cstddef>

class MyComplex { //Beginn der MyComplex Klasse

public:

    //Constructor
    //MyComplex ( const double real, const double imag);
    MyComplex ();


    //Copy-Constructor
    MyComplex( const MyComplex & c );

    //Destructor
    ~MyComplex ();

    //Return real-part of MyComplex
    const double real() const;

    //Return imag-part of MyComplex
    const double imag() const;

    //Return norm of MyComplex
    const double norm() const;


                //Ausgabe aller Einträge
                void print(const std::string title="", const int w=8) const; //const int w=8 default Wert für Abstand. Übergabe bei Aufruf optional

    //Copy Operator
    MyComplex & operator=(const MyComplex & c ); //& was ist der Unterschied zwischen MyComplex & operator, MyComplex operator

    //Initialisierung mit 2 Skalaren
    MyComplex & operator=(double c[]);
	//MyComplex & operator=( double re,  double im);

                //Index Operator Reading
                //const double  operator() ( std::size_t n ) const;

                //Index Operator Writing
                //double & operator() ( std::size_t n );


    //MyComplex-Addition
    const MyComplex operator+ (const MyComplex & c2) const;
    
    //MyComplex-Addition
    const MyComplex operator+ (const double & skal) const;

    //MyComplex-Subtraktion
    const MyComplex operator- (const MyComplex & c2) const;

    const MyComplex operator-() const;
    
    //Multiplikation mit Complex
    const MyComplex operator* (const MyComplex & c2) const;
    //Multiplikation mit Skalar
    const MyComplex operator* (const double & lambda) const;

private:

    //Default Constructor: Hier PRIVATE um Ausführen des Default Constructor zu unterbinden
    //MyComplex ();

    double * dataPtr;  // pointer for data
    //std::size_t      N;        // number of entries in the vector

}; //Ende der Vector Kasse
#endif