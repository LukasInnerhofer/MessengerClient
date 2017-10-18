#ifndef MAIN_H
#define MAIN_H

#include "restClient.h"

#include <curl/curl.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <functional>

template<typename T>
void validateRequestedMethod(const std::vector<T> &availableMethods, const T &requestedMethod);

template<typename T>
bool vectorContains(const std::vector<T> &vector, const T &element);

#endif // MAIN_H
