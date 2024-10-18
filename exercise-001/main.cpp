#include <fmt/chrono.h>
#include <fmt/format.h>
//system bibliotheken

#include "CLI/CLI.hpp"
#include "config.h"
//lokale includes 

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto counter = 20;
    CLI::App app{PROJECT_NAME};
    try
    {
      
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE)); 
        app.add_option("-C,--count", counter, "Counter is an integer option");

        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    fmt::print("Project name: {}!\n", PROJECT_NAME);
    fmt::print("Counter value: {}!\n", counter);

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Value of argc, {}!\n", argc);
    fmt::print("Value of argc[0], {}!\n", argv[0]);
    // fmt::print("Value of argc[3], {}!\n", argv[3]); //möglicher  Nullpointer Zugriff

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
