#include "AudioComponent.h"

bool AudioComponent::playMusic(string _path, bool loop)
{
	sf::Music music;
	music.openFromFile(_path);
	music.setLoop(loop);
	music.play();
	return true;
}

bool AudioComponent::playSound(string _path)
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile(_path);
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	return true;

}


