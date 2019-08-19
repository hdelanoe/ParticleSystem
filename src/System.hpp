#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "ParticleSystem.hpp"

class Shader;

class System
{
	public:

		System(void);
		~System(void) {};

		unsigned int		const	&getId(void)	const	{ return id; }

		void				bind(void);

	private:

		GLuint				VAO;
		GLuint				VBO;
};

#endif
