#pragma once

#include <iostream>
#include <string>
#include <map>
#include <chrono>

#define ERROR_STR ":-[INPUT FAILURE]-:"

enum class ResultErr { SUCCESS, ERROR };

namespace LoggingSystem 
{
	typedef unsigned int ID;

	enum class LogLevel { NONE, DEBUG, INFO, WARN, ERROR };
	enum class OutputDest { CONSOLE, FILE, NONE };

	struct LogEntry 
	{
		std::time_t timeStamp = 0;
		LogLevel	level     = LogLevel::NONE;
		std::string message   = "";
	};

	class Logger
	{
	public:
		unsigned int	   count = 0;
		std::map<ID, LogEntry> logList;

	public:

		ResultErr writeToStream();
	public:
		OutputDest output = OutputDest::NONE;

		LogEntry getLog(ID num)			{ return logList.at(num); }
		void	 newEntry(LogEntry log) { logList[++count] = log; }

		Logger() {  }
		~Logger();

	};
}

namespace ParsingModule
{


}