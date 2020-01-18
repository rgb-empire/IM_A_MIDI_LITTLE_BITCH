#include "Bug.h"

std::vector<name_and_time> Bug::function_stack;
std::vector<int> Bug::thing_stack;
//int Bug::framesPerSecond = 0;
float speed_scale_factor = 1;
float speed_scale_factor_modifier = 1;

Bug::Bug()
{
}