#include "ScriptComponent.h"

ScriptComponent::ScriptComponent(string _path)
{
	path = _path;
	componentID = "ScriptComponent";
}

string ScriptComponent::GetPath()
{
	return path;
}