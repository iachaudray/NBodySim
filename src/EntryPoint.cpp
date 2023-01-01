//
// Created by Ibaad A. Chaudray on 11/20/22.
//


#include "Core.h"
#include "Log.h"
#include "Application.h"
int main(int argc, char** argv) {
    Log::Init();
    auto app = new Application();
    app->run();
    return 0;
}