#ifndef MODEL_HPP
#define MODEL_HPP

#include "Model.hpp"
#include "Flow.hpp"
#include "System.hpp"
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
using std::vector;

        //----------------------iterator-------------
        typedef vector<System*> :: const_iterator Iterator_of_System;
        typedef vector<Flow*> :: const_iterator Iterator_of_Flow;

class Model
{
    public:

        static Model* getInstace();
        virtual ~Model() = default;
        //------------setters and getters-----------
        virtual void setName(const string name) = 0;
        virtual string getName() const = 0;
        virtual vector<System*> getSystems() const = 0;
        virtual vector<Flow*> getFlows() const = 0;
        virtual Flow* getFlow(string name) = 0;
        virtual System* getSystem(string name) = 0;
        //------------------others----------------
        virtual void addFlow(Flow* insert) = 0;
        virtual void addSystem(System* insert) = 0;
        virtual void execute(int begin, int end) = 0;
        //---------------------operator------------------------
        virtual Model& operator= (const Model& anotherModel) = 0;
        //-------------------others iterators--------------------
		virtual Iterator_of_System beginSystems() const = 0;
		virtual Iterator_of_System endSystems() const = 0;
		virtual Iterator_of_Flow beginFlows() const = 0;
		virtual Iterator_of_Flow endFlows() const = 0;
       
        virtual vector<Flow*>::iterator flowIterator() = 0;
        virtual vector<System*>::iterator systemIterator() = 0;
        //----------------------------Factory Method--------------------------
        virtual System& createSystem(string name, double values) = 0;
        static Model* createModel();
        static Model* createModel(string name);
        static Model* createModel(Model & model);
        //static Model& createModel();

        template <typename TYPE_FLOW>
        Flow* createFlow(string name, System* source, System* target)
        {
            Flow* flow1 = new TYPE_FLOW;
            flow1->setName((name));
            flow1->setSource(source);
            flow1->setTarget(target);
            addFlow(flow1);
            return flow1;
        }

};
#endif