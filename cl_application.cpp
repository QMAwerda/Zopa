#include "cl_application.h"
cl_application::cl_application(cl_base* p_head) : cl_base(p_head) {}

void cl_application::build_tree_objects() {
	std::string s_head_name, s_sub_name; // родитель - ребенок
	cl_base* p_head = nullptr; // Текущий корневой объект. Сначала тут будет головной.
	cl_base* p_sub = this; // будущий подчиненный объект
	int state, num_class;

	std::cin >> s_head_name;
	while (true)
	{
		std::cin >> s_head_name;
		if (s_head_name == "endtree")
			break;
		std::cin >> s_sub_name;
		p_head = p_sub->find_object_from_root(s_head_name);
		if (p_head) { //проверка во втором, чтобы убедиться, что сын не будет как и дед называться. В первом, чтобы убедиться, что отец вообще существует (к чему привяжем)
			p_sub = new cl_base(p_head, s_sub_name);	
		}
	}
}