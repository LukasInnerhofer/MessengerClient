#ifndef MAIN_H
#define MAIN_H

#include "restClient.h"

#include <curl/curl.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>

#define API_URL "10.8.0.2:9090/Messenger/webapi"

template<typename T>
bool vectorContains(const std::vector<T> vector, const T element);

#endif // MAIN_H
