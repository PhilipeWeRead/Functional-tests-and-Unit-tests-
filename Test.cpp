#include <iostream>
#include "FlowImpl.hpp"
#include "ModelImpl.hpp"
#include "test.hpp"
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;

///*
void functionExpTest()
{
	///*
    Model* modeloExp = Model::createModel("modelEXP");
    modeloExp->createSystem("pop1",100);
    modeloExp->createSystem("pop2",0);


    modeloExp->createFlow<Exponential>("flow1", (modeloExp->getSystem("pop1")), (modeloExp->getSystem("pop2")));
    
    modeloExp->execute(0,100);

    assert(fabs(modeloExp->getSystem("pop1")->getValue() - 36.6032) <= 0.0001);
    assert(fabs(modeloExp->getSystem("pop2")->getValue() - 63.3968) <= 0.0001);
    //*/

}
void functionLogisticTest()
{
    // Model logistic
    Model *mLogistic = Model::createModel("modelLogistic");

    // creating model and system
    mLogistic->createSystem("p1", 100);
    mLogistic->createSystem("p2", 10);

    mLogistic->createFlow<Logistic>("flow1", (mLogistic->getSystem("p1")), (mLogistic->getSystem("p2")));
    
    // simulate execution
    mLogistic->execute(0,100);

    assert(fabs(mLogistic->getSystem("p1")->getValue() - 88.2167) <= 0.0001);
    assert(fabs(mLogistic->getSystem("p2")->getValue() - 21.7834) <= 0.0001);
    
}
void completeTest()
{

    // Modelo para o sistema
    Model *modelComplete =  Model::createModel("modelComplete");
    // Os stocks do modelo
    modelComplete->createSystem("Q1", 100);
    modelComplete->createSystem("Q2", 0);
    modelComplete->createSystem("Q3", 100);
    modelComplete->createSystem("Q4", 0);
    modelComplete->createSystem("Q5", 0);


    modelComplete->createFlow<Exponential>("F",(modelComplete->getSystem("Q1")),(modelComplete->getSystem("Q2")));
    modelComplete->createFlow<Exponential>("T",(modelComplete->getSystem("Q2")),(modelComplete->getSystem("Q3")));
    modelComplete->createFlow<Exponential>("U",(modelComplete->getSystem("Q3")),(modelComplete->getSystem("Q4")));
    modelComplete->createFlow<Exponential>("V",(modelComplete->getSystem("Q4")),(modelComplete->getSystem("Q1")));
    modelComplete->createFlow<Exponential>("G",(modelComplete->getSystem("Q1")),(modelComplete->getSystem("Q3")));
    modelComplete->createFlow<Exponential>("R",(modelComplete->getSystem("Q2")),(modelComplete->getSystem("Q5")));
    modelComplete->execute(0,100);

    // Verificao de acertos dos resultados
    assert(fabs(modelComplete->getSystem("Q1")->getValue() - 31.8513) < 0.0001);
    assert(fabs(modelComplete->getSystem("Q2")->getValue() - 18.4003) < 0.0001);
    assert(fabs(modelComplete->getSystem("Q3")->getValue() - 77.1143) < 0.0001);
    assert(fabs(modelComplete->getSystem("Q4")->getValue() - 56.1728) < 0.0001);
    assert(fabs(modelComplete->getSystem("Q5")->getValue() - 16.4612) < 0.0001);
}

void unitaryTest_System()
{

	System *testing = new SystemImpl("testing", 50);
	assert(testing->getName() == "testing");
	assert(testing->getValue() == 50);


	testing->setName("name");
	assert(testing->getName() == "name");
	testing->setValue(91);
	assert(testing->getValue() == 91);


	System *testing2 = new SystemImpl("new testing", 22);
	assert(testing2->getName() == "new testing");
	assert(testing2->getValue() == 22);

	SystemImpl *del1 = dynamic_cast<SystemImpl*> (testing); 
	SystemImpl *del2 = dynamic_cast<SystemImpl*> (testing2);

	delete del1;
	delete del2;

	//cout << "Unitary test of system has finished" << endl;
}
//*/
void unitaryTest_Flow()
{
	System *firstSystem = new SystemImpl("firstSys", 1);
	System *secondSystem = new SystemImpl("secondSys", 2);

	Flow *testing = new Exponential("testing", firstSystem,secondSystem);
	assert(testing->getSource()->getName() == firstSystem->getName());
	assert(testing->getSource()->getValue() == firstSystem->getValue());

	assert(testing->getTarget()->getName() == secondSystem->getName());	
	assert(testing->getTarget()->getValue() == secondSystem->getValue());

	assert(testing->getName() == "testing");

//-----------------------------------------------------------------------------------
	
	Flow *testing2 = new Exponential(*testing);
	assert(testing2->getSource()->getName() == testing->getSource()->getName());
	assert(testing2->getSource()->getValue() == testing->getSource()->getValue());

	assert(testing2->getTarget()->getName() == testing->getTarget()->getName());	
	assert(testing2->getTarget()->getValue() == testing->getTarget()->getValue());

	assert(testing2->getName() == testing->getName());
	
	//-------------------------------------------setters------------------------------------
	//testing2->setValue(5);
	//testing2->setTarget(8);

	testing2->setName("testing2");
	//cout << testing2->getName(); 
	assert(testing2->getName() == "testing2");

//--------------------  -------------------------------------------------------------

	System *firstSys = new SystemImpl("firstSys", 1);
	System *secondSys = new SystemImpl("secondSys", 2);

	Flow *testingLogistic = new Logistic("testingLogistic", firstSys,secondSys);
	assert(testingLogistic->getSource()->getName() == firstSys->getName());
	assert(testingLogistic->getSource()->getValue() == firstSys->getValue());

	assert(testingLogistic->getTarget()->getName() == secondSys->getName());	
	assert(testingLogistic->getTarget()->getValue() == secondSys->getValue());

	assert(testingLogistic->getName() == "testingLogistic");

	//cout << "Unitary test of flow has finished" << endl;

	SystemImpl *del1 = dynamic_cast<SystemImpl*> (firstSystem);
	SystemImpl *del2 = dynamic_cast<SystemImpl*> (secondSystem);

	Exponential *del3 = dynamic_cast<Exponential*> (testing);

	delete del1;
	delete del2;
	delete del3;
}

void unitaryTest_Model()
{

	Model* models = new ModelImpl("name");
	assert(models->getName()=="name");

	models->setName("name");
	assert(models->getName()=="name");

	//test da funf report
	//assert(models->report());

//-------------------------------------testing vector----------------------------
	System *sys = new SystemImpl("name",40);
    System *sys2 = new SystemImpl("name2",6);
    Flow* flo = new Logistic("test",sys,sys2);
    Flow* flo2  = new Exponential("test2",sys,sys2);


    models->addSystem(sys);
    models->addSystem(sys2);
    models->addFlow(flo);
    models->addFlow(flo2);

/*
    auto iteratorFlow = models->flowIteratorBegin();
    assert(*iteratorFlow == flo);

    auto iteratorSystem = models->systemIteratorBegin();
    assert(*iteratorSystem == sys);

*/    

    SystemImpl *del1 = dynamic_cast <SystemImpl*> (sys);
	SystemImpl *del2 = dynamic_cast <SystemImpl*> (sys2);
	
	delete del1;
	delete del2;
	
    //cout << "Unitary test of model has finished" << endl;

	
}