#ifndef LOGGER_LOGGER_FACTORY_HPP
#define LOGGER_LOGGER_FACTORY_HPP

#include "Logger.hpp"
#include "LogInput.hpp"

namespace logger {

class LoggerFactory {
private:
  Logger& logger;

public:
  LoggerFactory(Logger& logger);
  LogInput log(LogLevel level, const std::string tag);
};

} /* namespace logger */

#endif /* LOGGER_LOGGER_FACTORY_HPP */
