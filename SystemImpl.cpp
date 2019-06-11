#include "SystemImpl.hpp"
#include <iostream>

using namespace std;

//------------------------------construtores&destrutor-------------------------------------

SystemImpl::SystemImpl(){}

SystemImpl::SystemImpl(string name, double value)
{
	this->name = name;
	this->value = value;
}

SystemImpl::SystemImpl(const System& anotherSystem)
{
	if(&anotherSystem == this)
		return;

	setName(anotherSystem.getName());
	setValue(anotherSystem.getValue());
}
SystemImpl::~SystemImpl(){}

//------------------------------setters and gatters-------------------------------------
void SystemImpl::setValue(double value)
{
	this->value = value;
}
void SystemImpl::setName(string name)
{
	this->name = name;
}
//------------------------------------------------------------------------------------------
double SystemImpl::getValue() const
{
	return value;
}
string SystemImpl::getName() const
{
	return name;
}
//----------------------------------------------overloading--------------------------/

System& SystemImpl::operator= (const System& anotherSystem)
{
	if(&anotherSystem == this)
		return *this;

	setName(anotherSystem.getName());
	setValue(anotherSystem.getValue());

	return *this;
}
//*/