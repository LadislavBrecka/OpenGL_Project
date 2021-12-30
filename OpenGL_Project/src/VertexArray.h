#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_RendererID;

public:
	VertexArray();
	~VertexArray();
	void Bind();
	void Unbind();
	void AddBuffer(VertexBuffer vb, VertexBufferLayout layout);
};