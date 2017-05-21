#include "MachineState.h"

//use these methods to initialize the FSM

void MachineState::SetCurrentState(StateIA * s) {
	m_pCurrentState = s;
	LogIA::log.push_back("-----------State ::" + m_pCurrentState->getStateName() + "----------");
	m_pCurrentState->Enter(m_pOwner);

}

//call this to update the FSM

void MachineState::Update() const
{
	//if a global state exists, call its execute method
	if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
	//same for the current state
	if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
}

//change to a new state

void MachineState::ChangeState(StateIA * pNewState)
{

	//keep a record of the previous state
	if ((m_pCurrentState->getStateName() != "Disparar") && (m_pCurrentState->getStateName() != "Perseguir"))
		m_pPreviousState = m_pCurrentState;
	//call the exit method of the existing state
	m_pCurrentState->Exit(m_pOwner);
	//change state to the new state
	m_pCurrentState = pNewState;

	LogIA::log.push_back("-----------State ::" + m_pCurrentState->getStateName() + "----------");
	//call the entry method of the new state
	m_pCurrentState->Enter(m_pOwner);


}
