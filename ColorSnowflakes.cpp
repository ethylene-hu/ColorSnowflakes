/*
 * By Arect
 * 2020/10/23
 * OpenGL study
 */
#include<glut.h>
#include<Windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.1415926535
const GLfloat px = 0.01f;
static GLfloat distance_sight = 2;
static GLfloat eyex = 0;
static GLfloat eyey = 0;
static GLfloat eyez = distance_sight;
static GLfloat centerx = 0;
static GLfloat centery = 0;
static GLfloat centerz = 0;
static GLfloat upx = 0;
static GLfloat upy = 1;
static GLfloat upz = 0;
static GLfloat sight = 90;
static GLfloat width = 400;
static GLfloat height = 400;
static GLfloat ah = 0;
static GLfloat dh = 0;
static int counter = 0;
static double fov_sight = 0;
const unsigned char up_key = 'w';
const unsigned char down_key = 's';
const unsigned char left_key = 'a';
const unsigned char right_key = 'd';
const unsigned char closer_key = 'q';
const unsigned char farther_key = 'e';

struct color_code
{
	GLubyte red = 0;
	GLubyte green = 0;
	GLubyte blue = 0;
	GLubyte alpha = 255;
};
struct color
{
	color_code* foreground_color = new color_code;
	color_code* background_color = new color_code;
} default_color;
color* color_array[3];

void init_main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("彩色雪花");
}
void init_draw() {
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void init_color() {
	color_array[0] = new color;
	color_array[1] = new color;
	color_array[2] = new color;
	color_array[0]->background_color->red = 33;
	color_array[0]->background_color->green = 150;
	color_array[0]->background_color->blue = 243;
	color_array[0]->foreground_color->red = 227;
	color_array[0]->foreground_color->green = 242;
	color_array[0]->foreground_color->blue = 253;
	color_array[0]->foreground_color->alpha = 0;
	color_array[1]->background_color->red = 255;
	color_array[1]->background_color->green = 152;
	color_array[1]->background_color->blue = 0;
	color_array[1]->foreground_color->red = 255;
	color_array[1]->foreground_color->green = 243;
	color_array[1]->foreground_color->blue = 224;
	color_array[1]->foreground_color->alpha = 0;
	color_array[2]->background_color->red = 0;
	color_array[2]->background_color->green = 0;
	color_array[2]->background_color->blue = 0;
	color_array[2]->foreground_color->red = 255;
	color_array[2]->foreground_color->green = 255;
	color_array[2]->foreground_color->blue = 255;
	color_array[2]->foreground_color->alpha = 0;
}
void draw_snow_body(GLfloat size, GLfloat dpx, color color_ = default_color) {
	GLfloat pxt = size * px;
	glBegin(GL_POLYGON);
	{
		glColor4ub(
			color_.background_color->red,
			color_.background_color->green,
			color_.background_color->blue,
			color_.background_color->alpha
		);
		glVertex3f(-pxt, 0 * pxt, dpx);
		glVertex3f(pxt, 0 * pxt, dpx);
		glVertex3f(pxt, 12 * pxt, dpx);
		glVertex3f(-pxt, 12 * pxt, dpx);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor4ub(
			color_.background_color->red,
			color_.background_color->green,
			color_.background_color->blue,
			color_.background_color->alpha
		);
		glVertex3f(pxt, 12 * pxt, dpx);
		glVertex3f(-pxt, 12 * pxt, dpx);
		glVertex3f(0, 13 * pxt, dpx);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor4ub(
			color_.background_color->red,
			color_.background_color->green,
			color_.background_color->blue,
			color_.background_color->alpha
		);
		glVertex3f(-pxt, 4 * pxt, dpx);
		glVertex3f(-pxt, 6 * pxt, dpx);
		glColor4ub(
			color_.foreground_color->red,
			color_.foreground_color->green,
			color_.foreground_color->blue,
			color_.foreground_color->alpha
		);
		glVertex3f(-3.5 * pxt, 9 * pxt, dpx);
		glVertex3f(-3.5 * pxt, 7 * pxt, dpx);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor4ub(
			color_.background_color->red,
			color_.background_color->green,
			color_.background_color->blue,
			color_.background_color->alpha
		);
		glVertex3f(pxt, 4 * pxt, dpx);
		glVertex3f(pxt, 6 * pxt, dpx);
		glColor4ub(
			color_.foreground_color->red,
			color_.foreground_color->green,
			color_.foreground_color->blue,
			color_.foreground_color->alpha
		);
		glVertex3f(3.5 * pxt, 9 * pxt, dpx);
		glVertex3f(3.5 * pxt, 7 * pxt, dpx);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor4ub(
			color_.background_color->red,
			color_.background_color->green,
			color_.background_color->blue,
			color_.background_color->alpha
		);
		glVertex3f(-pxt, 8 * pxt, dpx);
		glVertex3f(-pxt, 10 * pxt, dpx);
		glColor4ub(
			color_.foreground_color->red,
			color_.foreground_color->green,
			color_.foreground_color->blue,
			color_.foreground_color->alpha
		);
		glVertex3f(-2.5 * pxt, 12 * pxt, dpx);
		glVertex3f(-2.5 * pxt, 10 * pxt, dpx);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glColor4ub(
			color_.background_color->red,
			color_.background_color->green,
			color_.background_color->blue,
			color_.background_color->alpha
		);
		glVertex3f(pxt, 8 * pxt, dpx);
		glVertex3f(pxt, 10 * pxt, dpx);
		glColor4ub(
			color_.foreground_color->red,
			color_.foreground_color->green,
			color_.foreground_color->blue,
			color_.foreground_color->alpha
		);
		glVertex3f(2.5 * pxt, 12 * pxt, dpx);
		glVertex3f(2.5 * pxt, 10 * pxt, dpx);
	}
	glEnd();
}
void draw_snow_by_quads(GLfloat size, GLfloat dpx, color color_ = default_color) {
	glPushMatrix();
	for (int i = 0; i < 6; i++) {
		draw_snow_body(size, dpx, color_);
		glRotatef(60, 0, 0, 1);
	}
	glPopMatrix();
}
void spiral_ascension(GLfloat angle, GLfloat distance) {
	ah = angle;
	dh = distance;
	glTranslatef(0, distance, 0);
	glRotatef(angle, 0, 0, 1);
}
void undo_sa() {
	glRotatef(-ah, 0, 0, 1);
	glTranslatef(0, -dh, 0);
	gluLookAt(
		eyex, eyey, eyez,
		centerx, centery, centerz,
		upx, upy, upz
	);
}
void move_position(GLfloat x, GLfloat y, GLfloat z = 0) {
	glTranslatef(x, y, z);
}
void see_rightly() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(sight, width / height, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		eyex, eyey, eyez,
		centerx, centery, centerz,
		upx, upy, upz
	);
}
void rotating_observation(float direction) {
	fov_sight += direction * 0.1 * PI;
	eyex = distance_sight * sin(fov_sight);
	eyez = distance_sight * cos(fov_sight);
}
void my_display() {
	init_draw();
	{
		see_rightly();
		move_position(0.2, 0.2);
		spiral_ascension(1 * counter, -0.001 * counter);
		draw_snow_by_quads(2, -0.1, *color_array[0]);
		undo_sa();
	}
	{
		see_rightly();
		move_position(0, 0);
		spiral_ascension(1 * counter, -0.001 * counter);
		draw_snow_by_quads(2, -0.2, *color_array[1]);
		undo_sa();
	}
	{
		see_rightly();
		move_position(-0.2, 0.2);
		spiral_ascension(1 * counter, -0.001 * counter);
		draw_snow_by_quads(2, -0.3, *color_array[2]);
		undo_sa();
	}
	{
		see_rightly();
		move_position(-0.5, 0.2);
		glRotatef(60, 0, 1, 0);
		spiral_ascension(1 * counter, -0.001 * counter);
		draw_snow_by_quads(2, -0.3, *color_array[0]);
		undo_sa();
		glRotatef(-60, 0, 1, 0);
	}
	counter++;
	Sleep(5);
	rotating_observation(0.05);
	glutPostRedisplay();
	glutSwapBuffers();
}
void my_keyboard_fun(unsigned char key, int x, int y) {
	printf("[keyfunc] key: %c(%d), x: %d, y: %d\n", key, key, x, y);
	switch (key)
	{
	case up_key: {
		eyey -= px;
		centery -= px;
		break;
	}
	case down_key: {
		eyey += px;
		centery += px;
		break;
	}
	case left_key: {
		// eyex += px;
		// centerx += px;
		rotating_observation(-1);
		break;
	}
	case right_key: {
		// eyex -= px;
		// centerx -= px;
		rotating_observation(1);
		break;
	}
	case closer_key: {
		sight -= 10;
		break;
	}
	case farther_key: {
		sight += 10;
		break;
	}
	case 27: {
		exit(0);
	}
	default:
		break;
	}
}
void my_resize_fun(int w, int h) {
	printf("[resizefunc] w: %d, h: %d\n", w, h);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	if (w == 0) {
		w = 1;
	}
	if (h == 0) {
		h = 1;
	}
	width = w;
	height = h;
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	init_main();
	init_color();
	glutDisplayFunc(my_display);
	glutKeyboardFunc(my_keyboard_fun);
	glutReshapeFunc(my_resize_fun);
	glutMainLoop();
	return 0;
}