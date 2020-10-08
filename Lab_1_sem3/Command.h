#pragma once
#include <string>

using std::string;
namespace ui {
	class Command {
	public:
		virtual void Execute(string args) = 0;
	};
}