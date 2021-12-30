#pragma once
#include <string>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	unsigned int m_RendererID;

	ShaderProgramSource parseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind();
	void Unbind();

	void SetUniform1f(const std::string& name, float f1);
	void SetUniform2f(const std::string& name, float f1, float f2);
	void SetUniform3f(const std::string& name, float f1, float f2, float f3);
	void SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4);
};

