#include <chrono>

namespace time_functions
{
	void get_time_remaining_in_timer(std::string end_time_string)
	{
		const auto current_time = std::chrono::system_clock::now();
		const auto current_daypoint = floor<std::chrono::days>(current_time);
		const auto current_ymd = std::chrono::year_month_day{ current_daypoint };

		std::vector<int> temp{};

		std::string delimiter = "-";
		int start = 0;
		int end = end_time_string.find(delimiter);
		while (end != -1) {
			std::string token = end_time_string.substr(start, end - start);
			temp.push_back(std::stoi(token));
			start = end + delimiter.size();
			end = end_time_string.find(delimiter, start);
		}
		std::string token = end_time_string.substr(start, end - start);
		temp.push_back(std::stoi(token));
		
		std::unordered_map<std::string, int> ending_date_map{};
		ending_date_map["year"] = temp[0];
		ending_date_map["month"] = temp[1];
		ending_date_map["day"] = temp[2];

		std::chrono::year ending_year{ending_date_map["year"]};
		auto end_daypoint = std::chrono::sys_days{ending_year / ending_date_map["mongth"] / ending_date_map["day"]};
		
		auto time_remaining = end_daypoint - current_daypoint;
		std::cout << time_remaining.count() << std::endl;
	}

	void get_all_time_remaining()
	{
	}
}
