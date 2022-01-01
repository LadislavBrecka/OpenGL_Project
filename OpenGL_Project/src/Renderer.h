#pragma once
#include "GL/glew.h"

#include "IndexBuffer.h"
#include "VertexArray.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Draw(VertexArray& va, IndexBuffer& ib);
	void Clear();
};

