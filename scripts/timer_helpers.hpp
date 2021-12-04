#include <chrono>

namespace timer_helpers
{
	/* Get the time remaining in a given timer. The time remaining is calculated by subtracting the
	ending time by the current time.
	@param end_time_string is the ending time in the format of YYYY-MM-DD.
	@return The time remaining.
	*/
	int get_time_remaining_in_timer(const std::string& end_time_string)
	{
		const auto current_time = std::chrono::system_clock::now();
		const auto current_daypoint = floor<std::chrono::days>(current_time);
		const auto current_ymd = std::chrono::year_month_day{ current_daypoint };

		std::vector<int> input_vec{};

		const std::string delimiter = "-";
		int start = 0;
		int end = end_time_string.find(delimiter);
		while (end != -1) {
			const std::string token = end_time_string.substr(start, end - start);
			input_vec.push_back(std::stoi(token));
			start = end + delimiter.size();
			end = end_time_string.find(delimiter, start);
		}
		const std::string token = end_time_string.substr(start, end - start);
		input_vec.push_back(std::stoi(token));
		
		std::unordered_map<std::string, int> ending_date_map{};
		ending_date_map["year"] = input_vec[0];
		ending_date_map["month"] = input_vec[1];
		ending_date_map["day"] = input_vec[2];

		const std::chrono::year ending_year{ending_date_map["year"]};
		const auto end_daypoint = std::chrono::sys_days{ending_year / ending_date_map["month"] / ending_date_map["day"]};
		
		const auto time_remaining = end_daypoint - current_daypoint;
		auto z = time_remaining.count();
		return time_remaining.count();
	}

	/* Print the time remaining in a timer.
	@param end_time_string is the ending time in the format of YYYY-MM-DD.
	*/
	void print_time_remaining(std::string end_time_string)
	{
		std::cout << "    Time remaining: " <<
			timer_helpers::get_time_remaining_in_timer(end_time_string) << " days" << std::endl;
	}
}
