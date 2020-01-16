#pragma once

#include "Global_Definitions.h"

extern Easing_Function easing_function_list[];

int polynomial(float percent_complete, int old_val, int new_val, int delta_val, int modifier, Ease_Type type);
int sine(float percent_complete, int old_val, int new_val, int delta_val, int modifier, Ease_Type type);
int elastic(float percent_complete, int old_val, int new_val, int delta_val, int modifier, Ease_Type type);
int bounce(float percent_complete, int old_val, int new_val, int delta_val, int modifier, Ease_Type type);
float bounceOut(float x);