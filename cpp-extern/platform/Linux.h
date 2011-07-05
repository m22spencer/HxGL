#ifndef PLATFORM_LINUX_H
#define PLATFORM_LINUX_H

#include "IPlatform.h"
#include "../wnd/SFML_WND.h"
#include "../glwrapper/GLES20.h"
#include "../glwrapper/GLES11.h"
#include <iostream>
#include "../Log.h"
#include <unistd.h>

namespace platform
{
	class Linux : public IPlatform
	{
	public:
		Linux();
		~Linux();

		void beginMain();
		void allocateGLW(unsigned char major, unsigned char minor);
	};
}

#endif //PLATFORM_LINUX_H
