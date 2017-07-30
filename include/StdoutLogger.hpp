#ifndef LOGGER_STDOUT_LOGGER_HPP
#define LOGGER_STDOUT_LOGGER_HPP

#include <mutex>
#include <string>

#include <Logger.hpp>

namespace logger {

/** \class StdoutLogger
 * @brief Logger that outputs to an ANSI/vt-100 console
 */
class StdoutLogger : public Logger {
protected:
  std::mutex mtx;

public:
  const char* getName() const;
  void log(const std::string &message, LogLevel lvl, const std::string &tag);
};

} /* namespace logger */

#endif /* LOGGER_STDOUT_LOGGER_HPP */
