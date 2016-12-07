#pragma once

#include "../IA/StatesIA/StateIA.h"

template <class entity_type>
class MachineState
{
public:

	MachineState(entity_type* owner) :m_pOwner(owner),
		m_pCurrentState(NULL),
		m_pPreviousState(NULL),
		m_pGlobalState(NULL)
	{}
	~MachineState();

	//use these methods to initialize the FSM
	/*void SetCurrentState(StateIA<entity_type>* s) { m_pCurrentState = s; }
	void SetGlobalState(StateIA<entity_type>* s) { m_pGlobalState = s; }
	void SetPreviousState(StateIA<entity_type>* s) { m_pPreviousState = s; }

	//call this to update the FSM
	void Update()const
	{
		//if a global state exists, call its execute method
		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
		//same for the current state
		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
	}

	//change to a new state
	void ChangeState(StateIA<entity_type>* pNewState)
	{
		assert(pNewState &&
			"<StateMachine::ChangeState>: trying to change to a null state");
		//keep a record of the previous state
		m_pPreviousState = m_pCurrentState;
		//call the exit method of the existing state
		m_pCurrentState->Exit(m_pOwner);
		//change state to the new state
		m_pCurrentState = pNewState;
		//call the entry method of the new state
		m_pCurrentState->Enter(m_pOwner);
	}

	//change state back to the previous state
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
	//accessors
	StateIA<entity_type>* CurrentState() const { return m_pCurrentState; }
	StateIA<entity_type>* GlobalState() const { return m_pGlobalState; }
	StateIA<entity_type>* PreviousState() const { return m_pPreviousState; }
	//returns true if the current state’s type is equal to the type of the
	//class passed as a parameter.
	bool isInState(const State<entity_type>& st)const;*/

private:

	//a pointer to the agent that owns this instance
/*	entity_type* m_pOwner;
	StateIA<entity_type>* m_pCurrentState;
	//a record of the last state the agent was in
	StateIA<entity_type>* m_pPreviousState;
	//this state logic is called every time the FSM is updated
	StateIA<entity_type>* m_pGlobalState;	*/

};

