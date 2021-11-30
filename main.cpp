#include "CLI11.hpp"
#include <iostream>


int main(int argc, char** argv) {
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

    std::cout << "Parameter value: " << c << std::endl;
    std::cout << "Parameter value: " << v << std::endl;
    std::cout << "Parameter value: " << d << std::endl;

    return 0;
}
