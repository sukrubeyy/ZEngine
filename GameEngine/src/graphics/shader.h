#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../utils/fileutils.h"
namespace ZEngine {
	namespace maths {
		class Shader {
		public:
			GLuint m_ShaderID;
			const char* m_vertPath;
			const char* m_fragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
	}
}
