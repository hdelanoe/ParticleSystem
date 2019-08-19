#include "Env.hpp"


Env::Env(void)
:time(glfwGetTime())
{
	try {
		initGlfwEnvironment();
		initGlfwWindow();
		initGladEnvironment();
	} catch (const std::exception& error) { std::cout << error.what() << std::endl; }

	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CW);
	glEnable(GL_MULTISAMPLE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

Env::~Env(void) {}

void		Env::initGlfwEnvironment(void)
{
	if (!glfwInit())
		throw GlfwException();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
}

void		Env::initGlfwWindow(void)
{
	if (!(window = glfwCreateWindow(W, H, "Particle System", NULL, NULL)))
		throw WindowException();
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

}
