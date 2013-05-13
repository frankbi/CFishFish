// Concrete machine states
MachineState *State_Square::enter() {
   if ( true ) { 
      stateMachine->runTime->output = (stateMachine->runTime->input * stateMachine->runTime->input) ;

      return stateMachine->state_Square ; 
   } 

}

