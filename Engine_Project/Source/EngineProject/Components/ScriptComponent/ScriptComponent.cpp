#include "ScriptComponent.h"

ScriptComponent::ScriptComponent(string _path)
{
	path = _path;
	componentID = "Script";
	CoCreateGuid(&id);
}

string ScriptComponent::GetPath()
{
	return path;
}