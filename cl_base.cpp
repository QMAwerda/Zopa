#include "cl_base.h"
cl_base::cl_base(cl_base* _p_head_object, std::string _s_object_name)
{
	s_object_name = _s_object_name;
	p_head_object = _p_head_object;

	if (p_head_object != nullptr)
		p_head_object->subordinate_objects.push_back(this); // синтаксис
}
cl_base* cl_base::get_head_object() // геттер указателя на головной объект
{
	return p_head_object;
}

cl_base* cl_base::search_object(std::string s_name)
{
	if (this->s_object_name == s_name)
		return this;
	for (auto p_sub_object : subordinate_objects)
	{
		cl_base* p_found = p_sub_object->search_object(s_name);
		if (p_found != nullptr)
			return p_found;
	}
	return nullptr;
}

cl_base* cl_base::find_object_from_root(std::string s_name) { // метод поиска от корня дерева
	//cl_base* tmp = this;
	cl_base* tmp(this);
	while (tmp->p_head_object) {
		//tmp = tmp->get_head_object();// происходит явная аномалия при использовании указателя на головной напрямую. tmp = p_head_object
		tmp = p_head_object;
	}
	std::cout << "end\n";
	return tmp->search_object(s_name);
}