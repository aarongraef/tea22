#include <fmt/chrono.h>         //fmt bib
#include <fmt/format.h>         

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int         //funktion (leere parameterliste) ->Rückgabewert
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};         // initialisiere cli objekt, dem ich einen Projektnamen geben
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));        // hier projekt version und build datum einfügen
        app.parse(argc, argv);          // returncode, bei false gibts Fehlerbehandlung
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());         //python ähnlich

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/          //return code
}
