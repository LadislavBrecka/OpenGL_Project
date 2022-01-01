#include "VertexBufferLayout.h"

#include "Renderer.h"

VertexBufferLayout::VertexBufferLayout()
{
}

VertexBufferLayout::~VertexBufferLayout()
{
}

template<typename T>
void VertexBufferLayout::Push(unsigned int count, bool normalized)
{
	static_assert(false);
}

template<>
void VertexBufferLayout::Push<float>(unsigned int count, bool normalized)
{
	m_Elements.push_back({ count, GL_FLOAT,  normalized, count * sizeof(GL_FLOAT) });
}

template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count, bool normalized)
{
	m_Elements.push_back({ count, GL_UNSIGNED_INT,  normalized, count * sizeof(GL_UNSIGNED_INT) });
}

template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count, bool normalized)
{
	m_Elements.push_back({ count, GL_UNSIGNED_BYTE,  normalized, count * sizeof(GL_UNSIGNED_BYTE) });
}