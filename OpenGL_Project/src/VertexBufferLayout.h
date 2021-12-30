#pragma once

#include <vector>

struct VertexBufferElement
{
	unsigned int size;
	unsigned int type;
	bool		 normalized;
	unsigned int stride;
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;

public:
	VertexBufferLayout();
	~VertexBufferLayout();

	template<typename T>
	void Push(unsigned int count, bool normalized);
	template<> void Push<float>(unsigned int count, bool normalized);
	template<> void Push<unsigned int>(unsigned int count, bool normalized);
	template<> void Push<unsigned char>(unsigned int count, bool normalized);

	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }

};
