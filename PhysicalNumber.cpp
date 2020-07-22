#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PhysicalNumber.h"
#include "Unit.h"
using namespace std;

namespace ariel{
//constructor
PhysicalNumber::PhysicalNumber(double parameter,Unit unit){
	_parameter = parameter;
	_unit = unit;
}	
    
    //unary operators
    const PhysicalNumber PhysicalNumber::operator+()const{return PhysicalNumber(+this->_parameter,this->_unit);}
    const PhysicalNumber PhysicalNumber::operator-()const{return PhysicalNumber(-this->_parameter,this->_unit);}
    
    





	// this method defines operator +
    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p)const{
	// in case the number represent distance  
    if(this->_unit == Unit::KM || this->_unit == Unit::M || this->_unit == Unit::CM){
    switch (p._unit)
    {	// calculate the result for each unit
    	case Unit::CM:

        if(this->_unit == Unit::KM) return PhysicalNumber(this->_parameter+p._parameter/100000,this->_unit);
        else if(this->_unit == Unit::M)return PhysicalNumber(this->_parameter+p._parameter/100,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        
    	case Unit::M:

        if(this->_unit == Unit::KM) return PhysicalNumber(this->_parameter+p._parameter/1000,this->_unit);
        else if(this->_unit == Unit::M)return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter*100,this->_unit);

	case Unit::KM:

        if(this->_unit == Unit::KM) return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        else if(this->_unit == Unit::M)return PhysicalNumber(this->_parameter+p._parameter*1000,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter*100000,this->_unit);
	// if the other number isnt represent distance, thriw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}	// in case the number represent weight  

     if(this->_unit == Unit::G || this->_unit == Unit::KG || this->_unit == Unit::TON){
    switch (p._unit)
    	// calculate the result for each unit
    {	
    	case Unit::G:

        if(this->_unit == Unit::TON) return PhysicalNumber(this->_parameter+p._parameter/1000000,this->_unit);
        else if(this->_unit == Unit::KG)return PhysicalNumber(this->_parameter+p._parameter/1000,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        
    	case Unit::KG:

        if(this->_unit == Unit::TON) return PhysicalNumber(this->_parameter+p._parameter/1000,this->_unit);
        else if(this->_unit == Unit::KG)return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter*1000,this->_unit);

	case Unit::TON:

        if(this->_unit == Unit::TON) return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        else if(this->_unit == Unit::KG)return PhysicalNumber(this->_parameter+p._parameter*1000,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter*1000000,this->_unit);
	// if the other number isnt represent wegghit, throw an exception

        default : throw std::invalid_argument("different dimentions");
    }
} // in case the number represent time  

 if(this->_unit == Unit::SEC || this->_unit == Unit::MIN || this->_unit == Unit::HOUR){
	 
    switch (p._unit)
    {
	// calculate the result for each unit

    	case Unit::SEC:
	

        if(this->_unit == Unit::MIN) return PhysicalNumber(this->_parameter+p._parameter/60,this->_unit);
        else if(this->_unit == Unit::HOUR)return PhysicalNumber(this->_parameter+p._parameter/3600,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        
    	case Unit::MIN:
	 
        if(this->_unit == Unit::SEC) return PhysicalNumber(this->_parameter+p._parameter*60,this->_unit);
        else if(this->_unit == Unit::MIN)return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter/60,this->_unit);

	case Unit::HOUR:

        if(this->_unit == Unit::HOUR) return PhysicalNumber(this->_parameter+p._parameter,this->_unit);
        else if(this->_unit == Unit::MIN)return PhysicalNumber(this->_parameter+p._parameter*60,this->_unit);
        else return PhysicalNumber(this->_parameter+p._parameter*3600,this->_unit);
	// if the other number isnt represent time, throw an exception

        default : throw std::invalid_argument("different dimentions");
    }
}else
	throw std::invalid_argument("different dimentions");	
}
/////////////////////////////////////////////////////////////////////////////////////
	//this method defines the operator -
    const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p) const{
	    // in case the first physical number represent weight
		if(this->_unit == Unit::KM || this->_unit == Unit::M || this->_unit == Unit::CM){
		
    switch (p._unit)
    {
	//calculating the result for each unit
    	case Unit::CM:

        if(this->_unit == Unit::KM) return PhysicalNumber(this->_parameter-p._parameter/100000,this->_unit);
        else if(this->_unit == Unit::M)return PhysicalNumber(this->_parameter-p._parameter/100,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        
    	case Unit::M:

        if(this->_unit == Unit::KM) return PhysicalNumber(this->_parameter-p._parameter/1000,this->_unit);
        else if(this->_unit == Unit::M)return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter*100,this->_unit);

	case Unit::KM:

        if(this->_unit == Unit::KM) return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        else if(this->_unit == Unit::M)return PhysicalNumber(this->_parameter-p._parameter*1000,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter*100000,this->_unit);
	// if it is not the same unit throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}
	    //case the number represent weight
     if(this->_unit == Unit::G || this->_unit == Unit::KG || this->_unit == Unit::TON){
    switch (p._unit)
    {
		    //calculate the result for eaach unit
    	case Unit::G:

        if(this->_unit == Unit::TON) return PhysicalNumber(this->_parameter-p._parameter/1000000,this->_unit);
        else if(this->_unit == Unit::KG)return PhysicalNumber(this->_parameter-p._parameter/1000,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        
    	case Unit::KG:

        if(this->_unit == Unit::TON) return PhysicalNumber(this->_parameter-p._parameter/1000,this->_unit);
        else if(this->_unit == Unit::KG)return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter*1000,this->_unit);

	case Unit::TON:

        if(this->_unit == Unit::TON) return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        else if(this->_unit == Unit::KG)return PhysicalNumber(this->_parameter-p._parameter*1000,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter*1000000,this->_unit);
	// if its not the same type throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}
	    // cAse the the number represent time 
 if(this->_unit == Unit::SEC || this->_unit == Unit::MIN || this->_unit == Unit::HOUR){
    switch (p._unit)
    { //calculate the result for each unit
    	case Unit::SEC:

        if(this->_unit == Unit::MIN) return PhysicalNumber(this->_parameter-p._parameter/60,this->_unit);
        else if(this->_unit == Unit::HOUR)return PhysicalNumber(this->_parameter-p._parameter/3600,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        
    	case Unit::MIN:

        if(this->_unit == Unit::SEC) return PhysicalNumber(this->_parameter-p._parameter*60,this->_unit);
        else if(this->_unit == Unit::MIN)return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter/60,this->_unit);

	case Unit::HOUR:

        if(this->_unit == Unit::HOUR) return PhysicalNumber(this->_parameter-p._parameter,this->_unit);
        else if(this->_unit == Unit::MIN)return PhysicalNumber(this->_parameter-p._parameter*60,this->_unit);
        else return PhysicalNumber(this->_parameter-p._parameter*3600,this->_unit);
	//if the units isnt match throw an exceotion
        default : throw std::invalid_argument("different dimentions");
    }
}else
	throw std::invalid_argument("different dimentions");
	}

///////////////////////////////////////////////////////////////
	//this method defines the operator +=
    PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber& p) {
	 this->_parameter= (this->operator+(p))._parameter;
	 return (*this);
 }
////////////////////////////////////////////////////////////////
		//this method defines the operator -=

    PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber& p) {
	 this->_parameter= (this->operator-(p))._parameter;
	return (*this);}
//////////////////////////////////////////////////////////////
		//this method defines the operator !

    bool PhysicalNumber::operator!() const{
	if(this->_parameter == 0){
	return true;
	}
	else {
	return false;}
	}
////////////////////////////////////////////////////////////
	//this method defines the operator <
    bool PhysicalNumber::operator<(const PhysicalNumber& p) const{
	    //first case the number represent distance
		if(this->_unit == Unit::KM || this->_unit == Unit::M || this->_unit == Unit::CM){
	//calculating hte result
    switch (p._unit)
    {
    	case Unit::CM:

        if(this->_unit == Unit::KM) return (this->_parameter<p._parameter/100000);
        else if(this->_unit == Unit::M)return (this->_parameter<p._parameter/100);
        else return (this->_parameter<p._parameter);
        
    	case Unit::M:

        if(this->_unit == Unit::KM) return (this->_parameter<p._parameter/1000);
        else if(this->_unit == Unit::M)return (this->_parameter<p._parameter);
        else return (this->_parameter < p._parameter*100);

	case Unit::KM:

        if(this->_unit == Unit::KM) return (this->_parameter<p._parameter);
        else if(this->_unit == Unit::M)return (this->_parameter<p._parameter*1000);
        else return (this->_parameter<p._parameter*100000);
// if the types dont match throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}    // case the number represent weight
     if(this->_unit == Unit::G || this->_unit == Unit::KG || this->_unit == Unit::TON){
    switch (p._unit)
    {// calculate the result
    	case Unit::G:

        if(this->_unit == Unit::TON) return (this->_parameter<p._parameter/1000000);
        else if(this->_unit == Unit::KG)return (this->_parameter<p._parameter/1000);
        else return (this->_parameter<p._parameter);
        
    	case Unit::KG:

        if(this->_unit == Unit::TON) return (this->_parameter<p._parameter/1000);
        else if(this->_unit == Unit::KG)return (this->_parameter<p._parameter);
        else return (this->_parameter< p._parameter*1000);

	case Unit::TON:

        if(this->_unit == Unit::TON) return (this->_parameter<p._parameter);
        else if(this->_unit == Unit::KG)return (this->_parameter<p._parameter*1000);
        else return (this->_parameter<p._parameter*1000000);
//if the types dont match throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}// case the number represent time
 if(this->_unit == Unit::SEC || this->_unit == Unit::MIN || this->_unit == Unit::HOUR){
    switch (p._unit)
    {
    	case Unit::SEC:
//calcuate the result
        if(this->_unit == Unit::MIN) return (this->_parameter<p._parameter/60);
        else if(this->_unit == Unit::HOUR)return (this->_parameter<p._parameter/3600);
        else return (this->_parameter<p._parameter);
        
    	case Unit::MIN:

        if(this->_unit == Unit::SEC) return (this->_parameter<p._parameter*60);
        else if(this->_unit == Unit::MIN)return (this->_parameter<p._parameter);
        else return (this->_parameter < p._parameter/60);

	case Unit::HOUR:

        if(this->_unit == Unit::HOUR) return (this->_parameter<p._parameter);
        else if(this->_unit == Unit::MIN)return (this->_parameter<p._parameter*60);
        else return (this->_parameter<p._parameter*3600);
// if the units dont match throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}else
	throw std::invalid_argument("different dimentions");
	}
////////////////////////////////////////////////////////////////////////////
	//this method defines the operator >
    bool PhysicalNumber::operator>(const PhysicalNumber& p) const{
    return !(this->operator<(p))&& !(this->operator==(p)); 
	} 
/////////////////////////////////////////////////////////////////////////////
		//this method defines the operator <=

    bool PhysicalNumber::operator<=(const PhysicalNumber& p){

		return (this->operator<(p)|| this-> operator==(p));}
//////////////////////////////////////////////////////////////////////////////
		//this method defines the operator >=
    bool PhysicalNumber::operator>=(const PhysicalNumber& p){
	return (this->operator>(p)|| this-> operator==(p));
	}
////////////////////////////////////////////////////////////////////////////// 
		//this method defines the operator ==

    bool PhysicalNumber::operator==(const PhysicalNumber& p)const{
	    //case the number represent distance
   if(this->_unit == Unit::KM || this->_unit == Unit::M || this->_unit == Unit::CM){
    switch (p._unit)
    {
    	case Unit::CM:
	//calculate the result
        if(this->_unit == Unit::KM) return (this->_parameter==p._parameter/100000);
        else if(this->_unit == Unit::M)return (this->_parameter==p._parameter/100);
        else return (this->_parameter==p._parameter);
        
    	case Unit::M:

        if(this->_unit == Unit::KM) return (this->_parameter==p._parameter/1000);
        else if(this->_unit == Unit::M)return (this->_parameter==p._parameter);
        else return (this->_parameter ==p._parameter*100);

	case Unit::KM:

        if(this->_unit == Unit::KM) return (this->_parameter==p._parameter);
        else if(this->_unit == Unit::M)return (this->_parameter==p._parameter*1000);
        else return (this->_parameter==p._parameter*100000);
	//if the units dont match throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}	// case the number represent weight
     if(this->_unit == Unit::G || this->_unit == Unit::KG || this->_unit == Unit::TON){
    switch (p._unit)
    {
    	case Unit::G:
	//calculate the result
        if(this->_unit == Unit::TON) return (this->_parameter==p._parameter/1000000);
        else if(this->_unit == Unit::KG)return (this->_parameter==p._parameter/1000);
        else return (this->_parameter==p._parameter);
        
    	case Unit::KG:

        if(this->_unit == Unit::TON) return (this->_parameter==p._parameter/1000);
        else if(this->_unit == Unit::KG)return (this->_parameter==p._parameter);
        else return (this->_parameter == p._parameter*1000);

	case Unit::TON:

        if(this->_unit == Unit::TON) return (this->_parameter==p._parameter);
        else if(this->_unit == Unit::KG)return (this->_parameter==p._parameter*1000);
        else return (this->_parameter==p._parameter*1000000);
	//throw exception if the unit dont match
        default : throw std::invalid_argument("different dimentions");
    }
}
	    //case the number represent tome
 if(this->_unit == Unit::SEC || this->_unit == Unit::MIN || this->_unit == Unit::HOUR){
    switch (p._unit)
    {
		    //calculate the result
    	case Unit::SEC:

        if(this->_unit == Unit::MIN) return (this->_parameter==p._parameter/60);
        else if(this->_unit == Unit::HOUR)return (this->_parameter==p._parameter/3600);
        else return (this->_parameter==p._parameter);
        
    	case Unit::MIN:

        if(this->_unit == Unit::SEC) return (this->_parameter==p._parameter*60);
        else if(this->_unit == Unit::MIN)return (this->_parameter==p._parameter);
        else return (this->_parameter == p._parameter/60);

	case Unit::HOUR:

        if(this->_unit == Unit::HOUR) return (this->_parameter==p._parameter);
        else if(this->_unit == Unit::MIN)return (this->_parameter==p._parameter*60);
        else return (this->_parameter==p._parameter*3600);
	//if the units dont match throw an exception
        default : throw std::invalid_argument("different dimentions");
    }
}else
	throw std::invalid_argument("different dimentions");
}
	/////////////////////////////////
	// this method defines the operator << output
    ostream& operator<<(ostream& os, const PhysicalNumber& p){
	switch(p._unit){
	case Unit::KM : return os <<p._parameter<<"[km]";
	case Unit::M :return os <<p._parameter<<"[m]" ; 
	case Unit::CM :return os <<p._parameter<<"[cm]"; 
	case Unit::G :return os <<p._parameter<<"[g]" ; 
	case Unit::KG :return os <<p._parameter<<"[kg]" ; 
	case Unit::TON :return os <<p._parameter<<"[ton]";
	case Unit::SEC :return os <<p._parameter<<"[sec]";
	case Unit::MIN :return os <<p._parameter<<"[min]";
	case Unit::HOUR:return os <<p._parameter<<"[hour]";
	}
	}
	//////////////////////////
	//this method defines the operator >> input
    istream&  operator>> (istream& is, PhysicalNumber& p){
	//std::stringstream temp;
	//temp<<is.rdbuf()<<endl;
	double d_prev = p._parameter;
	 Unit  u_prev = p._unit;
	ios::pos_type startPosition = is.tellg(); // "iterator" to opsition of
    // the first charcter in stream
	double a;	
	is >> a;
	p._parameter = a; // "input goes to paramter"
	std::string str ;
	is >> str;
	if ( str == "[kg]"){p._unit = Unit::KG;}
	else if ( str == "[ton]"){p._unit = Unit::TON;}
	else if ( str == "[g]"){p._unit = Unit::G;}
	else if ( str == "[cm]"){p._unit = Unit::CM;}
	else if ( str == "[m]"){p._unit = Unit::M;}
	else if ( str == "[km]"){p._unit = Unit::KM;}
	else if ( str == "[sec]"){p._unit = Unit::SEC;}
	else if ( str == "[min]"){p._unit = Unit::MIN;}
	else if( str == "[hour]"){p._unit = Unit::HOUR;}
	else {
        // is go back to first condition
        auto errorState = is.rdstate(); // remember error state
        is.clear(); // clear error so seekg will work
        is.seekg(startPosition); // get back to initial position before
        // in "is" this function star
        is.clear(errorState); // set back the error flag
	      p._parameter = d_prev;
	      p._unit= u_prev;
	     }
        return is;
	}



    ///////////////////////////////
	//this method defines the operator++
    PhysicalNumber& PhysicalNumber::operator++(){
	_parameter++;
	return *this;
	}
	//////////////////////////////
//this method defines the operator++ with parameter
    PhysicalNumber PhysicalNumber::operator++(int postfix){
	PhysicalNumber save = *this;
	_parameter++;	
	return save;
}

////////////////////////////////////////////////--a////////////////////////////
//this method defines the operator-- with parameter

    PhysicalNumber& PhysicalNumber::operator--(){
	_parameter--;
	return *this;
	}
////////////////////////////////////////////////a--///////////////////////////////
	//this method defines the operator-- with parameter

     PhysicalNumber PhysicalNumber::operator--(int postfix){
	PhysicalNumber copy=*this;
	_parameter--;
	return (copy);
	}
//this method defines the operator!= with 2 parameteres

bool operator!=(const PhysicalNumber& p1,const PhysicalNumber& p2){
	return !(p1.operator==(p2));
}





};
