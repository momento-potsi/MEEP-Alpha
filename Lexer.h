#pragma once
#include "../ParsingProject.h"
#include <vector>
#include <fstream>

namespace Lexer
{
	enum class TokenType
	{
		NumericalValue,
		Identitifier,
		Operator,
		WhiteSpace,
		OpenBlockCharacter,
		ClosingBlockCharacter,
		UnknownCharacter
	}; /* Add keyword, string as grammer enum */

	std::string tkTypeAsStr(TokenType tk);

	struct Token {
		TokenType tokenType;
		std::string tokenData;
	};

	Token newToken();

	ResultErr checkStr(Token token);

	TokenType getTkType(char character);

	std::vector<Token> getTokens(std::string input);

	void printTokens(std::vector<Token> tokens);
}
