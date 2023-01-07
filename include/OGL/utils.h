#include <vector>
#include <string>

#include <GL/glut.h>

void DrawTriangle();
GLuint load_image_file(std::string filename);
GLuint display_image(float position_x, float position_y, std::vector<float> image_data);
void display_image(float position_x, float position_y, GLuint texture);
void StartDrawing(void);
