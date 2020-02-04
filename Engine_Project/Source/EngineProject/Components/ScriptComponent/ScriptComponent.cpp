#include "ScriptComponent.h"

ScriptComponent::ScriptComponent(string _path)
{
	path = _path;
	componentID = "Script";
}

string ScriptComponent::GetPath()
{
	return path;
}