//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_RENDERER_HPP
#define SOKULIB_RENDERER_HPP


namespace SokuLib
{
	struct Renderer {
		bool begin();
		void end();
	};

	extern Renderer &renderer;
}


#endif //SOKULIB_RENDERER_HPP
