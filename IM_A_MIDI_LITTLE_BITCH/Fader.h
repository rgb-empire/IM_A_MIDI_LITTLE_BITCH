#pragma once

#include "Details.h"

template<typename T>
class Fader
{
protected:

public:
	bool fading;

	fract8 fraction;

	long start_time;
	long end_time;
	int duration;

	T old_value;
	T new_value;
	T cur_value;

	Fader(T initial_value);

	Fader<T> operator+ (Fader<T> const &a);
	Fader<T> operator= (Fader<T> const &a);

	T update();

	void fade(const T new_new_value, const int new_duration = Details::beat_duration(4));
};

template<typename T>
inline Fader<T>::Fader(T initial_value)
	:old_value(initial_value),
	cur_value(initial_value),
	new_value(initial_value)
{

}

template<typename T>
inline Fader<T> Fader<T>::operator+ (Fader<T> const &a)
{
	Fader<T> result = Fader<T>(cur_value + a.cur_value);
	return a.cur_value + b.cur_value;
}

template<typename T>
inline Fader<T> Fader<T>::operator=(Fader<T> const& a)
{
	return Fader<T>();
}

template<typename T>
inline T Fader<T>::update()
{
	if (fading)
	{
		fraction = (Details ::now - start_time) / duration;

		cur_value = old_value + (new_value - old_value) * fraction / 255;
	}

	return cur_value;
}

template<typename T>
inline void Fader<T>::fade(const T new_new_value, const int new_duration)
{
	new_value = new_new_value;
	old_value = current_value;

	duration = new_duration;

	start_time = Details::now;
	end_time = start_time + duration;

	fading = true;
}
