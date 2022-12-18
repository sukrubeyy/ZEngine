#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace ZEngine {
	namespace graphics {

#define MAXIMUMKEYS 1024
#define MAX_BUTTONS 32

		class Window {
		public:
			Window* INSTANCE;
		private:
			const char* name;
			int width, height;
			GLFWwindow* window;
			bool close;

			bool keys[MAXIMUMKEYS];
			bool mouseButtons[MAX_BUTTONS];
			double x, y;
		public:
			Window(const char* name, int width, int height);
			~Window();

			void update();

			bool keyPressed(unsigned int keyCode) const;
			bool mouseButtonPressed(unsigned int btnCode) const;
			void getMousePos(double& x, double& y) const;

			void clear()const;
			bool closed()const;
			inline int getWidth() { return width; }
			inline int getHeight() { return height; }

			
		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}