#include "cl_application.h"
cl_application::cl_application(cl_base* p_head) : cl_base(p_head) {}

void cl_application::build_tree_objects() {
	std::string s_head_name, s_sub_name; // �������� - �������
	cl_base* p_head = nullptr; // ������� �������� ������. ������� ��� ����� ��������.
	cl_base* p_sub = this; // ������� ����������� ������
	int state, num_class;

	std::cin >> s_head_name;
	while (true)
	{
		std::cin >> s_head_name;
		if (s_head_name == "endtree")
			break;
		std::cin >> s_sub_name;
		p_head = p_sub->find_object_from_root(s_head_name);
		if (p_head) { //�������� �� ������, ����� ���������, ��� ��� �� ����� ��� � ��� ����������. � ������, ����� ���������, ��� ���� ������ ���������� (� ���� ��������)
			p_sub = new cl_base(p_head, s_sub_name);	
		}
	}
}