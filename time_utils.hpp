#ifndef __TIME_UTILS_HPP__
#define __TIME_UTILS_HPP__
#include <iostream>
#include <iomanip>
#include <sstream>

namespace mtk {
inline std::string sec2fmt(
		std::uint64_t sec
		) {
	std::string str = "";

	// second
	{
		std::stringstream ss;
		const auto s = sec % 60;
		ss << std::setw(2) << std::setfill('0') << s;
		sec /= 60;
		str = ss.str();
	}

	// minute
	{
		std::stringstream ss;
		const auto m = sec % 60;
		ss << std::setw(2) << std::setfill('0') << m;
		sec /= 60;
		str = ss.str() + ":" + str;
	}

	// hour
	{
		std::stringstream ss;
		const auto h = sec % 24;
		ss << std::setw(2) << std::setfill('0') << h;
		sec /= 24;
		str = ss.str() + ":" + str;
	}

	// day
	{
		std::stringstream ss;
		const auto d = sec;
		ss << d;
		str = ss.str() + "d " + str;
	}

	return str;
}
} // namespace mtk
#endif
