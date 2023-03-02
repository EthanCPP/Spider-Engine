#include "StateMachine.h"

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	this->_isAdding = true;
	this->_isRemoving = isReplacing;

	this->_newState = std::move(newState);
}

void StateMachine::RemoveState()
{
	this->_isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	// Removing a state
	if (this->_isRemoving && !this->_states.empty())
	{
		this->_states.pop();

		if (!this->_states.empty())
		{
			this->_states.top()->Resume();
		}

		this->_isRemoving = false;
	}

	// Adding a state
	if (this->_isAdding)
	{
		if (!this->_states.empty())
		{
			if (this->_isReplacing)
			{
				// Replacing, so remove the top state
				this->_states.pop();
			}
			else
			{
				// Pause the top state
				this->_states.top()->Pause();
			}
		}

		// Move the new state to the top and initialize it
		this->_states.push(std::move(this->_newState));
		this->_states.top()->Init();

		this->_isAdding = false;
	}
}

StateRef& StateMachine::GetActiveState()
{
	return this->_states.top();
}
