#pragma once
#if __cplusplus < 201103L && (!defined(_MSC_VER) || _MSC_VER < 1700)
#error Timer class requires C++11 support
#else
#include <chrono>
#include <ostream>
		class Timer {
			typedef std::chrono::high_resolution_clock high_resolution_clock;
			typedef std::chrono::milliseconds milliseconds;
			typedef std::chrono::seconds seconds;
		public:
			explicit Timer(bool run = false)
			{
				if (run)
					Reset();
			}
			void Reset()
			{
				_start = high_resolution_clock::now();
			}
			milliseconds ElapsedMilliseconds() const
			{
				return std::chrono::duration_cast<milliseconds>(high_resolution_clock::now() - _start);
			}
			seconds ElapsedSeconds() const
			{
				return std::chrono::duration_cast<seconds>(high_resolution_clock::now() - _start);
			}
			template <typename T, typename Traits>
			friend std::basic_ostream<T, Traits>& operator<<(std::basic_ostream<T, Traits>& out, const Timer& timer)
			{
				return out << timer.ElapsedMilliseconds().count();
			}
		private:
			high_resolution_clock::time_point _start;
		};
#endif