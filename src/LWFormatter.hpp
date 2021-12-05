// A subclass for the CLI::Formatter class. This class provides custom formatting for the help
// message.
class LWFormatter : public CLI::Formatter {
public:
    std::string make_description(const CLI::App*) const override
    {
        return "LWCountdown: C++ CLI countdown timer\n";
    }

    std::string make_usage(const CLI::App*, std::string name) const override
    {
        return "Usage: LWCountdown [OPTIONS]\n";
    }
};
