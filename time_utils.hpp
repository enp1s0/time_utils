#ifndef __TIME_UTILS_HPP__
#define __TIME_UTILS_HPP__
#include <iostream>
#include <iomanip>
#include <sstream>

namespace mtk {
inline std::string sec2fmt(
		std::uint64_t sec,
		const bool trunc = false
		) {
	char buffer[64];

	if ((!trunc) || (sec / (24 * 60 * 60))) {
		std::sprintf(buffer, "%lud %02lu:%02lu:%02lu",
				(sec / (24 * 60 * 60)),
				(sec / (60 * 60)) % 24,
				(sec / 60) % 60,
				sec % 60
				);
	} else {
		std::sprintf(buffer, "%02lu:%02lu:%02lu",
				(sec / (60 * 60)) % 24,
				(sec / 60) % 60,
				sec % 60
				);
	}

	return std::string(buffer);
}

inline std::string timestamp2fmt(
		std::time_t timestamp = std::time(nullptr)
		) {
	char buffer[64];
	std::strftime(buffer, sizeof(buffer), "%A %c", std::localtime(&timestamp));

	return std::string(buffer);
}
} // namespace mtk
#endif
