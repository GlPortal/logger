#ifndef LOGGER_NULL_LOGGER_HPP
#define LOGGER_NULL_LOGGER_HPP

#include <string>

#include "Logger.hpp"

namespace logger {

  class NullLogger : public Logger {

  public:
    const char* getName() const;
    void log(const std::string &message, LogLevel lvl, const std::string &tag);
  };

} /* namespace logger */

#endif /* LOGGER_NULL_LOGGER_HPP */
