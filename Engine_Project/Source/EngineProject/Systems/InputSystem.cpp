#include <SFML/Graphics.hpp>
#include "InputSystem.h"
#include <strsafe.h>
#include "../Events/MouseE.h"
#include "../Events/KeyboardE.h"
#include "../Base/Handler.h"

using namespace std;

InputSystem::InputSystem(sf::RenderWindow* _window) {
	window = _window;
}

bool InputSystem::Update() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::KeyPressed:
			
			//Handler::GetInstance()->Post(KeyboardE((char)event.key.code));
			Handler::GetInstance()->Post(KeyboardE());
			
			break;
		case sf::Event::MouseButtonPressed:
			//Handler::GetInstance()->Post(MouseE(event.mouseButton.x,event.mouseButton.y,event.mouseButton.button == sf::Mouse::Left));
			Handler::GetInstance()->Post(MouseE());
			break;
		}
		
	}

	return true;
}



