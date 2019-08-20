#ifndef ENV_HPP
#define ENV_HPP

#include "ParticleSystem.hpp"

class Env
{
	public:

		Env(void);
		~Env(void) {};

		void				initGlfwEnvironment(void);
		void				initGlfwWindow(void);
		void				initGladEnvironment(void);
		void				initCL(void);

		GLFWwindow*			getGLFWwin(void);
		float const			&getTime(void) const	{ return time; }
		void				setTime(float t)		{ time = t; }
		
		bool				isCLExtensionSupported(const char* extension);

	private:

		GLFWwindow*			window;
		
		size_t 				GlobalWorkSize[3];
		size_t  			LocalWorkSize[3];

		GLuint				hPobj;
		GLuint				hCobj;
		struct xyzw*		hvel;
		cl_mem				dPobj;
		cl_mem				dCobj;
		cl_mem				dVel;

		cl_command_queue	CmdQueue;
		cl_device_id		Device;
		cl_kernel			Kernel;
		cl_platform_id		Platform;
		cl_program			Program;


		float				time;
		float				frames;

        class 				GlfwException: public std::exception { virtual const char* what() const throw(); };
        class 				WindowException: public std::exception { virtual const char* what() const throw(); };
        class      			GladException: public std::exception { virtual const char* what() const throw(); };
        class      			CLException: public std::exception { virtual const char* what() const throw(); };

};

void						framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif
