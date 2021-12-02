#include <chrono>

namespace time_functions
{
	void get_time_remaining_in_timer(std::string end_time)
	{
		const auto current_time = std::chrono::system_clock::now();
		const auto daypoint = floor<std::chrono::days>(current_time);
		const auto ymd = std::chrono::year_month_day{ daypoint };

		std::vector<std::string> temp{};

		std::string delimiter = "-";
		int start = 0;
		int end = end_time.find(delimiter);
		while (end != -1) {
			std::string token = end_time.substr(start, end - start);
			temp.push_back(token);
			std::cout << token << std::endl;
			start = end + delimiter.size();
			end = end_time.find(delimiter, start);
		}
		temp.push_back(end_time.substr(start, end - start));
		std::cout << end_time.substr(start, end - start) << std::endl;
	}

	void get_all_time_remaining()
	{
	}
}
