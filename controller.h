#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_


#include <map>
#include "state.h"


class Controller {
  
  		State* current_state;				//this is the current state of the class
  		State* new_state;
  
		std::map < const char, State* > command_id_to_state;
		// std::map < const String, State* > command_id_to_state;


		int dir_pin;  
		int step_pin;  
		int sleep_pin;

		int microstep1_pin;
		int microstep2_pin;


 	public:

		Controller()  : current_state(NULL), 
						new_state(NULL), 
						dir_pin(100), 
						step_pin(100), 
						sleep_pin(100),
						microstep1_pin(100),
						microstep2_pin(100) {}; 
		~Controller();

		//this is what the user should use
		
		//functions handling the pins
		void setSleepPin( const int input_sleep_pin );
		int getSleepPin();

		void setStepPin( const int input_step_pin );
		int getStepPin();	

		void setDirPin( const int input_dir_pin );
		int getDirPin();

		void setMicrostep1Pin( const int input_microstep1_pin );
		int getMicrostep1Pin();

		void setMicrostep2Pin( const int input_microstep2_pin );
		int getMicrostep2Pin();

		void prepare_command(const char command);
		void run_command(const char command);
		void subscribeMethod( const char command, State* state_char);   
		void unsubscribeMethod( const char command);

};


#endif //_CONTROLLER_H_