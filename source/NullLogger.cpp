#include <NullLogger.hpp>

#include <iostream>

namespace logger {

  const char* NullLogger::getName() const {
    return "null logger";
  }

  void NullLogger::log(const std::string &message, LogLevel lvl, const std::string &tag) {
  }

} /* namespace logger */
