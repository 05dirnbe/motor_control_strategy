#include "controller.h"

//accsessor functions
void Controller::setSleepPin(int input_sleep_pin) { sleep_pin = input_sleep_pin; }
int Controller::getSleepPin() { return sleep_pin; }

void Controller::setStepPin(int input_step_pin){ step_pin = input_step_pin; }
int Controller::getStepPin(){ return step_pin; }	

void Controller::setDirPin( int input_dir_pin){ dir_pin = input_dir_pin; }
int Controller::getDirPin(){ return dir_pin; }

void Controller::setMicrostep1Pin( int input_microstep1_pin){ microstep1_pin = input_microstep1_pin; }
int Controller::getMicrostep1Pin(){ return microstep1_pin; }

void Controller::setMicrostep2Pin( int input_microstep2_pin){ microstep2_pin = input_microstep2_pin; }
int Controller::getMicrostep2Pin(){ return microstep2_pin; }



void Controller::subscribeMethod( const char command, State* state_char) { command_id_to_state[command] = state_char; }    
void Controller::unsubscribeMethod( const char command) {command_id_to_state.erase(command);}

void Controller::prepare_command(const char command) {

	new_state = command_id_to_state[command];

	if( new_state != current_state) {

		current_state = new_state;
		// new_state = NULL;
	}
	
	current_state -> prepare();

}

void Controller::run_command(const char command) {

	new_state = command_id_to_state[command];

	if( new_state != current_state) {

		current_state = new_state;
		new_state = NULL;
	}
	
	current_state -> execute();

}

Controller::~Controller(){

	delete current_state;
	delete new_state;
}


