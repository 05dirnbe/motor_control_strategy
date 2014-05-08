// state.cpp

#include "controller.h"

void State::move(int sleep_pin, int step_pin){

	digitalWrite(sleep_pin, HIGH);

	digitalWrite(step_pin, HIGH); //step!  
	delayMicroseconds(10);               
	digitalWrite(step_pin, LOW);  
	delayMicroseconds(1000);

}




void ExecuteNothing::prepare() { 
	
	Serial.println( "ExecuteNothing::prepare" ); 

	delayMicroseconds(10000);
}

void ExecuteNothing::execute() { 
	
	Serial.println( "ExecuteNothing::execute" ); 

	delayMicroseconds(10000);
}






void ExecuteRunForward::prepare() { 

	Serial.println( "ExecuteRunForward::prepare" ); 
	         
    digitalWrite( controller->getDirPin(), HIGH ); //direction forward

    // microstepping off
    digitalWrite(controller->getMicrostep1Pin(), LOW);
    digitalWrite(controller->getMicrostep2Pin(), LOW);

}

void ExecuteRunForward::execute() { 
	
	Serial.println( "ExecuteRunForward::execute" ); 

	move( controller->getSleepPin(), controller->getStepPin() );

}





void ExecuteRunBackward::prepare() { /*Serial.println( "ExecuteRunForward" );*/ 
	         
    digitalWrite( controller->getDirPin(), LOW ); //direction forward

    // microstepping off
    digitalWrite(controller->getMicrostep1Pin(), LOW);
    digitalWrite(controller->getMicrostep2Pin(), LOW);

}

void ExecuteRunBackward::execute() { /*Serial.println( "ExecuteRunBackward" );*/ 

    move( controller->getSleepPin(), controller->getStepPin() );

}




void ExecuteStop::prepare() { }

void ExecuteStop::execute() {

	digitalWrite( controller->getSleepPin(), LOW ); // stop

}


// void ExecuteMicrostepping2::execute() { /*Serial.println( "SetMicrostepping2" );*/ 

//     digitalWrite( controller->getDirPin(), HIGH ); //direction forward

//     // microstepping routine
//     digitalWrite(controller->getMicrostep1Pin(), HIGH);
//     digitalWrite(controller->getMicrostep2Pin(), LOW);

//     int sleep_pin = controller->getSleepPin();
//     int step_pin = controller->getStepPin();

//     move( sleep_pin, step_pin );
	

// }




// void ExecuteMicrostepping4::execute() { /*Serial.println( "SetMicrostepping2" );*/ 

//     digitalWrite( controller->getDirPin(), HIGH ); //direction forward

//     // microstepping routine
//     digitalWrite(controller->getMicrostep1Pin(), LOW);
//     digitalWrite(controller->getMicrostep2Pin(), HIGH);

//     int sleep_pin = controller->getSleepPin();
//     int step_pin = controller->getStepPin();

//     move( sleep_pin, step_pin );
	

// }




// void ExecuteMicrostepping8::execute() { /*Serial.println( "SetMicrostepping2" );*/ 

//     digitalWrite( controller->getDirPin(), HIGH ); //direction forward

//     // microstepping routine
//     digitalWrite(controller->getMicrostep1Pin(), HIGH);
//     digitalWrite(controller->getMicrostep2Pin(), HIGH);

//     int sleep_pin = controller->getSleepPin();
//     int step_pin = controller->getStepPin();

//     move( sleep_pin, step_pin );
	

// }


// void ExecuteMicrostepping8Backward::execute() { /*Serial.println( "SetMicrostepping2" );*/ 

//     digitalWrite( controller->getDirPin(), LOW ); //direction forward

//     // microstepping routine
//     digitalWrite(controller->getMicrostep1Pin(), HIGH);
//     digitalWrite(controller->getMicrostep2Pin(), HIGH);

//     int sleep_pin = controller->getSleepPin();
//     int step_pin = controller->getStepPin();

//     move( sleep_pin, step_pin );
	

// }












