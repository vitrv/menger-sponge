#include "menger.h"

namespace {
	const int kMinLevel = 0;
	const int kMaxLevel = 4;
};

Menger::Menger()
{
	// Add additional initialization if you like
}

Menger::~Menger()
{
}

void
Menger::set_nesting_level(int level)
{
	nesting_level_ = level;
	dirty_ = true;
}

bool
Menger::is_dirty() const
{
	return dirty_;
}

void
Menger::set_clean()
{
	dirty_ = false;
}

// FIXME generate Menger sponge geometry
void
Menger::generate_geometry(std::vector<glm::vec4>& obj_vertices,
			  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces) const
{
	double unit=1.0f;
	double start = -0.5f;
	if(nesting_level_== 0){
		unit = 1.0f;
	}else{
		unit = (0.5)/(3*nesting_level_);
	}
	//scaling, useless atm
	double x = 0.5f;
	std::vector<glm::vec4> start_vertices;

	// Front
	// Starting point
	obj_vertices.push_back(glm::vec4((start), (start), (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start), x));
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start), x));

	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start), x));
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start), x));

	//Left
	obj_vertices.push_back(glm::vec4((start), (start), (start), x));
	//TopFrontLeft
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start), x));
	obj_vertices.push_back(glm::vec4((start), (start), (start)+unit, x));

	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start), x));
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start), (start), (start)+unit, x));

	//Top
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start), x));
	//TopBackRight
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start)+unit, x));

	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start), x));
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start)+unit, x));

	//Right 
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start)+unit, x));

	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start)+unit, x));

	//Bottom
	obj_vertices.push_back(glm::vec4((start), (start), (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start), x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start)+unit, x));

	obj_vertices.push_back(glm::vec4((start), (start), (start), x));
	obj_vertices.push_back(glm::vec4((start), (start), (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start)+unit, x));

	// Back
	obj_vertices.push_back(glm::vec4((start), (start), (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start), (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start)+unit, x));

	obj_vertices.push_back(glm::vec4((start), (start), (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start), (start)+unit, (start)+unit, x));
	obj_vertices.push_back(glm::vec4((start)+unit, (start)+unit, (start)+unit, x));

	glm::vec3 startPoint (0.15f,0.0f,0.0f);
	gHelper(obj_vertices,start,unit,startPoint);
	startPoint.y += 0.15f;
	gHelper(obj_vertices,start,unit,startPoint);
	startPoint.z += -0.15f;
	gHelper(obj_vertices,start,unit,startPoint);
	startPoint.x += 0.15f;
	gHelper(obj_vertices,start,unit,startPoint);
	startPoint.y += 0.15f;
	gHelper(obj_vertices,start,unit,startPoint);
	startPoint.z += -0.15f;
	gHelper(obj_vertices,start,unit,startPoint);


	int bigI = 36*7;

	for(int i =0 ; i<(bigI);i++){
		vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	}
	int counter =0;
	while(counter<(bigI)){
		obj_faces.push_back(glm::uvec3(counter++, counter++, counter++));
	}


}
void 
Menger::gHelper(std::vector<glm::vec4>& obj_vertices,double start,double unit,glm::vec3 startPoint) const{
	double x = 0.5f;
	double xx = startPoint.x;
	double y = startPoint.y;
	double z = startPoint.z;
	// Front
	// Starting point
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z), x));

	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z), x));

	//Left
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z), x));
	//TopFrontLeft
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z)+unit, x));

	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z)+unit, x));

	//Top
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z), x));
	//TopBackRight
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z)+unit, x));

	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z)+unit, x));

	//Right 
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z)+unit, x));

	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z)+unit, x));

	//Bottom
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z)+unit, x));

	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z), x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z)+unit, x));

	// Back
	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y), (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z)+unit, x));

	obj_vertices.push_back(glm::vec4((start+xx), (start+y), (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx), (start+y)+unit, (start+z)+unit, x));
	obj_vertices.push_back(glm::vec4((start+xx)+unit, (start+y)+unit, (start+z)+unit, x));

}

