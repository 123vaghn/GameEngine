
#include "pch.h"
#include "Game/Game.h"
#include "Game/TestScene.h"

using namespace Engine;
using namespace Engine::Components;
using namespace Engine::Graphics;

using namespace MyApp;


static Actor s_SceneGraph;
static Actor s_SG_Camera;
static Actor s_SG_PlaneObject;


class TestScript : public Script
{
public:
	TestScript()
	{
		std::cout << "TestScript.TestScript()" << std::endl;
	}

	virtual ~TestScript() override
	{
		std::cout << "virtual TestScript.~TestScript()" << std::endl;
	}

	virtual void OnCreate() override
	{
		std::cout << "virtual void TestScript.OnCreate()" << std::endl;
	}

	virtual void OnDestroy() override
	{
		std::cout << "virtual void TestScript.OnDestroy()" << std::endl;
	}

	virtual void OnStart() override
	{
		std::cout << "virtual void TestScript.OnStart()" << std::endl;
	}

	virtual void OnUpdate() override
	{
		std::cout << "virtual void TestScript.OnUpdate()" << std::endl;
	}
};


/**
 * implementation
 */
TestScene::TestScene()
{
	s_SG_Camera.AddComponent<Input>();
	s_SG_Camera.AddComponent<Camera>();

	s_SceneGraph.AddChild(s_SG_Camera);
	s_SG_PlaneObject.GetTransform().SetPosition({ 0, 0, -5 });
}


/**
 * implementation
 */
TestScene::~TestScene()
{
}


/**
 * implementation
 */
void TestScene::OnScenePlay()
{
	std::cout << "TestScene::OnScenePlay()" << std::endl;
}


/**
 * implementation
 */
void TestScene::OnSceneStop()

{
	std::cout << "TestScene::OnSceneStop()" << std::endl;
}


/**
 * implementation
 */
void TestScene::OnSceneActorUpdate(Timestep DeltaTime)
{
	std::cout << "TestScene::OnSceneActorUpdate(" << DeltaTime << ")" << std::endl;
}


/**
 * implementation
 */
void TestScene::OnSceneActorPhysicsUpdate(PhysicsTimestep DeltaTime)
{
	std::cout << "TestScene::OnSceneActorPhysicsUpdate(" << DeltaTime << ")" << std::endl;
}


