#ifndef _STATE_H_
#define _STATE_H_

#include <Arduino.h> //needed for Serial.println

class Controller;



class State {
  
  public:

    virtual ~State() {}   
    virtual void prepare() = 0; 
    virtual void execute() = 0;

    void move(int sleep_pin, int step_pin);
};

class ExecuteNothing : public State {
  
  Controller* const controller;
  
  
  public:

    ExecuteNothing( Controller* const newController) : controller(newController){}
 
    void prepare();
    void execute();
  
};

class ExecuteRunForward : public State {
  
  Controller* const controller;
  
  
  public:

    ExecuteRunForward( Controller* const newController) : controller(newController){}
 
    void prepare();
    void execute();
  
};



class ExecuteRunBackward : public State {
  
  Controller* const controller;
  
  
  public:

    ExecuteRunBackward( Controller* const newController ) : controller(newController) {}
 
    void prepare();
    void execute();
  
};



class ExecuteStop : public State {
  
  Controller* const controller;
  
  
  public:

    ExecuteStop( Controller* const newController ) : controller(newController) {}
    
    void prepare();
   	void execute();
  
};

// class ExecuteMicrostepping2Forward : public State {
  
//   Controller* const controller;
  
  
//   public:

//     ExecuteMicrostepping2Forward( Controller* const newController ) : controller(newController) {}
 
//    	void execute();

  
// };

#endif