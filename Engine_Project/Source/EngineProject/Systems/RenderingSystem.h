
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>

using namespace std;

namespace sf {
	class RenderWindow;
}

class Actor;


class RenderingSystem
{

public:
	RenderingSystem(sf::RenderWindow* _window);
	~RenderingSystem();
	void WindowClose();
	bool IsWindowOpen();
	void RenderActors(vector<Actor*>* actors);
	sf::RenderWindow* window;
};

