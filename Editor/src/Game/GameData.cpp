
#include "pch.h"
#include "Game/Game.h"
#include "Game/Application.h"
#include "Game/TestScene.h"
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Math/QuaternionF.h"
#include "Engine/Math/VectorF.h"
#include "Engine/Engine/Actor.h"
#include "Engine/Engine/Components/Behavior.h"
#include "Engine/Engine/Components/Camera.h"
#include "Engine/Engine/SceneGraph.h"
#include "Engine/Engine/Scene.h"
#include "Engine/Engine/Graphics/DirectionalLight.h"
#include "Engine/Engine/Graphics/DynamicIndexBuffer.h"
#include "Engine/Engine/Graphics/DynamicVertexBuffer.h"
#include "Engine/Engine/Graphics/IndexBuffer.h"
#include "Engine/Engine/Graphics/Graphics.h"
#include "Engine/Engine/Graphics/Mesh.h"
#include "Engine/Engine/Graphics/Shader.h"
#include "Engine/Engine/Graphics/Texture2D.h"
#include "Engine/Engine/Graphics/VertexBuffer.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Components;
using namespace Engine::Graphics;

using namespace MyApp;


namespace MyApp
{
	std::shared_ptr<Scene> s_ActiveScene;
	uint32_t s_VAO;
	std::unique_ptr<DynamicIndexBuffer> s_IBO;
	std::unique_ptr<DynamicVertexBuffer> s_VBO;
	std::unique_ptr<Texture2D> s_Texture2D;
	std::unique_ptr<Shader> s_BasicShader;
	std::unique_ptr<Shader> s_PhongShader;
	std::unique_ptr<Script> s_Script1;
	std::unique_ptr<Script> s_Script2;
	std::unique_ptr<Script> s_Script3;
	std::unique_ptr<Script> s_Script4;
	std::unique_ptr<Script> s_Script5;
	std::unique_ptr<Script> s_Script6;
}

/**
 * implementation
 */
void MyApp::InitGameData()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D_ARRAY);
	glEnable(GL_BLEND);

	glGenVertexArrays(1, &s_VAO);
	glBindVertexArray(s_VAO);

	std::vector<uint32_t> indices =
	{
		0, 1, 2,
		2, 3, 0
	};

	std::vector<Vertex> vertices =
	{
		{ -1, -1, 0, 0, 0 },
		{  1, -1, 0, 1, 0 },
		{  1,  1, 0, 1, 1 },
		{ -1,  1, 0, 0, 1 }
	};

	s_IBO = std::unique_ptr<DynamicIndexBuffer>(
		DynamicIndexBuffer::Create(
			indices
		));

	s_VBO = std::unique_ptr<DynamicVertexBuffer>(
		DynamicVertexBuffer::Create(
			CalculateNormals(vertices, indices)
		));

	glBindVertexArray(0);

	std::string vs = MyApp::LoadShaderFromFile("Basic.Vertex.glsl");
	std::string fs = MyApp::LoadShaderFromFile("Basic.Fragment.glsl");

	s_BasicShader = std::unique_ptr<Shader>(
		Shader::Create
		(
			vs.c_str(),
			fs.c_str()
		));

	vs = LoadShaderFromFile("Phong.Vertex.glsl");
	fs = LoadShaderFromFile("Phong.Fragment.glsl");

	s_PhongShader = std::unique_ptr<Shader>(
		Shader::Create
		(
			vs.c_str(),
			fs.c_str()
		));


	s_Texture2D = std::unique_ptr<Texture2D>(Texture2D::Create(256, 256, 4, "C:\\Users\\HeatS\\Desktop\\Texture.png"));
}
