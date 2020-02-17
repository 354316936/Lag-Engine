#pragma once
#include <string>
#include <SFML/Audio.hpp>
using namespace std;
class AudioComponent
{
public:
	bool playMusic(string _path, bool loop);
	bool playSound(string _path);
};

