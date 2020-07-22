#include <iostream>
#include "Unit.h"
using namespace std;



namespace ariel {


class PhysicalNumber {
    
    private:
	double _parameter;	
	Unit _unit ;


    public:
    PhysicalNumber(double parameter,Unit unit);
    
    //unary operators
    const PhysicalNumber operator+()const;
    const PhysicalNumber operator-()const;
    
    //overload simple add and substruct operators
    const PhysicalNumber operator+(const PhysicalNumber& other)const;
    const PhysicalNumber operator-(const PhysicalNumber& other) const;

    //overload simple add and substruct operators, witch the result stores in the first number
    PhysicalNumber operator+=(const PhysicalNumber& other) ;
    PhysicalNumber operator-=(const PhysicalNumber& other) ;
    //overload not operator
    bool operator!() const;
    //overload comerasion operators
    bool operator<(const PhysicalNumber& p) const;
    bool operator>(const PhysicalNumber& p)const;
    bool operator<=(const PhysicalNumber& p);     	
    bool operator>=(const PhysicalNumber& p); 
    bool operator==(const PhysicalNumber& p)const;


    
    //overload operator ++ which increasing number by 0ne
    PhysicalNumber& operator++();
    //overload operator ++ which increasing number by 0ne with parameter
    PhysicalNumber operator++(int dummy_flag_for_postfix_increment) ;
    //overload operator ++ which decreasing number by 0ne
    PhysicalNumber& operator--();
     //overload operator ++ which dencreasing number by 0ne with parameter
    PhysicalNumber operator--(int dummy_flag_for_postfix_increment) ;
    

    
    //friend bool operator==(const PhysicalNumber& c1, const PhysicalNumber& c2);
   friend bool operator!=(const PhysicalNumber& p1,const PhysicalNumber& p2);
    // input and output operators
    friend ostream& operator<< (ostream& os, const PhysicalNumber& c);
   friend istream& operator>> (istream& is, PhysicalNumber& c);
    



};


};
