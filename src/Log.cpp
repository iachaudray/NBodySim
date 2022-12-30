//
// Created by Ibaad A. Chaudray on 11/21/22.
//

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::s_Logger = 0;
void Log::Init() {
    spdlog::set_pattern("%^%@[%T %o] %n: %v%$");
    s_Logger = spdlog::stdout_color_mt("BODYSIM");
    s_Logger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> Log::getLogger() {
    return s_Logger;
}
