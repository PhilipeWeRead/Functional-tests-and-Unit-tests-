#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
//#include "System.hpp"

using namespace std;

class System
{
    public:
       
        virtual double getValue() const = 0;
        virtual string getName() const = 0;
        //------------------setters---------------
        virtual void setValue(double value) = 0;
        virtual void setName(string name) = 0;
        //-----------overloading---------
        virtual System& operator= (const System& anotherSystem) = 0;

};
#endif 