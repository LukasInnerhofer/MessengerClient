#ifndef REST_CLIENT_H
#define REST_CLIENT_H

#include <curl/curl.h>
#include <string>
#include <iostream>

namespace restClient
{
	namespace
	{
		extern std::string data;
		
		size_t writeCallback(const char * const buffer, const size_t size, const size_t nBytes, void *up);
	}
	std::string GET(const std::string &url);
	std::string POST(const std::string &url, const std::string &postData = "");
	std::string PUT(const std::string &url, const std::string &putData = "");
	std::string DELETE(const std::string &url, const std::string &deleteData = "");
}

#endif // REST_CLIENT_H
