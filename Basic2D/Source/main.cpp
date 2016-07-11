#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>

#include "Matrix.h"
#include "Vector.h"
#include "Constants.h"
#include "Display.h"
#include "Object.h"
#include "World.h"
#include "EOMSolver.h"
#include "Scene.h"
#include "CollisionTest.h"
#include "object_generation.h"

using namespace std;

World *world;

clock_t clocks_0 = 0;
clock_t clocks_1;
unsigned int delta_time_ms = 10;
double delta_time = delta_time_ms/1000.0;
float elapsed_ms;
int count = 0;
int y_min = -50;

void run() {

	clocks_1 = clock();
	elapsed_ms = float(clocks_1 - clocks_0) / (CLOCKS_PER_SEC/1000);

	if(elapsed_ms >= delta_time_ms) {
		clocks_0 = clocks_1;

		Vector contact_point = CollisionTest::collision_detection_SAT(world->get_objects().at(0), world->get_objects().at(1));
		
		for(unsigned int object_index = 0; object_index < world->get_objects().size(); object_index++) {
			Object *object = world->get_objects().at(object_index);

			EOMSolver::simulate_object(object, delta_time);
		}

		Scene::render_world(world);
	}
}

int main(int argc, char** argv) {

	vector<Object*> objects = generate_objects();

	objects.at(0)->set_position(Vector(0, 0));
	objects.at(0)->set_velocity(Vector(0, 0));

	for(unsigned int i = 0; i < objects.at(0)->get_normals().size(); i++) {
		printf("normal: \n");
		Display::vector(objects.at(0)->get_normals().at(i), WHITE);

		printf("norm: %f\n", objects.at(0)->get_normals().at(i).norm());
	}

	world = new World(objects);

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Physics Engine");
    glutDisplayFunc(run);
    glutIdleFunc(run);
    glutMainLoop();
 	
 	delete world;

	return 0;
}