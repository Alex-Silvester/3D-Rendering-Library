#pragma once

#include <chrono>

template<typename Acc>
class Timer
{
public:

	Timer() = default;

	void Start();

	template<typename conversionType>
	long double End();

	template<typename conversionType>
	long double time();

	static const int den = Acc::period::den;

private:

	using time_p = std::chrono::steady_clock::time_point;

	time_p m_start_time;
	time_p m_end_time;

	long double total_time = 0.f;

	bool stopped = false;
};

template<typename Acc>
void Timer<Acc>::Start()
{
	stopped = false;
	m_start_time = std::chrono::high_resolution_clock::now();
}

template<typename Acc>
template<typename conversionType>
long double Timer<Acc>::End()
{
	if (stopped) return NAN;

	stopped = true;

	m_end_time = std::chrono::high_resolution_clock::now();

	total_time = conversionType::period::den * (long double)std::chrono::duration_cast<Acc>(m_end_time - m_start_time).count() / den;

	return total_time;
}

template<typename Acc>
template<typename conversionType>
inline long double Timer<Acc>::time()
{
	if (stopped) return total_time * conversionType::period::den;

	using namespace std::chrono;
	return conversionType::period::den * (long double)duration_cast<Acc>(high_resolution_clock::now() - m_start_time).count() / den;
}