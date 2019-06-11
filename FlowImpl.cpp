#include "Flow.hpp"
#include "FlowImpl.hpp"

//------------------------------construtores&destrutor-------------------------------------
FlowImpl::FlowImpl(){}

FlowImpl::FlowImpl(const Flow& anotherFlow)
{
	if(&anotherFlow == this)
		return;

	setName(anotherFlow.getName());
	setSource(anotherFlow.getSource());
	setTarget(anotherFlow.getTarget());	

}
FlowImpl::FlowImpl(string name2, System* source2, System* target2)
{
	this->name = name2;
	this->source = source2;
	this->target = target2;
};

FlowImpl::~FlowImpl(){}

//------------------------------setters and gatters-------------------------------------
void FlowImpl::setSource(System* source2)
{
	source = source2;
}
void FlowImpl::setTarget(System* target2)
{
	target = target2;
}
void FlowImpl::setName(string name2)
{
	name = name2;
}
//------------------------------------------------------------------------------------------
System* FlowImpl::getSource() const
{
	return source;
}
System* FlowImpl::getTarget() const
{
	return target;
}
string FlowImpl::getName() const
{
	return name;
}
//----------------------------------------operator overloading-----------------------------------------
Flow& FlowImpl::operator=(const Flow& anotherFlow)
{
	if(this == &anotherFlow)
	{
		return *this;
	}

	setName(anotherFlow.getName());
	setSource(anotherFlow.getSource());
	setTarget(anotherFlow.getTarget());

	return *this;
}