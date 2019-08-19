#include "ParticleSystem.hpp"
#include "Env.hpp"

const double maxFPS = 60.0;
const double maxPeriod = 1.0 / maxFPS;

int main(void)
{
    Env env;
    Shader shader(Shader("src/shader/model.vs", "src/shader/model.fs"));
    System system;

	while (!glfwWindowShouldClose(env.getGLFWwin()))
	{
	}

	glfwTerminate();
	return 0;
}
