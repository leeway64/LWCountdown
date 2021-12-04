#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>
#include "timer_helpers.hpp"

#include <regex>
#include <iostream>


int main(int argc, char** argv) {
    const std::string timers_file_name = "list_of_timers.json";

    const std::filesystem::path timers_file{ timers_file_name };
    if (!std::filesystem::exists(timers_file))
    {
        std::ofstream output(timers_file_name);
        // Write brackets so that the file can be correctly read as a JSON file
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
            timer_helpers::print_time_remaining(end_time);
        }
    }

    if (view != "")
    {
        const auto end_time_string = timers[view];
        if (end_time_string == nullptr)
        {
            std::cout << "Timer \"" << view << "\" not found" << std::endl;
            timers.erase(view);
        }
        else
        {
            std::cout << "Timer selected: " << view << std::endl;
            timer_helpers::print_time_remaining(end_time_string);
        }
    }

    if (view_all)
    {
        std::cout << "Showing all timers\n" << std::endl;
        for (const auto& [name, end_time_string] : timers.items())
        {
            std::cout << name << std::endl;
            timer_helpers::print_time_remaining(end_time_string);
        }
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
    // Write the updated timers back to the JSON file
    output << std::setw(4) << timers << std::endl;
    output.close();

    return 0;
}
