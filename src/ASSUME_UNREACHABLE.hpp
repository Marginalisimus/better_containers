#include <ciso646>

#ifdef _MSVC
	#define ASSUME_UNREACHABLE() __assume(0)
#elif defined(__clang__) || defined(__GNUC__)
	#define ASSUME_UNREACHABLE() __builtin_unreachable()
#else
	#define ASSUME_UNREACHABLE() ((void)0)
#endif