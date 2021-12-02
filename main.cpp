#include "CLI11.hpp"
#include "json.hpp"
#include "time_functions.hpp"

#include <iostream>


int main(int argc, char** argv) {
    std::string timers_file_name = "list_of_timers.json";
    std::filesystem::path timers_file{ timers_file_name };
    if (!std::filesystem::exists(timers_file))
    {
        std::ofstream output(timers_file_name);
        output.close();
    }        

    std::ifstream input(timers_file_name);
    nlohmann::json timers;
    input >> timers;
    input.close();

    CLI::App app{ "LWCountdown" };

    std::string c = "";
    app.add_option("-c", c, "Create/update a timer");

    std::string v = "";
    app.add_option("-v", v, "View a timer");

    bool view_all{false};
    app.add_flag("-a", view_all, "View all timers");

    std::string d = "";
    app.add_option("-d", d, "Delete a timer");
    
    try {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e) {
        return app.exit(e);
    }


    if (c != "")
    {
        std::string end_time{};
        std::cout << "Name of timer: " << c << std::endl;
        std::cout << "    End time: ";
        std::cin >> end_time;
        timers[c] = end_time;
        time_functions::get_timer();
    }

    if (v != "")
    {
        if (timers[v] == nullptr)
        {
            std::cout << "Timer not found" << std::endl;
        }
        else
        {
            std::cout << "Timer selected: " << v << std::endl;
            std::cout << "    Time remaining: current time - " << timers[v] << std::endl;
            time_functions::get_timer();
        }
    }

    if (view_all)
    {
        time_functions::get_all_timers();
        std::cout << "view all " << std::endl;
    }

    if (d != "")
    {
        if (timers[d] == nullptr)
        {
            std::cout << "Timer not found" << std::endl;
        }
        else
        {            
            std::cout << "Timer \"" << d << "\" has been deleted" << std::endl;
        }
        timers.erase(d);
    }

    std::ofstream output(timers_file_name);
    output << std::setw(4) << timers << std::endl;
    output.close();

    return 0;
}
