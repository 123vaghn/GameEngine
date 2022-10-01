
#include "pch.h"
#include "Game/Game.h"

using namespace Engine;
using namespace Engine::Components;
using namespace Engine::Graphics;

namespace MyApp
{
	std::string LoadShaderFromFile(const char *FilePath)
	{
		std::string s = "";
		std::ifstream stream(FilePath);

		if (stream)
		{
			stream.seekg(0, std::ios::end);
			s.resize(stream.tellg());
			stream.seekg(0, std::ios::beg);
			stream.read(&s[0], s.size());
			stream.close();
		}
		else
		{
			std::terminate();
		}

		return s;
	}

	VectorF ComputeFaceNormal(const VectorF &A, const VectorF &B, const VectorF &C)
	{
		auto v1 = B - A;
		auto v2 = C - A;

		return VectorF::GetCrossProduct(v1, v2).GetNormalizedVector();
	}

	std::vector<Vertex> &CalculateNormals(std::vector<Vertex> &vertices, const std::vector<uint32_t> &indices)
	{
		for (auto i = 0; i < indices.size(); i += 3)
		{
			uint32_t i0 = indices[i];
			uint32_t i1 = indices[i + 1];
			uint32_t i2 = indices[i + 2];

			VectorF FaceNormal = ComputeFaceNormal(vertices[i0].Position, vertices[i1].Position, vertices[i2].Position);

			vertices[i0].Normal += FaceNormal;
			vertices[i1].Normal += FaceNormal;
			vertices[i2].Normal += FaceNormal;
		}

		for (auto i = 0; i < vertices.size(); i++)
		{
			vertices[i].Normal.Normalize();
		}

		return vertices;
	}
}
