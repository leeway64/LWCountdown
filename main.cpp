#include "CLI11.hpp"
#include "json.hpp"

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

    // Create/update a timer
    std::string c = "";
    app.add_option("-c", c, "Parameter");

    // View a timer
    std::string v = "";
    app.add_option("-v", v, "Parameter");

    // Delete a timer
    std::string d = "";
    app.add_option("-d", d, "Parameter");
    
    try {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e) {
        return app.exit(e);
    }

    if (c != "")
    {
        std::cout << "Name of timer: " << c << std::endl;
        std::cout << "End time: ";
    }

    if (v != "")
    {
        if (timers[v] == nullptr)
        {
            std::cout << "Timer not found" << std::endl;
        }
        else
        {
            std::cout << timers[v] << std::endl;
            std::cout << "    Time remaining: random time" << std::endl;
        }
    }

    if (d != "")
    {
        if (timers[d] == nullptr)
        {
            std::cout << "Timer not found" << std::endl;
        }
        else
        {            
            auto timer_name = timers[d];
            timers.erase(d);
            std::cout << "Timer " << timer_name << " has been deleted" << std::endl;
        }
    }

    std::ofstream output(timers_file_name);
    output << std::setw(4) << timers << std::endl;
    output.close();

    return 0;
}
