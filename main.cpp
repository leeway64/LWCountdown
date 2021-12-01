#include "CLI11.hpp"
#include "json.hpp"

#include <iostream>


int main(int argc, char** argv) {
    std::ifstream input("list_of_timers.json");
    nlohmann::json timers;
    input >> timers;
    input.close();

    CLI::App app{ "LWCountdown" };

    // Create/update a countdown
    std::string c = "";
    app.add_option("-c", c, "Parameter");

    // View a countdown
    std::string v = "";
    app.add_option("-v", v, "Parameter");

    // Delete a countdown
    std::string d = "";
    app.add_option("-d", d, "Parameter");
    
    try {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e) {
        return app.exit(e);
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
            std::cout << "  Time remaining: random time" << std::endl;
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

    return 0;
}
