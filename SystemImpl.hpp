#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include <string>
#include "System.hpp"

using namespace std;

class SystemImpl : public System
{
    private:
        double value;
        string name;

    public:
        SystemImpl();
        SystemImpl(const System& anotherSystem);
        SystemImpl(string name, double value);
        virtual ~SystemImpl();
        //-------------setters and getters--------------
        double getValue() const;
        string getName() const;
        void setValue(double value);
        void setName(string name);
        //-----------overloading---------
        System& operator= (const System& anotherSystem);

};
#endif 