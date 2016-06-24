#ifndef EOM_SOLVER_H
#define EOM_SOLVER_H

class World;
class Object;
class Vector;

class EOMSolver {

public:
	static void resolve_time_step(World &world, unsigned int time_step);
	static void simulate_object(Object &object, unsigned int time_step);
	static Vector evaluate_object_EOM(Object &object);
};

#endif