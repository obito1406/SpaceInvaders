// GLEW	(GLEW library includes OpenGl library itself)
#define GLEW_STATIC		//This allow us to use glew as an static library(.lib) otherwise it will search for a .dll
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

//Otras librerias comunes
#include <iostream>
#include <Windows.h>

int main()
{
	glfwInit();	//Ha de siempre ser inicializado para poder usarse GLFW y debera ser terminado [glfwTerminate()] al acabar la aplicacion
	//Para info sobre las distintas configuraciones de pantalla mirar http://www.glfw.org/docs/latest/window.html#window_hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//Usa un set limitado de OpengGL solo los metodos mas nuevos, quitandonos compatibilidad pero siendo mas facil el desarrollo.
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL WINDOW", nullptr, nullptr);
	if (window = nullptr)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	//Seleccionamos que ahora esta es la ventana activa y la que estara asociada al thread.
	
	//glewExperimental = GL_TRUE;	//FALLA I DONT KNOW WHY Se usas tecniacas modernas para manejar OpenGl. Asegurando no utilizar metodos obsoltos
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//Hay que especificar el tamaño de la ventana donde queremos renderizar para que opneGL lo sepa
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);	//Obtencion del tamaño de la ventana a partir de esta
	glViewport(0, 0, width, height);	//0,0  es la localizacion de el origen de coordenadas en este caso la esquina izquierda inferior.

	//Game Loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}