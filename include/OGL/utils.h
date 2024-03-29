#pragma once

#include <vector>
#include <string>

#include <GL/glut.h>
#include "Base/Game.h"

void draw_triangle();
GLuint load_image_file(std::string filename);
GLuint display_image(float position_x, float position_y, std::vector<float> image_data);
void display_image(float position_x, float position_y, GLuint texture);
void start_drawing(void);
std::vector<GLuint> load_all_images();
void display_player_cards(Game,std::vector<GLuint>,int playerno = 0,float=0, float =0);
void draw_full_box();
