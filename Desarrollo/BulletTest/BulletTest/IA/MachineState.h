#pragma once

#include "../IA/StatesIA/StateIA.h"
#include "StatesIA\BuscarWeapon.h"
#include <LogIA.h>

class MachineState
{
public:

	MachineState(Enemy_Bot* owner) :m_pOwner(owner)
	{}
	~MachineState();

	//use these methods to initialize the FSM
	void SetCurrentState(StateIA* s) {
		m_pCurrentState = s; 
		LogIA::log.push_back("-----------State ::" + m_pCurrentState->getStateName() + "----------");
		m_pCurrentState->Enter(m_pOwner);
		
	}

	void SetGlobalState(StateIA* s) { m_pGlobalState = s; }
	void SetPreviousState(StateIA* s) { m_pPreviousState = s; }

	//call this to update the FSM
	void Update()const
	{
		//if a global state exists, call its execute method
		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
		//same for the current state
		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
	}

	std::string getCurrentStateName() {
		return m_pCurrentState->getStateName();
	}

	//change to a new state
	void ChangeState(StateIA* pNewState)
	{

		//keep a record of the previous state
		if((m_pCurrentState->getStateName()!="Disparar") && (m_pCurrentState->getStateName() != "Perseguir"))
		m_pPreviousState = m_pCurrentState;
		//call the exit method of the existing state
		m_pCurrentState->Exit(m_pOwner);
		//change state to the new state
		m_pCurrentState = pNewState;

		LogIA::log.push_back("-----------State ::" + m_pCurrentState->getStateName() + "----------");
		//call the entry method of the new state
		m_pCurrentState->Enter(m_pOwner);

		
	}

	//change state back to the previous state
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
	//accessors
	StateIA* CurrentState()  { return m_pCurrentState; }
	StateIA* GlobalState()  { return m_pGlobalState; }
	StateIA* PreviousState()  { return m_pPreviousState; }
	//returns true if the current state’s type is equal to the type of the
	//class passed as a parameter.
	bool isInState(std::string estado) {
		if (m_pCurrentState->getStateName() == estado) {
			return true;
		}
		return false;
	}


	void resetMachineState() {

		SetPreviousState(&BuscarWeapon::i());
		SetCurrentState(&BuscarWeapon::i());

	}

private:

	//a pointer to the agent that owns this instance
	Enemy_Bot* m_pOwner;

	StateIA* m_pCurrentState;
	//a record of the last state the agent was in
	StateIA* m_pPreviousState;
	//this state logic is called every time the FSM is updated
	StateIA* m_pGlobalState;
	

};

