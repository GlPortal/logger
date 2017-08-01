#include <LoggerFactory.hpp>

namespace logger {

  LoggerFactory::LoggerFactory(Logger& logger):logger(logger) {

  }

  LogInput LoggerFactory::log(LogLevel level, const std::string tag){
    return LogInput(logger, level, tag);
  }

} /* namespace logger */
