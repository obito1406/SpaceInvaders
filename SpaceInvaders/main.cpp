// GLEW	(GLEW library includes OpenGl library itself) //This allow us to use glew as an static library(.lib) otherwise it will search for a .dll

#define GLEW_STATIC		
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

//Otras librerias comunes
#include <iostream>
#include <Windows.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);  //Aunque la creemos nosotros es el prototipo que acepta glfwSetKeyCallback.



int main()
{
	glfwInit();	//Ha de siempre ser inicializado para poder usarse GLFW y debera ser terminado [glfwTerminate()] al acabar la aplicacion
				//Para info sobre las distintas configuraciones de pantalla mirar http://www.glfw.org/docs/latest/window.html#window_hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//Usa un set limitado de OpengGL solo los metodos mas nuevos, quitandonos compatibilidad pero siendo mas facil el desarrollo.
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL WINDOW", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	//Seleccionamos que ahora esta es la ventana activa y la que estara asociada al thread.

	glewExperimental = GL_TRUE;	//FALLA I DONT KNOW WHY Se usas tecniacas modernas para manejar OpenGl. Asegurando no utilizar metodos obsoltos

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//Hay que especificar el tamaño de la ventana donde queremos renderizar para que opneGL lo sepa
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);	//Obtencion del tamaño de la ventana a partir de esta
	glViewport(0, 0, width, height);	//0,0  es la localizacion de el origen de coordenadas en este caso la esquina izquierda inferior.

	glfwSetKeyCallback(window, key_callback);

	//Game Loop
	while (!glfwWindowShouldClose(window))
	{
		//Check and CallBacks
		glfwPollEvents(); //To check if any event has been triggered ALWAYS FIRST

						  //Rendering commmands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);	//This will clear the buffer and the new buffer will be colored with the color specified in glClearColor method

										//Swap the buffers
		glfwSwapBuffers(window);	//Actualiza la pantalla?
	}
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)  //Aunque la creemos nosotros es el prototipo que acepta glfwSetKeyCallback.
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
