#include "Renderer.h"



Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Draw(VertexArray& va, IndexBuffer& ib)
{
	va.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
