#ifndef MENGER_H
#define MENGER_H

#include <glm/glm.hpp>
#include <vector>

class Menger {
public:
	Menger();
	~Menger();
	void set_nesting_level(int);
	bool is_dirty() const;
	void set_clean();
	void generate_geometry(std::vector<glm::vec4>& obj_vertices,
			       std::vector<glm::vec4>& vtx_normals,
	                       std::vector<glm::uvec3>& obj_faces) const;
	void gHelper(std::vector<glm::vec4>& obj_vertices, double start, double unit, glm::vec3 startPoint) const;
private:
	int nesting_level_ = 0;
	bool dirty_ = false;
};

#endif
