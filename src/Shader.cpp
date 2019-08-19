#include "Shader.hpp"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vString = getFromFile(vertexPath);
    std::string fString = getFromFile(fragmentPath);

   	vShaderCode = vString.c_str();
    fShaderCode = fString.c_str();

  	compile();
  	use();
}

std::string Shader::getFromFile(const std::string &filename)
{
	std::ifstream   ifs(filename);
    std::string     content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return (content);
}

void			Shader::compile(void)
{
	char            info_log[512];
    int             success;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
		glGetShaderInfoLog(vertex, 512, NULL, info_log);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
		glGetShaderInfoLog(fragment, 512, NULL, info_log);

	id = glCreateProgram();
	glAttachShader(id, vertex);
	glAttachShader(id, fragment);
	glLinkProgram(id);
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success)
		glGetProgramInfoLog(id, 512, NULL, info_log);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
