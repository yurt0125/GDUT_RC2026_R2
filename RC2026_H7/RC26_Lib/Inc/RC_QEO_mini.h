#pragma once

#ifdef __cplusplus

#include "RC_dji_motor.h"
#include "RC_vector2d.h"
#include "RC_tim.h"

namespace fusion
{
	class QEOmini : public tim::TimHandler
    {
    public:
		QEOmini(motor::DjiMotor& m1_, motor::DjiMotor& m2_, tim::Tim& tim_);
		~QEOmini() = default;
		
		void Iteration()
		{
			y += (m1.Get_Pos() - m2.Get_Pos()) * QEO_POS_TO_M;//
			
			m1.Set_Pos_Zero();
			m2.Set_Pos_Zero();
		}
		
		constexpr float Y() const { return y; }
		
		constexpr void Set_Y(float y_) { y = y_; }
		
    protected:
		
		void Tim_It_Process() override 
		{
			Iteration();
		}
		
    private:
		motor::DjiMotor& m1;
		motor::DjiMotor& m2;
	
		static constexpr float QEO_POS_TO_M =  1.f / 36.f * 0.015 / 2.0f * 1.27f;// * 0.87f;
	
		float y;
    };
}
#endif
