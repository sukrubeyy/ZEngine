#include <iostream>
#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
	using namespace ZEngine;
	using namespace graphics;
	using namespace maths;
	//ZEngine penceresi olu�turuluyor.
	Window window("ZEngine", 800, 600);
	//Motorun arkaplan rengini belirler
	//RGB-Doygunluk
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	//Vertex Buffer Tamponu
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//OpenGL versiyonunu konsol ekran�na yazd�r�yorum
	std::cout << glGetString(GL_VERSION) << std::endl;
	//ZEngine penceresi kapat�lmad��� s�rece d�ng� devam etsin

	vec4 a(1.0f, 2.0f, 5.0f, 1.5f);
	vec4 b(2, 4, 6,3);
	vec4 c = a + b;
	while (!window.closed()) {
		
		//Buffer Temizleme i�lemi �a��r�l�yor
		window.clear();
		std::cout << a << std::endl;

		double x, y;
		window.getMousePos(x, y);
		

		//std::cout << x << "," << y << std::endl;
		if (window.keyPressed(GLFW_KEY_A))
		if (window.mouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f); //left bottom corner vertex
		glVertex2f(-0.5f, 0.5f);   // left top corner vertex
		glVertex2f(0.5f, 0.5f); //right bottom corner vertex
		glVertex2f(0.5f, -0.5f); //right top corner vertex
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}
	return 0;
}