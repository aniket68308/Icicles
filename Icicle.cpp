#include<utility>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include "Constants.cpp"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Icicle {

	public:

	std::pair<float,float> position;
    std::pair<float,float> velocity;
    int segment;
    float angle;

    Icicle(float x,float y) {
        position.first = x;
        position.second = y;
        segment = 1000;
        velocity = std::make_pair(0.0f,0.0f);
    }

    void intit(std::pair<float,float> pos){
        time_t t;
        srand(time(&t));
        position.first = pos.first;
        position.second = pos.second;
        velocity = std::make_pair(0.0f,0.0f);
    }

	void update() {
        velocity.second += Constants::ICICLES_ACCELERATION * 0.166;
        position.second += velocity.second * 0.166;
    }

    void render() {

        glColor3f(static_cast <float> (rand()) / static_cast <float> (RAND_MAX),static_cast <float> (rand()) / static_cast <float> (RAND_MAX)
                  ,static_cast <float> (rand()) / static_cast <float> (RAND_MAX));

        glBegin(GL_POLYGON);
            glVertex2f(position.first, position.second);
            glVertex2f(position.first - Constants::ICICLES_WIDTH / 2, position.second + Constants::ICICLES_HEIGHT);
            glVertex2f(position.first + Constants::ICICLES_WIDTH / 2, position.second + Constants::ICICLES_HEIGHT);
        glEnd();

    }
};

