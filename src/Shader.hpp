#ifndef SHADER_HPP
#define SHADER_HPP

#include "Env.hpp"
#include "ParticleSystem.hpp"

class Shader
{
    public:

        Shader(void) {}
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader(void) { glDeleteProgram(id); }

        unsigned int	getId(void) { return id; }
        void			use(void)  	{ glUseProgram(id); }
        void			compile(void);

        void setInt(const std::string &name, int value) const { glUniform1i(glGetUniformLocation(id, name.c_str()), value); }
        void setFloat(const std::string &name, float value) const { glUniform1f(glGetUniformLocation(id, name.c_str()), value); }
        void setVec2(const std::string &name, const glm::vec2 &value) const { glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]); }
        void setVec3(const std::string &name, const glm::vec3 &value) const { glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]); }
        void setVec4(const std::string &name, const glm::vec4 &value) const { glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]); }
        void setMat3(const std::string &name, const glm::mat3 &mat) const { glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]); }
        void setMat4(const std::string &name, const glm::mat4 &mat) const { glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]); }

    private:

        unsigned int    id;
        unsigned int    vertex;
        unsigned int    fragment;
        const char*     vShaderCode;
        const char*     fShaderCode;

        std::string   getFromFile(const std::string &filename);
};

#endif
