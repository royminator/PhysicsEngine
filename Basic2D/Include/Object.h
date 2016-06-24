#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

class Vector;

class Object {

private:

	std::vector<Vector> vertices;
	float x, y;
	float d_x, d_y;
	float theta, omega;

public:
	
	// --- Constructors ---
	Object();
	Object(std::vector<Vector> vertices);
	~Object();

	// --- Utility ---
	std::vector<Vector> get_vertices() const;
	void set_x(float x);
	void set_y(float y);
	std::vector<float> calculate_centroid() const;
	float calculate_signed_area() const;
	void update_centroid_position();
	Vector get_state() const;
	void set_state(const Vector &state);
};

#endif
