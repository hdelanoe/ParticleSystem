#include "Env.hpp"


Env::Env(void)
: GlobalWorkSize({NUM_PARTICLES, 1, 1}), LocalWorkSize({LOCAL_SIZE, 1, 1}) 
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

void		Env::initGladEnvironment(void)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw GladException();

}

void		Env::initCL(void)
{
	cl_int status = clGetPlatformIDs( 1, &Platform, NULL );
	PrintCLError(status, "clGetPlatformIDs: ");
	status = clGetDeviceIDs(Platform, CL_DEVICE_TYPE_GPU, 1, &Device, NULL );
	PrintCLError(status, "clGetDeviceIDs: ");
	
	if (!IsCLExtensionSupported("cl_khr_gl_sharing"))
		throw CLException();

	#ifdef __APPLE__
		cl_context_properties props[] = 
		{
			CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE,
			(cl_context_properties) kCGLShareGroup,
			0
		};
		cl_context Context = clCreateContext( props, 0, 0, NULL, NULL, &status);
	#elif __LINUX__
		cl_context_properties props[] = 
		{
			CL_GL_CONTEXT_KHR,	(cl_context_properties) glXGetCurrentContext(),
			CL_GLX_DISPLAY_KHR,	(cl_context_properties) glXGetCurrentDisplay(),
			CL_CONTEXT_PLATFORM,(cl_context_properties) Platform,
			0
		};
		cl_context Context = clCreateContext( props, 0, 0, NULL, NULL, &status);
	#endif
}

bool		Env::isCLExtensionSupported(const char* extension)
{
	if (extension == NULL || extension[0] == '\0')
		return false;
	char* where = (char*)strchr(extension, ' ');
	if (where != NULL)
		return false;
	
	size_t extensionSize;
	clGetDeviceInfo(Device, CL_DEVICE_EXTENSIONS, 0, NULL, &extensionSize);
	char* extensions = new char[extensionSize];
	clGetDeviceInfo(Device, CL_DEVICE_EXTENSIONS, extensionSize, extensions, NULL);

	for(char* start = extensions ;  ; )
	{
		where = (char*) strstr((const char *) start, extension);
		if(where == 0)
		{
			delete [] extensions;
			return false;
		}
		char* terminator = where + strlen(extension);
		if (*terminator == ' ' || *terminator == '\0' ||
			*terminator == '\r' || *terminator == '\n')
		{
			delete [] extensions;
			return true;
		}
		start = terminator;
	}
}

const char* Env::GlfwException::what() const throw() { return ("glfw initialization failed"); }
const char* Env::WindowException::what() const throw() { return ("window initialization failed"); }
const char* Env::GladException::what() const throw() { return ("glad initialization failed"); }
const char* Env::CLException::what() const throw() { return ("OpenCL initialization failed"); }
