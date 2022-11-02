#include "window.h"
namespace ZEngine {
	namespace graphics {

		void resize_Window(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int key, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		Window::Window(const char* name, int width, int height) {
			this->name = name;
			this->width = width;
			this->height = height;
			if (!init())
				glfwTerminate();

			for (int i = 0; i < MAXIMUMKEYS; i++) {
				keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++) {
				mouseButtons[i] = false;
			}
			INSTANCE = this;
		}

		Window::~Window() {
			//Tüm pencereler yok edilir
			glfwTerminate();
		}

		bool Window::init() {
			std::cout << "Initalize" << std::endl;
			//GLFW Initialize edilmediyse
			if (!glfwInit())
			{
				std::cout << "Failed To Initialize GLFW" << std::endl;
				return false;
			}

			//ZEngine penceresinin size parametreleri belirlenip ekran oluþturuluyor.
			this->window = glfwCreateWindow(this->width, this->height, this->name, NULL, NULL);
			//Eðer pencere oluþturulmadýysa
			if (!this->window) {
				std::cout << "Failed to create GLFW Window" << std::endl;
				return false;
			}

			//Ana Context olarak penceremizi gönderiyoruz
			glfwMakeContextCurrent(this->window);
			//Ne iþe yarýyor unuttum
			glfwSetWindowUserPointer(this->window, this);
			//listen mouse button input callback
			glfwSetMouseButtonCallback(this->window, mouse_button_callback);
			//listen keyboard input callback
			glfwSetKeyCallback(this->window, key_callback);

			//ResizeWindow CallBack olarak eklenir
			glfwSetWindowSizeCallback(window, resize_Window);

			//Mouse Cursor CallBack
			glfwSetCursorPosCallback(this->window, cursor_position_callback);

			if (glewInit() != GLEW_OK) {
				std::cout << "could not initialize GLEW" << std::endl;
				return false;
			}
			return true;
		}

		bool Window::keyPressed(unsigned int keyCode) const {
			if (keyCode >= MAXIMUMKEYS)
				return false;
			return keys[keyCode];
		}

		bool Window::mouseButtonPressed(unsigned int btnCode) const {
			if (btnCode >= MAX_BUTTONS)
				return false;

			return mouseButtons[btnCode];
		}

		void Window::getMousePos(double& xPos, double& yPos) const {
			xPos = x;
			yPos = y;
		}

		void Window::clear() const {
			//Biraz tampon temizliði yapalým
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::closed()const {
			//Eðer glfwWindowShouldClose 1 deðeri döndürüyorsa pencere kapatýlmýþtýr.
			return glfwWindowShouldClose(this->window) == 1;
		}
		void Window::update() {
			glfwPollEvents();
			//glfwGetFramebufferSize(this->window, &this->width, &this->height);
			glfwSwapBuffers(this->window);
		}
		void resize_Window(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int key, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mouseButtons[key] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->x = xpos;
			win->y = ypos;
		}
	}
}