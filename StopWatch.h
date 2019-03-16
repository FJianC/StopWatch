#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#if defined(_MSC_VER) || defined(__MINGW32__) || defined(WIN32)
#include <Windows.h>
#else
#include <chrono>
#endif

class StopWatch
{
public:

	StopWatch();
	~StopWatch();

	//开启计时
	void Start();

	//暂停计时
	void Stop();

	//重新计时
	void ReStart();

	//微秒
	double Elapsed();

	//毫秒
	double ElapsedMS();

	//秒
	double ElapsedSecond();

private:
	long long elapsed_;
#if defined(_MSC_VER) || defined(__MINGW32__) || defined(WIN32)
	LARGE_INTEGER start_;
	LARGE_INTEGER stop_;
	LARGE_INTEGER frequency_;
#else
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::microseconds MicroSeconds;
	std::chrono::steady_clock::time_point start_;
	std::chrono::steady_clock::time_point stop_;
#endif
	
};

#endif // __STOPWATCH_H__




