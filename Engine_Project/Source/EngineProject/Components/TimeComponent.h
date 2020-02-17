
#include <string>
#include <SFML\System\Clock.hpp>
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>

using namespace std;

class TimeComponent
{
public:
	TimeComponent();
	float dt;
	float getDeltaTime();
	
};


