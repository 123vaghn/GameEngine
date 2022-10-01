
#include "pch.h"
#include "Game/Game.h"
#include "Game/Application.h"
#include "Game/TestScene.h"

using namespace Engine;
using namespace Engine::Components;
using namespace Engine::Graphics;

using namespace MyApp;


/**
 * implementation
 */
Game::Game()
{
	Graphics::SetAPI(Graphics::GraphicsAPI::OpenGLCoreProfile);

	CreateHWND();
	CreateGraphicsDevice();
	
	// TEMP
	InitGameData();

	// TEMP
	s_ActiveScene = std::make_shared<TestScene>();
	s_ActiveScene->OnScenePlay();
}


/**
 * implementation
 */
Game::~Game()
{
}


/**
 * implementation
 */
void Game::GameUpdate(Timestep DeltaTime)
{
	s_ActiveScene->OnSceneActorUpdate(DeltaTime);
}


/**
 * implementation
 */
void Game::GamePhysicsUpdate(PhysicsTimestep DeltaTime)
{
	s_ActiveScene->OnSceneActorPhysicsUpdate(DeltaTime);
}

