#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace ZEngine {
	namespace graphics {

#define MAXIMUMKEYS 1024
#define MAXIMUMBUTTON 32

		class Window {
		public:
			Window* INSTANCE;
		private:
			const char* name;
			int width, height;
			GLFWwindow* window;
			bool close;
			static bool keys[MAXIMUMKEYS];
			static bool buttons[MAXIMUMBUTTON];
			static double x, y;
		public:
			Window(const char* name, int width, int height);
			~Window();
			void update();
			void clear()const;
			bool closed()const;

			inline int getWidth() { return width; }
			inline int getHeight() { return height; }
			static bool keyPressed(unsigned int keyCode);
		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}