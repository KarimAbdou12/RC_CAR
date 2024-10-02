
#include "StdTypes.h"

u8 Interpolation_Calc (u16 _1st_point_x_axis ,u16 _1st_point_y_axis ,u16 _2nd_piont_x_axis ,u16 _2nd_point_y_axis ,u16 given_point_x_axis)
{
	u16 req_poin_y_axis=0;
	req_poin_y_axis=((u32)(_2nd_point_y_axis-_1st_point_y_axis)*(given_point_x_axis-_1st_point_y_axis))/(_2nd_piont_x_axis-_1st_point_x_axis)+_1st_point_y_axis;
	
	return req_poin_y_axis;
}
