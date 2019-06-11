#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
#include "ModelImpl.hpp"
#include "FlowImpl.hpp"

//------------------------------construtores&destrutor-------------------------------------
ModelImpl::ModelImpl()
{
    this->name = "";
    flows.clear();
    systems.clear();
}

ModelImpl::ModelImpl(string name)
{
    this->name = name;
}
ModelImpl::ModelImpl(const Model& anotherModel)
{
    name = anotherModel.getName();
    Logistic* helpLogistic;
    Exponential* helpExponential;

    for(const auto &flow : anotherModel.getFlows()){
        helpLogistic = dynamic_cast<Logistic*>(flow);
        helpExponential = dynamic_cast<Exponential*>(flow);
        if(helpLogistic != nullptr){
            flows.push_back(new Logistic((*helpLogistic)));
            systems.push_back(helpLogistic->getSource());
            systems.push_back(helpLogistic->getTarget());
        }else if(helpExponential != nullptr){
            flows.push_back(new Exponential(*helpExponential));
            systems.push_back(helpExponential->getSource());
            systems.push_back(helpExponential->getTarget());
        }
    }
}

ModelImpl::~ModelImpl() {}
//*/

//------------------------------setters and gatters-------------------------------------
void ModelImpl::setName(const string name)
{
    this->name = name;
}
/*void ModelImpl::getFlow(const string &name)
{

}*/
vector<System*> ModelImpl::getSystems() const
{
    return systems;
}
vector<Flow*> ModelImpl::getFlows() const
{
    return flows;
}
string ModelImpl::getName() const 
{
    return name;
}
Flow* ModelImpl::getFlow(string name)
{
    auto it = find_if(flows.begin(),flows.end(),[&name](Flow* help){return help->getName() == name;});
    if(it != flows.end())
        return (*it);
    return nullptr;
}
System* ModelImpl::getSystem(string name)
{
    auto it = find_if(systems.begin(),systems.end(),[&name](System* help){return help->getName() == name;});
    if(it != systems.end())
        return (*it);
    return nullptr;
}
//------------------------------add method-------------------------------------
void ModelImpl::addFlow(Flow* insert)
{
    flows.push_back(insert);
}
void ModelImpl::addSystem(System* insert)
{
    systems.push_back(insert);
}
/*
void ModelImpl::addModel(Model* insert)
{
    models.push_back(insert);
}
//*/
//------------------------------------------------------------------------------------
vector<Flow*>::iterator ModelImpl::flowIterator()
{
    vector<Flow*>::iterator it = flows.begin();
    return it;
}
vector<System*>::iterator ModelImpl::systemIterator()
{
    vector<System*>::iterator it = systems.begin();
    return it;
}
//*/
//--------------------------------------------iterators------------------------------/

Iterator_of_System ModelImpl::beginSystems() const
{
    return systems.begin();
}

Iterator_of_System ModelImpl::endSystems() const 
{
    return systems.end();
}
Iterator_of_Flow ModelImpl::beginFlows() const 
{
    return flows.begin();
}

Iterator_of_Flow ModelImpl::endFlows() const
{
    return flows.end();
}
/*
Iterator_of_Flow ModelImpl::beginFlows() const 
{
    return flows.begin();
}

Iterator_of_Flow ModelImpl::endFlows() const
{
    return flows.end();
}
*/
//-------------------------------------Exponetial and logistic-----------------------------------------------------------
void ModelImpl::execute(int begin, int end)
{
    double values[100];

    for(int i=begin; i<end; i++)
    {
        for(int j=0; j<flows.size(); j++)
        {
            Flow*aux = this->flows[j];
            values[j] = aux->execute();
        }
        for(int k=0; k<flows.size(); k++)
        {
            System* s = this->flows[k]->getSource();
            System* t = this->flows[k]->getTarget();
            s->setValue(s->getValue() - values[k]);
            t->setValue(t->getValue() + values[k]);
        }
    }
}
//*/
//------------------------------------------others------------------------------------------------------------------------------
void ModelImpl::report()
{
    cout << "Model: " << getName() << endl;
    cout << "values: " << endl;

    for(auto it = systems.begin(); it != systems.end(); it++)
    {
        cout << "Name: " << (*it)->getName() << endl;
        cout << "Value: " << (*it)->getValue() << endl;
    }
}

// implemetação do operator do valmir
Model& ModelImpl :: operator= (const Model& anotherModel)
{
    name = anotherModel.getName();
    Logistic* helpLogistic;
    Exponential* helpExponential;

    for(const auto &flow : anotherModel.getFlows()){
        helpLogistic = dynamic_cast<Logistic*>(flow);
        helpExponential = dynamic_cast<Exponential*>(flow);
        if(helpLogistic != nullptr){
            flows.push_back(new Logistic((*helpLogistic)));
            systems.push_back(helpLogistic->getSource());
            systems.push_back(helpLogistic->getTarget());
        }else if(helpExponential != nullptr){
            flows.push_back(new Exponential(*helpExponential));
            systems.push_back(helpExponential->getSource());
            systems.push_back(helpExponential->getTarget());
        }
    }

    return *this;
}
//---------------------------------------Factory Method--------------------------
System& ModelImpl::createSystem(string name, double values)
{
	System *s = new SystemImpl(name, values);
	addSystem(s);

	return *s;
}
///*/
Model* ModelImpl::createModel() 
{
    Model* model = new ModelImpl();
    return model;
}

Model* ModelImpl::createModel(string name) 
{
    Model* model = new ModelImpl(name);
    return model;
}

Model* ModelImpl::createModel(Model &model) 
{
    Model *md = new ModelImpl(model);
    return md;
}
Model* Model::createModel() 
{
    return ModelImpl::createModel();
}

Model* Model::createModel(string name) 
{
    return ModelImpl::createModel(name);
}

Model* Model::createModel(Model &model) 
{
    return ModelImpl::createModel(model);
}
//*/
Model *Model::getInstace() {
    return ModelImpl::getInstace();
}

Model *ModelImpl::getInstace() {
    return new ModelImpl();
}
