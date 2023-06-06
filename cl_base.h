#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <iostream>
#include <string>
#include <vector>
class cl_base {
private:
	std::string s_object_name; // имя объекта
	cl_base* p_head_object = nullptr; // указатель на головной объект
	std::vector <cl_base*> subordinate_objects; // указатели на подчиненные объекты

public:
	cl_base(cl_base* _p_head_object, std::string _s_object_name = "root");
	
	cl_base* get_head_object(); // геттер указателя на головной объект

	cl_base* search_object(std::string s_name);

	cl_base* find_object_from_root(std::string s_name);
};
#endif