
#include "pch.h"
#include "Game/Application.h"

using namespace Engine;
using namespace MyApp;

int main()
{
	static std::shared_ptr<Game> application = std::make_shared<Game>();

	application->Run();
}
