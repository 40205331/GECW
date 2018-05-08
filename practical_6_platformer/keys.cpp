#include "keys.h"

#include <stdexcept>

using namespace std;
using namespace sf;

map<std::string, Keyboard::Key> keys::_keyboardLookupTable;

void keys::initialise()
{
	keys::SetKeyboardKey("Right", Keyboard::Right);
	/*
	Controls::SetKeyboardKey("Return to menu", Keyboard::Escape);
	Controls::SetKeyboardKey("Enter", Keyboard::Space);
	Controls::SetKeyboardKey("Sprint", Keyboard::Space);
	Controls::SetKeyboardKey("Shoot", Keyboard::RShift);
	Controls::SetKeyboardKey("Up", Keyboard::W);
	Controls::SetKeyboardKey("Down", Keyboard::S);
	Controls::SetKeyboardKey("Left", Keyboard::A);
	Controls::SetKeyboardKey("Right", Keyboard::D);
	*/
}

Keyboard::Key keys::GetKeyboardKey(string action)
{
	auto k = _keyboardLookupTable.find(action);
	if (k != _keyboardLookupTable.end())
	{
		return k->second;
	}
	else
	{
		throw invalid_argument("Action not known.");
	}
}

void keys::SetKeyboardKey(string action, Keyboard::Key key)
{
	_keyboardLookupTable[action] = key;
}