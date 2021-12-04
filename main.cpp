#include "CLI11.hpp"
#include "json.hpp"
#include "timer_helpers.hpp"

#include <regex>
#include <iostream>


int main(int argc, char** argv) {
    const std::string timers_file_name = "list_of_timers.json";

    const std::filesystem::path timers_file{ timers_file_name };
    if (!std::filesystem::exists(timers_file))
    {
        std::ofstream output(timers_file_name);
        output << "{\n}\n";
        output.close();
    }        

    std::ifstream input(timers_file_name);
    nlohmann::json timers;
    input >> timers;
    input.close();

    CLI::App app{ "LWCountdown" };

    std::string create = "";
    app.add_option("-c", create, "Create/update a timer");

    std::string view = "";
    app.add_option("-v", view, "View a timer");

    bool view_all{false};
    app.add_flag("-a", view_all, "View all timers");

    std::string delete_timer = "";
    app.add_option("-d", delete_timer, "Delete a timer");
    
    try {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e) {
        return app.exit(e);
    }


    if (create != "")
    {
        std::string end_time{};
        std::cout << "Name of timer: " << create << std::endl;
        std::cout << "    End date: ";
        std::cin >> end_time;
       
        const std::regex re("[\\d]{4}-[\\d]{2}-[\\d]{2}|[\\d]{4}-[\\d]{1}-[\\d]{1}");
        if (!std::regex_match(end_time, re))
        {
            std::cout << "\nIncorrect date format" << std::endl;
            std::cout << "Date must be in the form of YYYY-MM-DD or YYYY-M-D" << std::endl;
        }
        else {
            std::cout << "Timer \"" << create << "\" has been set" << std::endl;
            timers[create] = end_time;
            std::cout << "    Time remaining: " <<
            timer_helpers::get_time_remaining_in_timer(end_time) << " days" << std::endl;
        }
    }

    if (view != "")
    {
        const auto end_time = timers[view];
        if (end_time == nullptr)
        {
            std::cout << "Timer \"" << view << "\" not found" << std::endl;
            timers.erase(view);
        }
        else
        {
            std::cout << "Timer selected: " << view << std::endl;
            std::cout << "    Time remaining: " <<
                timer_helpers::get_time_remaining_in_timer(end_time) << " days" << std::endl;
        }
    }

    if (view_all)
    {
        std::cout << "All timers" << std::endl;
        timer_helpers::get_all_time_remaining(timers);
    }

    if (delete_timer != "")
    {
        std::cout << "Timer \"" << delete_timer << "\" ";
        if (timers[delete_timer] == nullptr)
        {
            std::cout << "not found" << std::endl;
        }
        else
        {            
            std::cout << "has been deleted" << std::endl;
        }
        timers.erase(delete_timer);
    }

    std::ofstream output(timers_file_name);
    output << std::setw(4) << timers << std::endl;
    output.close();

    return 0;
}
