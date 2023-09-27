#include "Lexer.h"

#define WHITE_SPACE_TK Token{ TokenType::WhiteSpace, "" }

namespace Lexer
{
	std::string tkTypeAsStr(TokenType tk)
	{
		switch (tk)
		{
			case Lexer::TokenType::NumericalValue:
				std::cout << "NumericalValue" << std::endl; break;
			case Lexer::TokenType::Identitifier:
				std::cout << "Identifier" << std::endl; break;
			case Lexer::TokenType::Operator:
				std::cout << "Operator" << std::endl; break;
			case Lexer::TokenType::WhiteSpace:
				std::cout << "WhiteSpace" << std::endl; break;
			case Lexer::TokenType::OpenBlockCharacter:
				std::cout << "OpenBlockCharacter" << std::endl; break;
			case Lexer::TokenType::ClosingBlockCharacter:
				std::cout << "ClosingBlockCharacter" << std::endl; break;
			case Lexer::TokenType::UnknownCharacter:
				std::cout << "UnknownCharacter" << std::endl; break;
			default:
				break;
		}
		return std::string();
	}

	Token newToken() {
		return Token{ TokenType::UnknownCharacter, ERROR_STR };
	}

	ResultErr checkStr(Token token)
	{
		if(token.tokenType != TokenType::UnknownCharacter) {
			if (token.tokenData != ERROR_STR) {
				return ResultErr::SUCCESS;
			}
		}
		return ResultErr::ERROR;
	}

	TokenType getTkType(char character)
	{
		switch (character)
		{
			case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
			case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
			case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
			case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
				return TokenType::Identitifier; break;

			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				return TokenType::NumericalValue; break;
			
			case '_': case '+': case '-': case '*': case '/': case '~': case '`': case '!': case '@': case '#': case '$': case '%': case '^': case '&': case '=':
			case '|': case '\\': case ':': case ';': case '"': case '\'': case '?': case '.': case ',': case '<': case '>':
				return TokenType::Operator; break;

			case '(': case '{':  case '[':
				return TokenType::OpenBlockCharacter; break;

			case ')': case '}': case ']':
				return TokenType::ClosingBlockCharacter; break;
	
			case ' ': case '\t': case '\n': case '\r':
				return TokenType::WhiteSpace; break;

			default:
				return TokenType::UnknownCharacter;
				break;
		}
	}

	std::vector<Token> getTokens(std::string input) 
	{
		Token currToken = WHITE_SPACE_TK;
		std::vector<Token> result;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (i == 0) { /* Start of input */
				currToken.tokenType = getTkType(input[i]); /* todo add check valid function here */
				currToken.tokenData.append((const char*)input[i]);
			}

			else 
			{
				if(currToken.tokenType == getTkType(input[i])) {
					currToken.tokenData.append((const char*) input[i]);
				} else if(getTkType(input[i]) == TokenType::WhiteSpace) { /* also later on function for removing whitespace */
					result.push_back(currToken);
					currToken = WHITE_SPACE_TK;
				} else {
					switch (currToken.tokenType) /* todo */ /* Given next != current */
					{
						case TokenType::NumericalValue:
							if (getTkType(input[i]) == TokenType::Identitifier) { /* Numerical Annotator */
								currToken.tokenData.append((const char*)input[i]);
								result.push_back(currToken);
								currToken = WHITE_SPACE_TK;
							} else {
								result.push_back(currToken);
								currToken = Token { getTkType(input[i]), (const char*)input[i] };
							}
							break;
						case TokenType::Identitifier:
							if (getTkType(input[i]) == TokenType::NumericalValue) {
								currToken.tokenData.append((const char*)input[i]);
							} else {
								result.push_back(currToken);
								currToken = Token{ getTkType(input[i]), (const char*)input[i] };
							}
							break;
						default:
							result.push_back(currToken);
							currToken = Token{ getTkType(input[i]), (const char*)input[i] };
							break;
					}
				}
			}
			return result;
		}
		
	}

	void printTokens(std::vector<Token> tokens)
	{
		for each (Token var in tokens)
		{
			std::cout << "[Token Type: " << tkTypeAsStr(var.tokenType) << "]" << " -> (Token str) " << var.tokenData << std::endl;
			std::cout << "---------------------------------------------------- \n" << std::endl;
		}
	}
}
