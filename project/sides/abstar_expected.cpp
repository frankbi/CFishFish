// Concrete machine states
MachineState *State_Final::enter() {
   if ( (stateMachine->runTime->nextChar == 'a') ) { 
      stateMachine->runTime->outputBuffer = "In Final, found A" ;

      return stateMachine->state_NeedB ; 
   } 

   if ( (stateMachine->runTime->nextChar != '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Final, found something other than B" ;

      return stateMachine->state_Error ; 
   } 

   if ( (stateMachine->runTime->nextChar == '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Final, exiting." ;

      return NULL ;   } 

}

/////////////////////////////////////////////////////////////////////////////////////////

MachineState *State_NeedB::enter() {
   if ( (stateMachine->runTime->nextChar == 'b') ) { 
      stateMachine->runTime->outputBuffer = "In NeedB, found B" ;

      return stateMachine->state_Final ; 
   } 

   if ( (stateMachine->runTime->nextChar != '\0') ) { 
      stateMachine->runTime->outputBuffer = "In NeedB, found something other than B" ;

      return stateMachine->state_Error ; 
   } 

   if ( (stateMachine->runTime->nextChar == '\0') ) { 
      stateMachine->runTime->outputBuffer = "In NeeDB, exiting." ;

      return NULL ;   } 

}

/////////////////////////////////////////////////////////////////////////////////////////

MachineState *State_Error::enter() {
   if ( (stateMachine->runTime->nextChar != '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Error" ;

      return stateMachine->state_Error ; 
   } 

   if ( (stateMachine->runTime->nextChar == '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Error, exiting." ;

      return NULL ;   } 

}

