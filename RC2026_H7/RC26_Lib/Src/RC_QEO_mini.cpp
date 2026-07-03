#include "RC_QEO_mini.h"

namespace fusion
{
	QEOmini::QEOmini(motor::DjiMotor& m1_, motor::DjiMotor& m2_, tim::Tim& tim_)
	: m1(m1_), m2(m2_), tim::TimHandler(&tim_)
	{
		
	}
}