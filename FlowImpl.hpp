#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"
#include "System.hpp"
#include <string>

using namespace std;


class FlowImpl : public Flow
{
	private:
		System* source;
		System* target;
		string name;

	public:
		//--------------Constuctor/destructor--------------
		FlowImpl();
		FlowImpl(const Flow& anotherFlow);
		FlowImpl(string name, System* source2, System* target2);
		virtual ~FlowImpl();
		//--------------setters/getters--------------
		void setSource(System* source2);
		void setTarget(System* target2);
		void setName(string name);
		System* getSource() const;
		System* getTarget() const;
		string getName() const;
		virtual double execute()=0;
		//--------------operator overloading--------------
		Flow& operator=(const Flow& anotherFlow);
};

class Exponential: public FlowImpl
{

public:
	Exponential(): FlowImpl(){};
	Exponential(const Flow& anotherFlow)
	{
		if(&anotherFlow == this)
			return;

		setName(anotherFlow.getName());
		setSource(anotherFlow.getSource());
		setTarget(anotherFlow.getTarget());	
	}
	Exponential(string name, System *source2, System* target2):FlowImpl(name,source2,target2){};

	double execute()
	{
		return getSource()->getValue() * 0.01;
	}
};

class Logistic: public FlowImpl
{
	
public:
	Logistic(): FlowImpl(){};
	Logistic(const Flow& anotherFlow)
	{
		if(&anotherFlow == this)
			return;

		setName(anotherFlow.getName());
		setSource(anotherFlow.getSource());
		setTarget(anotherFlow.getTarget());	
	}
	
	Logistic(string name, System *source2, System* target2):FlowImpl(name,source2,target2){};

	double execute()
	{
		return  (0.01 * getTarget()->getValue() * (1 - getTarget()->getValue()/70));
	}
};

#endif