#ifndef Visitor
#define Visitor

class cell;

class visitor
{
public:
	visitor();
	void visit_column(cell * input);
	void visit_row(cell * input);
	void visit_square(cell * input);
};

#endif
