#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"
class cl_application : public cl_base
{
public:
	cl_application(cl_base* p_head);
	void build_tree_objects();
};
#endif