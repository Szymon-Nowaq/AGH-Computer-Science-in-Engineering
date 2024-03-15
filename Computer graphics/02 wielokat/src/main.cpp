#include <iostream>
#include <glad/glad.h>  // musi być dołączony jako pierwszy
#include <GLFW/glfw3.h>

# define M_PI           3.14159265358979323846

#include<math.h>

using namespace std;

int main()
{
    // inicjalizacja GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Tworzenie okna
    const unsigned int window_width = 800;
    const unsigned int window_height = 800;
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "grafika komputerowa", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    // inicjalizacja GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    glViewport(0, 0, (GLuint)window_width, (GLuint)window_height);
    
    int n_vert;
    cout<<"podaj ilosc wierzhcolkow: ";
    cin>>n_vert;

    const float r = 0.3; 
    const float alpha = (360.0f / n_vert) * (M_PI / 180.0f);

    // Tworzenie tablicy na współrzędne wierzchołków
    // Każdy trójkąt potrzebuje 3 punktów, każdy punkt ma 3 współrzędne, więc potrzebujemy n_vert * 3 * 3 elementów
    GLfloat *vertices = new GLfloat[(n_vert + 1) * 6]; 

    vertices[0] = 0.0f;
    vertices[1] = 0.0f; 
    vertices[2] = 0.0f;
    vertices[3] = 0.0f; 
    vertices[4] = 1.0f; 
    vertices[5] = 0.0f;

    for(int i = 1; i < n_vert + 1; i++){

        // wsp
        vertices[i * 6 ] = r * std::cos(i * alpha); 
        vertices[i * 6 + 1] = r * std::sin(i * alpha); 
        vertices[i * 6 + 2] = 0.0f; 

        // kolor
        vertices[i * 6 + 3] = 0.0f;
        vertices[i * 6 + 4] = 1.0f;
        vertices[i * 6 + 5] = 0.0f; 
    }

    GLuint *indices = new GLuint[n_vert * 3];
    for(int i = 0; i < n_vert; i++){
        indices[3 * i] = 0; 
        indices[3 * i + 1] = i + 1; 

        if(i == n_vert - 1){
            indices[3 * i + 2] = 1; 
        } else {
            indices[3 * i + 2] = i + 2;
        }
    }

    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, (n_vert + 1) * 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);


    GLuint EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, n_vert * 3 * sizeof(GLuint), indices, GL_STATIC_DRAW);

    delete [] indices;
    delete [] vertices;

    const GLchar* vertexShaderSource =
    "#version 330 core\n"
    "layout(location = 0) in vec3 position;\n"
    "layout(location = 1) in vec3 color;\n"
    "out vec3 vertexColor;\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    " vertexColor = color;\n"
    "}\0";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint status;
    GLchar error_message[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, error_message);
        std::cout << "Error (Vertex shader): " << error_message << std::endl;
    }

    const GLchar* fragmentShaderSource =
    "#version 330 core\n"
    "in vec3 vertexColor;\n"
    "out vec4 fragmentColor;\n"
    "void main()\n"
    "{\n"
    " fragmentColor = vec4(vertexColor, 1.0);\n"
    "}\0";

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, error_message);
        std::cout << "Error (Fragment shader): " << error_message << std::endl;
    }

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
    if (!status)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, error_message);
        std::cout << "Error (Shader program): " << error_message << std::endl;
    }

    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glUseProgram(shaderProgram);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);




    // pętla zdarzeń
    while (!glfwWindowShouldClose(window))
    {
        // renderowanie
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, n_vert * 3, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    

    glfwTerminate();
    return 0;
}