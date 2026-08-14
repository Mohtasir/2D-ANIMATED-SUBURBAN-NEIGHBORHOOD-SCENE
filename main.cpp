#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>


float cloudOffset = 0.0;
float carX = 140.0;
int carDirection = -1;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x + cx), (y + cy));
    }

    glEnd();
}


  void update(int value) {
    cloudOffset += 0.08;
    if (cloudOffset > 110.0) {
        cloudOffset = -40.0;
    }

    carX += 0.45 * carDirection;


    if (carX < -45.0) {
        carX = 140.0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void Draw()
{
    // Background
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5137, 0.7843, 0.8941);

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(100, 100);
    glVertex2i(0, 100);
    glEnd();

    // Cloud 1
    float c1 = cloudOffset;

    glColor3f(0.5, 0.5, 0.5);
    circle(1.5, 1.5, 2 + c1, 93);
    circle(1.8, 1.8, 3.5 + c1, 94);
    circle(1.9, 1.9, 5 + c1, 94.3);
    circle(1.7, 1.7, 6.5 + c1, 94);
    circle(1.4, 1.4, 8 + c1, 93);
    circle(1.3, 1.3, 3 + c1, 92.2);
    circle(1.4, 1.4, 5.5 + c1, 92);
    circle(1.2, 1.2, 7 + c1, 91.2);

    // Cloud 2
    float c2 = cloudOffset;

    glColor3f(0.5, 0.5, 0.5);
    circle(3, 3, 24 + c2, 86);
    circle(3.6, 3.6, 27 + c2, 88);
    circle(3.8, 3.8, 30 + c2, 88.6);
    circle(3.4, 3.4, 33 + c2, 88);
    circle(2.8, 2.8, 36 + c2, 86);
    circle(2.6, 2.6, 26 + c2, 84.4);
    circle(2.8, 2.8, 31 + c2, 84);
    circle(2.4, 2.4, 34 + c2, 84.4);

    // Cloud 3
    float c3 = cloudOffset;

    glColor3f(0.5, 0.5, 0.5);
    circle(3, 3, 44 + c2, 86);
    circle(3.6, 3.6, 47 + c2, 88);
    circle(3.8, 3.8, 50 + c2, 88.6);
    circle(3.4, 3.4, 53 + c2, 88);
    circle(2.8, 2.8, 56 + c2, 86);
    circle(2.6, 2.6, 46 + c2, 84.4);
    circle(2.8, 2.8, 51 + c2, 84);
    circle(2.4, 2.4, 54 + c2, 84.4);

    // ROAD
    glColor3f(0.4196, 0.4118, 0.3725);

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(100, 9);
    glVertex2i(0, 9);
    glEnd();

    glColor3f(0.2937, 0.2883, 0.2608);

    glBegin(GL_POLYGON);
    glVertex2i(0, 9);
    glVertex2i(90, 9);
    glVertex2i(88, 10);
    glVertex2i(0, 10);
    glEnd();

    glColor3f(0.7882, 0.7451, 0.6275);

    glBegin(GL_POLYGON);
    glVertex2i(0, 10);
    glVertex2i(88, 10);
    glVertex2i(82, 14);
    glVertex2i(0, 14);
    glEnd();

    glColor3f(0, 0, 0);

    glBegin(GL_LINES);
    glVertex2i(20, 10);
    glVertex2i(25, 14);
    glEnd();

    glColor3f(0, 0, 0);

    glBegin(GL_LINES);
    glVertex2i(39, 10);
    glVertex2i(42, 14);
    glEnd();

    glColor3f(0.7882, 0.7451, 0.6275);

    glBegin(GL_POLYGON);
    glVertex2i(88, 10);
    glVertex2i(91, 9);
    glVertex2i(100, 9);
    glVertex2i(100, 14);
    glVertex2i(82, 14);
    glEnd();

    glColor3f(0, 0, 0);

    glBegin(GL_LINES);
    glVertex2i(88, 10);
    glVertex2i(85, 14);
    glEnd();

    glColor3f(0, 0, 0);

    glBegin(GL_LINES);
    glVertex2i(91, 9);
    glVertex2i(87, 14);
    glEnd();

    glColor3f(0.7882, 0.7451, 0.6275);

    glBegin(GL_POLYGON);
    glVertex2i(42, 14);
    glVertex2i(61, 14);
    glVertex2i(57, 20);
    glVertex2i(47, 20);
    glEnd();

    //========

    // TREE
    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(17, 22);
    glVertex2i(19, 25);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(21, 25);
    glVertex2i(22, 22);
    glEnd();

    // Trunk main body
    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(19, 25);
    glVertex2i(18, 34);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(21, 34);
    glVertex2i(21, 25);
    glEnd();

    // Major Secondary Branches
    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(19, 33);
    glVertex2i(15, 39);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(16, 39);
    glVertex2i(20, 33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(19, 34);
    glVertex2i(24, 39);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(24, 39);
    glVertex2i(20, 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(19, 34);
    glVertex2i(18, 42);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(20, 42);
    glVertex2i(19, 34);
    glEnd();

    // Minor twigs
    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(15, 39);
    glVertex2i(13, 42);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(13, 42);
    glVertex2i(16, 39);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.15, 0.08);
    glVertex2i(24, 39);
    glVertex2i(26, 42);
    glColor3f(0.38, 0.26, 0.16);
    glVertex2i(27, 42);
    glVertex2i(24, 39);
    glEnd();

    //leaf 1
    glColor3f(0.12, 0.25, 0.10);
    circle(5, 4, 14, 39);
    circle(6, 5, 25, 38);
    circle(6, 5, 16, 43);
    circle(6, 5, 23, 42);
    circle(5, 4, 13, 43);
    circle(4, 4, 27, 42);
    circle(6, 6, 19, 46);
    circle(6, 5, 21, 47);
    circle(5, 4, 20, 50);

    // leaf 2
    glColor3f(0.20, 0.36, 0.15);
    circle(5, 4, 15, 39);
    circle(5, 4, 26, 39);
    circle(5, 5, 17, 43);
    circle(5, 4, 24, 43);
    circle(4, 4, 13, 44);
    circle(4, 3, 27, 43);
    circle(6, 5, 19, 47);
    circle(5, 4, 22, 48);
    circle(4, 4, 20, 50);

    // leaf 3
    glColor3f(0.28, 0.48, 0.20);
    circle(4, 3, 15, 39);
    circle(4, 3, 26, 39);
    circle(4, 4, 17, 43);
    circle(4, 4, 24, 43);
    circle(3, 3, 13, 44);
    circle(3, 3, 27, 43);
    circle(5, 4, 19, 47);
    circle(4, 4, 22, 48);
    circle(4, 3, 20, 50);

    // leaf 4
    glColor3f(0.42, 0.62, 0.26);
    circle(2, 2, 15, 40);
    circle(3, 2, 26, 39);
    circle(3, 2, 17, 44);
    circle(3, 2, 24, 43);
    circle(2, 2, 14, 44);
    circle(2, 2, 28, 43);
    circle(3, 3, 20, 47);
    circle(3, 2, 22, 48);
    circle(2, 2, 21, 51);

    // leaf 5
    glColor3f(0.55, 0.75, 0.32);
    circle(1, 1, 15, 40);
    circle(1, 1, 26, 39);
    circle(2, 1, 17, 44);
    circle(2, 1, 24, 43);
    circle(1, 1, 14, 44);
    circle(1, 1, 28, 43);
    circle(2, 2, 20, 47);
    circle(1, 1, 22, 48);
    circle(1, 1, 21, 51);

    // BACKGROUND LEFT SIDE WALL
    glColor3f(0.4392, 0.3804, 0.2667);

    glBegin(GL_POLYGON);
    glVertex2i(31, 22);
    glVertex2i(31, 30);
    glVertex2i(14, 30);
    glVertex2i(14, 22);
    glEnd();

    // GREEN PORTION LEFT SIDE
    glColor3f(0.4824, 0.4784, 0.3216);

    glBegin(GL_POLYGON);
    glVertex2i(42, 14);
    glVertex2i(0, 14);
    glVertex2i(0, 20);
    glVertex2i(11, 22);
    glVertex2i(31, 22);
    glVertex2i(31, 21);
    glVertex2i(46, 21);
    glVertex2i(46, 20);
    glVertex2i(47, 20);
    glEnd();

    glColor3f(0.4824, 0.4784, 0.3216);

    glBegin(GL_POLYGON);
    glVertex2i(0, 19);
    glVertex2i(14, 22);
    glVertex2i(14, 25);
    glVertex2i(0, 21);
    glEnd();

    // Right side
    glColor3f(0.4824, 0.4784, 0.3216);

    glBegin(GL_POLYGON);
    glVertex2i(61, 14);
    glVertex2i(85, 14);
    glVertex2i(65, 21);
    glVertex2i(58, 21);
    glVertex2i(58, 20);
    glVertex2i(57, 20);
    glEnd();

    // BRICK
    glColor3f(0.4392, 0.3804, 0.2667);

    glBegin(GL_POLYGON);
    glVertex2i(31, 24);
    glVertex2i(31, 21);
    glVertex2i(46, 21);
    glVertex2i(47, 22);
    glVertex2i(47, 24);
    glEnd();

    glColor3f(0.4392, 0.3804, 0.2667);

    glBegin(GL_POLYGON);
    glVertex2i(58, 24);
    glVertex2i(58, 21);
    glVertex2i(65, 21);
    glVertex2i(65, 22);
    glVertex2i(65, 24);
    glEnd();

    // LEFT BUILDING
    glColor3f(0.9176, 0.8275, 0.6078);

    glBegin(GL_POLYGON);
    glVertex2i(0, 56);
    glVertex2i(15, 48);
    glVertex2i(14, 25);
    glVertex2i(0, 21);
    glEnd();

    // Window 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(2, 30);
    glVertex2i(6, 30);
    glVertex2i(6, 35);
    glVertex2i(2, 35);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(2, 30);
    glVertex2i(5, 30);
    glVertex2i(5, 35);
    glVertex2i(2, 35);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(4, 30);
    glVertex2i(4, 35);
    glVertex2i(2, 33);
    glVertex2i(5, 33);
    glEnd();

    // Window 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(7, 32);
    glVertex2i(11, 32);
    glVertex2i(11, 37);
    glVertex2i(7, 37);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(7, 32);
    glVertex2i(10, 32);
    glVertex2i(10, 37);
    glVertex2i(7, 37);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(9, 32);
    glVertex2i(9, 37);
    glVertex2i(7, 35);
    glVertex2i(10, 35);
    glEnd();

    // Window 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(2, 40);
    glVertex2i(6, 40);
    glVertex2i(6, 45);
    glVertex2i(2, 45);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(2, 40);
    glVertex2i(5, 40);
    glVertex2i(5, 45);
    glVertex2i(2, 45);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(4, 40);
    glVertex2i(4, 45);
    glVertex2i(2, 43);
    glVertex2i(5, 43);
    glEnd();

    // Window 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(7, 42);
    glVertex2i(11, 42);
    glVertex2i(11, 47);
    glVertex2i(7, 47);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(7, 42);
    glVertex2i(10, 42);
    glVertex2i(10, 47);
    glVertex2i(7, 47);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(9, 42);
    glVertex2i(9, 47);
    glVertex2i(7, 45);
    glVertex2i(10, 45);
    glEnd();

    // FENCE
    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(11, 28);
    glVertex2i(11, 22);
    glVertex2i(13, 22);
    glVertex2i(13, 28);
    glVertex2i(12, 29);
    glEnd();

    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(14, 28);
    glVertex2i(14, 22);
    glVertex2i(16, 22);
    glVertex2i(16, 28);
    glVertex2i(15, 29);
    glEnd();

    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(17, 28);
    glVertex2i(17, 22);
    glVertex2i(19, 22);
    glVertex2i(19, 28);
    glVertex2i(18, 29);
    glEnd();

    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(20, 28);
    glVertex2i(20, 22);
    glVertex2i(22, 22);
    glVertex2i(22, 28);
    glVertex2i(21, 29);
    glEnd();

    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(23, 28);
    glVertex2i(23, 22);
    glVertex2i(25, 22);
    glVertex2i(25, 28);
    glVertex2i(24, 29);
    glEnd();

    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(26, 28);
    glVertex2i(26, 22);
    glVertex2i(28, 22);
    glVertex2i(28, 28);
    glVertex2i(27, 29);
    glEnd();

    glColor3f(0.7569, 0.7922, 0.7294);
    glBegin(GL_POLYGON);
    glVertex2i(29, 28);
    glVertex2i(29, 22);
    glVertex2i(31, 22);
    glVertex2i(31, 28);
    glVertex2i(30, 29);
    glEnd();

    // MAIN HOUSE
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(47, 24);
    glVertex2i(46, 22);
    glVertex2i(46, 21);
    glVertex2i(46, 20);
    glVertex2i(59, 20);
    glVertex2i(59, 21);
    glVertex2i(58, 24);
    glEnd();

    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_LINES);
    glVertex2i(47, 22);
    glVertex2i(58, 22);
    glVertex2i(47, 23);
    glVertex2i(58, 23);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2i(31, 24);
    glVertex2i(65, 24);
    glEnd();

    glColor3f(0.7137, 0.7843, 0.6784);
    glBegin(GL_POLYGON);
    glVertex2i(31, 24);
    glVertex2i(65, 24);
    glVertex2i(65, 37);
    glVertex2i(31, 37);
    glEnd();

    // Door
    glColor3f(0.30, 0.45, 0.55);
    glBegin(GL_POLYGON);
    glVertex2i(50, 24);
    glVertex2i(54, 24);
    glVertex2i(54, 33);
    glVertex2i(50, 33);
    glEnd();

    glColor3f(0.85, 0.85, 0.85);
    glBegin(GL_POLYGON);
    glVertex2i(50, 24);
    glVertex2i(50, 24);
    glVertex2i(50, 33);
    glVertex2i(50, 33);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(54, 24);
    glVertex2i(54, 24);
    glVertex2i(54, 33);
    glVertex2i(54, 33);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(50, 33);
    glVertex2i(54, 33);
    glVertex2i(54, 33);
    glVertex2i(50, 33);
    glEnd();

    // Door knob
    glColor3f(0.75, 0.65, 0.35);
    circle(0, 0, 53, 29);

    // Window 5
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(36, 27);
    glVertex2i(41, 27);
    glVertex2i(41, 33);
    glVertex2i(36, 33);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(37, 28);
    glVertex2i(40, 28);
    glVertex2i(40, 32);
    glVertex2i(37, 32);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(39, 28);
    glVertex2i(39, 32);
    glVertex2i(37, 30);
    glVertex2i(40, 30);
    glEnd();

    // Window 6
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(59, 27);
    glVertex2i(64, 27);
    glVertex2i(64, 33);
    glVertex2i(59, 33);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(60, 28);
    glVertex2i(63, 28);
    glVertex2i(63, 32);
    glVertex2i(60, 32);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(62, 28);
    glVertex2i(62, 32);
    glVertex2i(60, 30);
    glVertex2i(63, 30);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(30, 37);
    glVertex2i(66, 37);
    glVertex2i(66, 39);
    glVertex2i(30, 39);
    glEnd();

    glColor3f(0.3529, 0.3608, 0.3294);
    glBegin(GL_POLYGON);
    glVertex2i(30, 39);
    glVertex2i(66, 39);
    glVertex2i(62, 44);
    glVertex2i(35, 44);
    glEnd();

    glColor3f(0.7137, 0.7843, 0.6784);
    glBegin(GL_POLYGON);
    glVertex2i(35, 44);
    glVertex2i(62, 44);
    glVertex2i(62, 55);
    glVertex2i(35, 55);
    glEnd();

    // Window 7
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(39, 47);
    glVertex2i(44, 47);
    glVertex2i(44, 53);
    glVertex2i(39, 53);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(40, 48);
    glVertex2i(43, 48);
    glVertex2i(43, 52);
    glVertex2i(40, 52);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(42, 48);
    glVertex2i(42, 52);
    glVertex2i(40, 50);
    glVertex2i(43, 50);
    glEnd();

    // Window 8
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(53, 47);
    glVertex2i(58, 47);
    glVertex2i(58, 53);
    glVertex2i(53, 53);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(54, 48);
    glVertex2i(57, 48);
    glVertex2i(57, 52);
    glVertex2i(54, 52);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(56, 48);
    glVertex2i(56, 52);
    glVertex2i(54, 50);
    glVertex2i(57, 50);
    glEnd();

    glColor3f(0.7137, 0.7843, 0.6784);
    glBegin(GL_POLYGON);
    glVertex2i(35, 44);
    glVertex2i(35, 55);
    glVertex2i(32, 55);
    glVertex2i(32, 41);
    glEnd();

    glColor3f(0.7137, 0.7843, 0.6784);
    glBegin(GL_POLYGON);
    glVertex2i(62, 44);
    glVertex2i(62, 55);
    glVertex2i(65, 55);
    glVertex2i(65, 40);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(30, 55);
    glVertex2i(67, 55);
    glVertex2i(67, 56);
    glVertex2i(30, 56);
    glEnd();

    glColor3f(0.3529, 0.3608, 0.3294);
    glBegin(GL_POLYGON);
    glVertex2i(30, 56);
    glVertex2i(67, 56);
    glVertex2i(60, 67);
    glVertex2i(37, 67);
    glEnd();

    // Top room
    glColor3f(0.7137, 0.7843, 0.6784);
    glBegin(GL_POLYGON);
    glVertex2i(43, 60);
    glVertex2i(54, 60);
    glVertex2i(54, 72);
    glVertex2i(49, 76);
    glVertex2i(43, 72);
    glEnd();

    // Window 9
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(46, 63);
    glVertex2i(51, 63);
    glVertex2i(51, 68);
    glVertex2i(46, 68);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(47, 64);
    glVertex2i(50, 64);
    glVertex2i(50, 67);
    glVertex2i(47, 67);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(49, 64);
    glVertex2i(49, 67);
    glVertex2i(47, 66);
    glVertex2i(50, 66);
    glEnd();

    // Chimney
    glColor3f(0.20, 0.20, 0.24);
    glBegin(GL_POLYGON);
    glVertex2i(56, 58);
    glVertex2i(59, 58);
    glVertex2i(59, 74);
    glVertex2i(56, 74);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(60, 58);
    glVertex2i(62, 58);
    glVertex2i(62, 70);
    glVertex2i(60, 70);
    glEnd();

    // Antenna 1
    glColor3f(0.15, 0.15, 0.15);
    glLineWidth(1.2);
    glBegin(GL_LINES);
    glVertex2i(50, 76);
    glVertex2i(50, 83);
    glVertex2i(48, 80);
    glVertex2i(51, 80);
    glVertex2i(49, 82);
    glVertex2i(50, 82);
    glEnd();

    // Antenna 2
    glColor3f(0.15, 0.15, 0.15);
    glLineWidth(1.2);
    glBegin(GL_LINES);
    glVertex2i(61, 70);
    glVertex2i(61, 75);
    glVertex2i(60, 73);
    glVertex2i(62, 73);
    glVertex2i(60, 74);
    glVertex2i(62, 74);
    glEnd();

    // RIGHT ROAD
    glColor3f(0.4235, 0.4196, 0.3961);
    glBegin(GL_POLYGON);
    glVertex2i(85, 14);
    glVertex2i(65, 21);
    glVertex2i(65, 24);
    glVertex2i(75, 24);
    glVertex2i(100, 20);
    glVertex2i(100, 14);
    glEnd();

    // RIGHT FENCE
    glColor3f(0.7255, 0.7647, 0.7137);
    glBegin(GL_POLYGON);
    glVertex2i(75, 24);
    glVertex2i(100, 20);
    glVertex2i(100, 30);
    glVertex2i(75, 26);
    glEnd();



    // RIGHT-SIDE HOUSE
    glColor3f(0.5804, 0.4471, 0.4314);
    glBegin(GL_POLYGON);
    glVertex2i(95, 29);
    glVertex2i(75, 26);
    glVertex2i(75, 50);
    glVertex2i(95, 54);
    glEnd();

    glColor3f(0.9373, 0.8549, 0.6157);
    glBegin(GL_POLYGON);
    glVertex2i(95, 29);
    glVertex2i(95, 54);
    glVertex2i(100, 54);
    glVertex2i(100, 29);
    glEnd();

    // Window 10
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(78, 30);
    glVertex2i(81, 30);
    glVertex2i(81, 35);
    glVertex2i(78, 35);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(78, 30);
    glVertex2i(81, 30);
    glVertex2i(81, 35);
    glVertex2i(78, 35);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(80, 30);
    glVertex2i(80, 35);
    glVertex2i(78, 33);
    glVertex2i(81, 33);
    glEnd();

    // Window 11
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(78, 38);
    glVertex2i(81, 38);
    glVertex2i(81, 43);
    glVertex2i(78, 43);
    glEnd();

    glColor3f(0.55, 0.72, 0.80);
    glBegin(GL_POLYGON);
    glVertex2i(78, 38);
    glVertex2i(81, 38);
    glVertex2i(81, 43);
    glVertex2i(78, 43);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(80, 38);
    glVertex2i(80, 43);
    glVertex2i(78, 41);
    glVertex2i(81, 41);
    glEnd();

    float carPos = carX;
    float carY = 5.8f;

    //Shadow
    glColor4f(0.0, 0.0, 0.0, 0.25);
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 1, carY + 1);
    glVertex2i(carPos + 25, carY + 1);
    glVertex2i(carPos + 27, carY + 3);
    glVertex2i(carPos - 1, carY + 3);
    glEnd();

    //Main Car Body
    glColor3f(0.15, 0.45, 0.75);

    // Lower body
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 2, carY + 4);
    glVertex2i(carPos + 23, carY + 4);
    glVertex2i(carPos + 25, carY + 7);
    glVertex2i(carPos + 23, carY + 10);
    glVertex2i(carPos + 9, carY + 12);
    glVertex2i(carPos + 6, carY + 9);
    glVertex2i(carPos + 2, carY + 7);
    glEnd();

    //Pillar
    glColor3f(0.05, 0.05, 0.05);
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 6, carY + 9);
    glVertex2i(carPos + 9, carY + 12);
    glVertex2i(carPos + 10, carY + 11);
    glVertex2i(carPos + 7, carY + 9);
    glEnd();

    // B-Pillar
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 15, carY + 10);
    glVertex2i(carPos + 16, carY + 10);
    glVertex2i(carPos + 15, carY + 8);
    glVertex2i(carPos + 14, carY + 8);
    glEnd();

    // Front Windshield
    glColor3f(0.70, 0.85, 0.95);
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 6, carY + 9);
    glVertex2i(carPos + 9, carY + 12);
    glVertex2i(carPos + 10, carY + 11);
    glVertex2i(carPos + 7, carY + 9);
    glEnd();

    //Front Side Window
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 10, carY + 11);
    glVertex2i(carPos + 15, carY + 11);
    glVertex2i(carPos + 14, carY + 8);
    glVertex2i(carPos + 11, carY + 8);
    glEnd();

    //Rear Side Window
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 16, carY + 11);
    glVertex2i(carPos + 21, carY + 10);
    glVertex2i(carPos + 19, carY + 8);
    glVertex2i(carPos + 15, carY + 8);
    glEnd();

    //Rear Windshield
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 21, carY + 10);
    glVertex2i(carPos + 23, carY + 10);
    glVertex2i(carPos + 21, carY + 8);
    glVertex2i(carPos + 19, carY + 8);
    glEnd();

    //Bumpers
    glColor3f(0.15, 0.15, 0.15);
    // Front Bumper
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 1, carY + 4);
    glVertex2i(carPos + 3, carY + 4);
    glVertex2i(carPos + 3, carY + 5);
    glVertex2i(carPos + 1, carY + 5);
    glEnd();
    // Rear Bumper
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 23, carY + 4);
    glVertex2i(carPos + 25, carY + 4);
    glVertex2i(carPos + 25, carY + 5);
    glVertex2i(carPos + 23, carY + 5);
    glEnd();

    //Front Grille
    glColor3f(0.60, 0.60, 0.60);
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 2, carY + 6);
    glVertex2i(carPos + 3, carY + 6);
    glVertex2i(carPos + 3, carY + 6);
    glVertex2i(carPos + 2, carY + 6);
    glEnd();

    // --- Tail Lights ---
    glColor3f(0.85, 0.10, 0.10);
    glBegin(GL_POLYGON);
    glVertex2i(carPos + 23, carY + 6);
    glVertex2i(carPos + 25, carY + 6);
    glVertex2i(carPos + 25, carY + 7);
    glVertex2i(carPos + 23, carY + 7);
    glEnd();

    // Door Line
    glColor3f(0.10, 0.30, 0.50);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2i(carPos + 13, carY + 9);
    glVertex2i(carPos + 13, carY + 4);
    glEnd();

    // Front Tire
    glColor3f(0.05, 0.05, 0.05);
    circle(2, 2, carPos + 6, carY + 4);
    // Front Hubcap
    glColor3f(0.60, 0.60, 0.60);
    circle(1, 1, carPos + 6, carY + 4);

    // Rear Tire
    glColor3f(0.05, 0.05, 0.05);
    circle(2, 2, carPos + 19, carY + 4);
    // Rear Hubcap
    glColor3f(0.60, 0.60, 0.60);
    circle(1, 1, carPos + 19, carY + 4);

    // Pole
    glColor3f(0.45, 0.47, 0.50);
    glBegin(GL_POLYGON);
    glVertex2i(2, 14);
    glVertex2i(3, 14);
    glVertex2i(3, 48);
    glVertex2i(2, 48);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(3, 48);
    glVertex2i(6, 49);
    glVertex2i(6, 50);
    glVertex2i(3, 49);
    glEnd();

    // Lamp head
    glColor3f(0.30, 0.32, 0.34);
    circle(1, 1, 6, 49);
    glColor3f(0.95, 0.85, 0.55);
    circle(1, 1, 6, 48);

    // FIRE HYDRANT
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
     glVertex2i(2, 10);
    glVertex2i(4, 10);
    glVertex2i(4, 13);
     glVertex2i(2, 13);
    glEnd();
     circle(1, 1, 3, 13);

    glColor3f(0.60, 0.22, 0.15);
    glBegin(GL_POLYGON);
    glVertex2i(1, 14);
    glVertex2i(4, 14);
    glVertex2i(4, 14);
    glVertex2i(1, 14);
    glEnd();
    circle(1, 1, 3, 15);

   //  Side nozzles
    glColor3f(0.75, 0.30, 0.20);
    glBegin(GL_POLYGON);
    glVertex2i(1, 12);
   glVertex2i(2, 12);
   glVertex2i(2, 13);
   glVertex2i(1, 13);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(4, 12);
    glVertex2i(4, 12);
    glVertex2i(4, 13);
    glVertex2i(4, 13);
    glEnd();



    //==========

    // 1. Front sloping face
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(75, 50);
    glVertex2i(95, 56);
    glVertex2i(95, 53);
    glVertex2i(75, 47);
    glEnd();

    // 2. Right-side edge thickness
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(95, 56);
    glVertex2i(100, 56);
    glVertex2i(100, 53);
    glVertex2i(95, 53);
    glEnd();

    //========
    //roof
    glColor3f(0.298, 0.274, 0.329);
    glBegin(GL_POLYGON);
    glVertex2i(75, 50);
    glVertex2i(80, 60);
    glVertex2i(98, 65);
    glVertex2i(95, 56);
    glEnd();

    glColor3f(0.823, 0.776, 0.717);
    glBegin(GL_POLYGON);
    glVertex2i(98, 65);
    glVertex2i(100, 65);
    glVertex2i(100, 56);
    glVertex2i(95, 56);
    glEnd();

    //Bam pasher barir uporer sada dag
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(0, 56);
    glVertex2i(15, 48);
    glVertex2i(15, 50);
    glVertex2i(0, 58);
    glEnd();

    //Bam barir chad
    glColor3f(0.298, 0.274, 0.329);
    glBegin(GL_POLYGON);
    glVertex2i(15, 50);
    glVertex2i(0, 58);
    glVertex2i(0, 62);
    glVertex2i(10, 56);
    glEnd();

    //moddher barir uporer sada dag
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(42, 70);
    glVertex2i(49, 76);
    glVertex2i(49, 78);
    glVertex2i(42, 72);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(49, 76);
    glVertex2i(55, 70);
    glVertex2i(55, 72);
    glVertex2i(49, 78);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}

