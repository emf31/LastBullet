#include "AnimationMachine.h"
#include <Character.h>

void AnimationMachine::Update()const
{
	//if a global state exists, call its execute method
	if (m_pCurrentAnimation) m_pCurrentAnimation->Execute(m_pOwner);
	//same for the current state
}

void AnimationMachine::SetCurrentAnimation(AnimationCharacter* s) {
	m_pCurrentAnimation = s;

}

void AnimationMachine::ChangeState(AnimationCharacter* pNewState)
{

	//keep a record of the previous state

	//call the exit method of the existing state
	m_pCurrentAnimation->Exit(m_pOwner);
	//change state to the new state
	m_pCurrentAnimation = pNewState;

	//call the entry method of the new state
	m_pCurrentAnimation->Enter(m_pOwner);


}