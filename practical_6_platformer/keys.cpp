#include "keys.h"

#include <stdexcept>

using namespace std;
using namespace sf;

map<std::string, Keyboard::Key> keys::_keyboardLookupTable;

void keys::initialise()
{
	keys::SetKeyboardKey("Right", Keyboard::Right);
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