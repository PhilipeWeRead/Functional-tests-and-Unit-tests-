#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "Model.hpp"

using namespace std;

class ModelImpl : public Model
{
    protected:
        string name;
        vector <Flow*> flows;
        vector <System*> systems;
        static vector <Model*> models;
    
    public:

        static Model* getInstace();
        //--------------constructor/destructor--------
        ModelImpl();
        ModelImpl(string name);
        ModelImpl(const Model& anotherModel);

        virtual ~ModelImpl();
        //------------setters and getters-------------
        void setName(const string name);
        string getName() const;
        vector<System*> getSystems() const;
        vector<Flow*> getFlows() const;
        Flow* getFlow(string name);
        System* getSystem(string name); 
        //------------------Methods----------------
        void addFlow(Flow* insert);
        void addSystem(System* insert);
        void execute(int begin, int end);
        void report();
        //---------------------operator------------------------
        Model& operator= (const Model& anotherModel);       
        //-------------------others iterators------------------
		Iterator_of_System beginSystems() const;
		Iterator_of_System endSystems() const;
		Iterator_of_Flow beginFlows() const;
		Iterator_of_Flow endFlows() const;
        //-----------------Factory Method----------------------
        System& createSystem(string name, double values);
        static Model* createModel();
        static Model* createModel(string name);
        static Model* createModel(Model& model);
        //Model& createModel();

        vector<Flow*>::iterator flowIterator();
        vector<System*>::iterator systemIterator();

};
#endif