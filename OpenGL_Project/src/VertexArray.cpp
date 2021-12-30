#include "VertexArray.h"
#include <GL/glew.h>

#include <vector>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
	glBindVertexArray(m_RendererID);
}

VertexArray::~VertexArray()
{
}

void VertexArray::Bind()
{
	glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::AddBuffer(VertexBuffer vb, VertexBufferLayout layout)
{
	vb.Bind();
	std::vector<VertexBufferElement> elements = layout.GetElements();

	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		VertexBufferElement element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.size, element.type, element.normalized ? GL_TRUE : GL_FALSE, element.stride, (void *) offset);
		offset += element.stride;
	}
}
