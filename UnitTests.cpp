#include "UnitTests.h"

namespace UnitTests
{
	ResultErr loggingSystem()
	{
		LoggingSystem::Logger logger = LoggingSystem::Logger();
		logger.newEntry(LoggingSystem::LogEntry{ std::time(nullptr), LoggingSystem::LogLevel::NONE, "Testing1" });
		ResultErr err = logger.writeToStream();
		return err;
	}

	ResultErr lexerAlpha()
	{
		std::ifstream file ("C:\\Users\\PLACEHOLDER.TXT");
		std::string strInput = "";
		file >> strInput;
		auto tkList = Lexer::getTokens(strInput);
		Lexer::printTokens(tkList);
		return ResultErr::SUCCESS;
	}

	ResultErr testSuite() /* Todo add descriptive test fail cases */
	{
		std::vector<ResultErr> results;
		results.push_back(loggingSystem());

		for (int i = 0; i < results.size(); i++)
		{
			if(results[i] == ResultErr::ERROR) {
				return ResultErr::ERROR;
			}
		}

		return ResultErr::SUCCESS;
	}
};
