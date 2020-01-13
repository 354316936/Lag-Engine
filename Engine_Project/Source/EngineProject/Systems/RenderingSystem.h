
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
private:
	string szTitle;

public:
	RenderingSystem(string _szTitle);
	~RenderingSystem();
	void WindowCreate();
	void WindowClose();
	bool IsWindowOpen();
	void RenderSplashScreen();
	void RenderActors(vector<Actor*>* actors);
	sf::RenderWindow* window;
};

