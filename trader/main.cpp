//
// An algorithmic trading application built to work with the
// Alpaca Markets brokerage API.
// 
// Main method -> no logic, just startup and log any errors
// 

#include "trading/Trader.hpp"
#include "tools/FileWritingUtilities.hpp"
#include "tools/PreprocessorOptions.hpp"

#include <fstream>
#include <iostream>

int main() 
{
    try 
    {
    	trading::Trader app;
    	app.run();
    } catch (const std::exception& e)
    {
    	// log any errors thrown up to main
    	tools::log(e.what());
    	std::cout << "Logging: " << e.what() << std::endl;
    }

    return 0;
}
