#include <iostream>
#include <time_utils.hpp>

void test(
	const unsigned d,
	const unsigned h,
	const unsigned m,
	const unsigned s
	) {
	char buffer[64];
	const std::uint64_t sec = s + m * 60 + h * 60 * 60 + d * 60 * 60 * 24;
	const auto test_str = mtk::sec2fmt(sec);

	std::sprintf(buffer,
							 "%ud %02u:%02u:%02u",
							 d, h, m, s
							 );
	std::printf("[%s] <> [%s] (%s)\n",
							buffer,
							test_str.c_str(),
							(test_str == buffer ? "PASSED" : "FAILED"));
}

int main() {
	test(0, 0, 0, 0);
	test(0, 0, 0, 1);
	test(0, 0, 1, 1);
	test(0, 1, 1, 1);
	test(1, 1, 1, 1);
}
