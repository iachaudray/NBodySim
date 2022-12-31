//
// Created by Ibaad A. Chaudray on 11/21/22.
//

#pragma once
#include "1.10.0_1/spdlog/spdlog.h"
#include <memory>


class Log {

public:
    static void Init();

    static std::shared_ptr<spdlog::logger> getLogger();
private:

    static std::shared_ptr<spdlog::logger> s_Logger;
};




#define LOG_TRACE(...)      ::Log::getLogger()->trace(__VA_ARGS__)
#define LOG_WARN(...)       ::Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      ::Log::getLogger()->error(__VA_ARGS__)
#define LOG_INFO(...)       ::Log::getLogger()->info(__VA_ARGS__)
#define LOG_FATAL(...)      ::Log::getLogger()->fatal(__VA_ARGS__)

