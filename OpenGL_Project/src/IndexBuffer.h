#pragma once

class IndexBuffer
{
private:
	unsigned int m_RendererID;

public:
	IndexBuffer(void* data, unsigned int size);
	~IndexBuffer();

	void Bind();
	void Unbind();
};