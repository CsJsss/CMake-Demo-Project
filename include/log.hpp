#ifndef __INCLUDE_LOG_H_
#define __INCLUDE_LOG_H_

#include "spdlog/spdlog.h"

#define LOG_TRACE(...)                                                         \
  SPDLOG_LOGGER_TRACE(spdlog::default_logger_raw(), __VA_ARGS__);
#define LOG_DEBUG(...)                                                         \
  SPDLOG_LOGGER_DEBUG(spdlog::default_logger_raw(), __VA_ARGS__);
#define LOG_INFO(...)                                                          \
  SPDLOG_LOGGER_INFO(spdlog::default_logger_raw(), __VA_ARGS__);
#define LOG_WARN(...)                                                          \
  SPDLOG_LOGGER_WARN(spdlog::default_logger_raw(), __VA_ARGS__);
#define LOG_ERROR(...)                                                         \
  SPDLOG_LOGGER_ERROR(spdlog::default_logger_raw(), __VA_ARGS__);
#define LOG_CRITICAL(...)                                                      \
  SPDLOG_LOGGER_CRITICAL(spdlog::default_logger_raw(), __VA_ARGS__);

#endif /* __INCLUDE_LOG_H_ */
