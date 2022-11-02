#include <iostream>
#include "src/graphics/window.h"

int main()
{
	using namespace ZEngine;
	using namespace graphics;

	//ZEngine penceresi oluþturuluyor.
	Window window("ZEngine", 800, 600);

	//Motorun arkaplan rengini belirler
	//RGB-Doygunluk
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//OpenGL versiyonunu konsol ekranýna yazdýrýyorum
	std::cout << glGetString(GL_VERSION) << std::endl;

	//ZEngine penceresi kapatýlmadýðý sürece döngü devam etsin
	while (!window.closed()) {
		//Buffer Temizleme iþlemi çaðýrýlýyor
		window.clear();

		double x, y;
		window.getMousePos(x, y);
		std::cout << x << "," << y << std::endl;

		

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