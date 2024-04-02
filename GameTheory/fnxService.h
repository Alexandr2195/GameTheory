#pragma once
#include <iostream>
#include <cassert>
#include <array>
#include <chrono>
#include <cstdlib>

inline __int64 GetTimeNow(void)
{
	std::chrono::steady_clock::time_point Now(std::chrono::steady_clock::now());
	auto	Ms(std::chrono::time_point_cast<std::chrono::milliseconds>(Now));

	return	Ms.time_since_epoch().count();
}

template <typename T>
inline T RangeRand(T _min, T _max)
{
	T tmp(_max - _min);
	if (tmp != static_cast<T>(0))
		return _min + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX) / (tmp));
	else
		return static_cast<T>(0);
}

inline void fnxMessageEx()
{
	std::cout << std::endl;
}

template <typename T>
inline void fnxMessageEx(const T& t) 
{
	std::cout << t << std::endl;
}

template <typename First, typename... Rest>
inline void fnxMessageEx(const First& first, const Rest&... rest) 
{
	std::cout << first << " ";
	fnxMessageEx(rest...);
}

#define fnxMessageOut	fnxMessageEx

#ifdef _DEBUG
#define FNX_ASSERT assert
#define fnxMessage		fnxMessageEx
#else
#define fnxMessage
#define FNX_ASSERT
#endif	

#define FNX_CLASS_SETTING( CLASS, COPY_CONSTR, MOVE_CONSTR, OPER_COPY, OPER_MOVE )\
	public:\
		CLASS(const CLASS&) COPY_CONSTR;\
		CLASS(CLASS&&) MOVE_CONSTR;\
		CLASS& operator=(const CLASS&) OPER_COPY;\
		CLASS& operator=(CLASS&&) OPER_MOVE;

#define FNX_CLASS_DEFAULT( CLASS )\
	FNX_CLASS_SETTING(CLASS, =default,=default,=default,=default)

#define FNX_CLASS_DELETE( CLASS )\
	FNX_CLASS_SETTING(CLASS, =delete,=delete,=delete,=delete)