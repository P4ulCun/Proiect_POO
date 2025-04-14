#pragma once
#include <string>
#include <stdexcept>

class GameError : public std::runtime_error
{
public:
	GameError(const std::string message) : std::runtime_error(message) {};
};

// maybe path not found

class FontLoadError : public GameError
{
public:
	FontLoadError(const std::string message) : GameError(message) {};
};

class TextureLoadError : public GameError
{
public:
	TextureLoadError(const std::string message) : GameError(message) {};
};