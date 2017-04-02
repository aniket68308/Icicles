#include<vector>
#include "Icicle.cpp"
#include<cstdlib>
#include<ctime>
#include<random>
#include<stdio.h>


class Icicles {


	public:
    int iciclesDodged;
    std::vector<Icicle> icicleList;
    char str[100];

	Icicles() {
        iciclesDodged = 0;
    }

    void init(int newGame){
        if(newGame == 0){
            iciclesDodged = 0;
        }

        icicleList.clear();
    }

    void update() {

        if(icicleList.size() < Constants::ARRAY_CAPACITY ){

            icicleList.push_back(Icicle(rand()%Constants::WORLD_WIDTH,Constants::WORLD_HEIGHT));
        }

        for (int i = 0; i < int(icicleList.size()); i++) {
            icicleList[i].update();
        }

        for (int i = 0; i < int(icicleList.size()); i++) {
            if (icicleList[i].position.second < -1*Constants::ICICLES_HEIGHT) {
                iciclesDodged += 1;
                icicleList.erase(icicleList.begin()+i);
            }
        }

    }

    void drawText(int score){
        char str[20];

        glColor3f(1,1,0);
        glPushMatrix();
        sprintf(str,"S c o r e : %d",score);
        glTranslatef(40,Constants::WORLD_HEIGHT-40,0);
        glScalef(.1,.2,.1);
        for(int i=0;str[i]!='\0';i++)
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
        glPopMatrix();

    }

	void render() {


        for (Icicle icicle : icicleList) {
            icicle.render();
        }
        drawText(iciclesDodged);

    }

};

