// ParsingProject.cpp : Defines the entry point for the application.
//
#include <fstream>
#include "ParsingProject.h"
#include "UnitTests.h"

#ifndef BUILD_MODE /* If program is not being optimized */
	#define DEBUG_MODE /* Enable debug features */
#else
	 /* Otherwise, in build mode */
#endif /* BUILD_MODE */

namespace LoggingSystem 
{
	std::string logLevelToStr(LogLevel level) 
	{
		switch (level)
		{
		case LogLevel::NONE:
			return "NONE"; break;
		case LogLevel::DEBUG:
			return "DEBUG";  break;
		case LogLevel::INFO:
			return "INFO"; break;
		case LogLevel::WARN:
			return "WARN"; break;
		case LogLevel::ERROR:
			return "ERROR"; break;
		default:
			return "UNKNOWN_LEVEL"; break;
		}
	}

	ResultErr Logger::writeToStream() /* TODO implement other streams */
	{
		// std::ofstream logFile;
		// logFile.open("LogFile.txt");
		std::map<ID, LogEntry>::iterator iter = this->logList.begin();

		while (iter != logList.end()) 
		{
			std::cout << "[ Entry: " << iter->first << " ]" << std::endl;
			std::cout << "{\n\t" << "CODE => " << logLevelToStr(iter->second.level) << std::endl;
			std::cout << "\t" << "TIME STAMP => " << std::asctime(std::localtime(&iter->second.timeStamp)) << std::endl;
			std::cout << "\t" << "MESSAGE => " << iter->second.message << std::endl;
			std::cout << "}" << std::endl;
			iter++;
		}
		return ResultErr::SUCCESS;
	}

	Logger::~Logger() {
		switch (this->output)
		{
		case OutputDest::FILE:

			break;
		default:
			break;
		}
	}
};


auto main() -> int
{
	std::cout << "[Intiallizing] ..." << std::endl;

	//std::cout << "[Welcome to MEEP shell] -> (Mathematical Expressions Evaluator Program)!" << std::endl;
	//std::cout << "[Type `:-[HELP]-:` for help]" << std::endl;

	//std::string input = "";

	//while (input != ":-[EXIT]-:") 
	//{
	//	std::cout << "[LINE: NULL]$ ";
	//	std::getline(std::cin, input);

	//	#ifdef DEBUG_MODE
	//			std::cout << "\t--> Echoing back input: { " << input << " }" << std::endl;
	//			ResultErr e = UnitTests::testSuite();
	//	#endif /* DEBUG_MODE */
	//}

	UnitTests::lexerAlpha();

	std::cout << "[Program Termination]!" << std::endl;
	return EXIT_SUCCESS;
}