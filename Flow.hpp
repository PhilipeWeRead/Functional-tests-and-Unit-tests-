#ifndef FLOW_HPP
#define FLOW_HPP

#include "Flow.hpp"
#include "SystemImpl.hpp"
#include <string>

using namespace std;


class Flow
{
	public:
		//--------------setters/getters--------------
		virtual void setSource(System* source2) = 0;
		virtual void setTarget(System* target2) = 0;
		virtual void setName(string name) = 0;
		virtual System* getSource() const = 0;
		virtual System* getTarget() const = 0;
		virtual string getName() const = 0;
		virtual double execute() = 0 ;
		//--------------operator overloading--------------
		virtual Flow& operator=(const Flow& anotherFlow) = 0;
};

#endif