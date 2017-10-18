#include "restClient.h"

namespace restClient
{
	namespace
	{
		std::string data = "";
		
		size_t writeCallback(const char * const buffer, const size_t size, const size_t nBytes, void *up)
		{
			for(unsigned int it = 0; it < size * nBytes; ++it)
			{
				data.push_back(buffer[it]);
			}
			return size * nBytes;
		}
	}
	
	std::string GET(const std::string &url, const std::string &getData)
	{
		data = "";
		CURL *curl = curl_easy_init();
		
		if(curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
			
			curl_easy_perform(curl);
		}
		curl_easy_cleanup(curl);
		
		return data;
	}
	
	std::string POST(const std::string &url, const std::string &postData)
	{
		data = "";
		CURL *curl = curl_easy_init();
		
		if(curl)
		{
			std::string text = (postData != "") ? "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>" + postData : "";
			
			struct curl_slist *slist = nullptr;

			slist = curl_slist_append(slist, "Accept: application/xml");
			slist = curl_slist_append(slist, "Content-Type: application/xml");
			slist = curl_slist_append(slist, ("Content-Length: " + std::to_string(text.size())).c_str());
			
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
			curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_POST, 1L);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, text.c_str());
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
			
			curl_easy_perform(curl);
			curl_slist_free_all(slist);
		}
		curl_easy_cleanup(curl);
		
		return data;
	}
	
	std::string PUT(const std::string &url, const std::string &putData)
	{
		data = "";
		CURL *curl = curl_easy_init();
		
		if(curl)
		{
			std::string text = (putData != "") ? "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>" + putData : "";
			
			struct curl_slist *slist = nullptr;
			
			slist = curl_slist_append(slist, "Accept: application/xml");
			slist = curl_slist_append(slist, "Content-Type: application/xml");
			slist = curl_slist_append(slist, ("Content-Length: " + std::to_string(text.size())).c_str());
			
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
			curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, text.c_str());
			
			curl_easy_perform(curl);
			curl_slist_free_all(slist);
		}
		curl_easy_cleanup(curl);
		
		return data;
	}
	
	std::string DELETE(const std::string &url, const std::string &deleteData)
	{
		data = "";
		CURL *curl = curl_easy_init();
		
		if(curl)
		{
			std::string text = (deleteData != "") ? "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>" + deleteData : "";
			
			struct curl_slist *slist = nullptr;
			
			slist = curl_slist_append(slist, "Accept: application/xml");
			slist = curl_slist_append(slist, "Content-Type: application/xml");
			slist = curl_slist_append(slist, ("Content-Length: " + std::to_string(text.size())).c_str());
			
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
			curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, text.c_str());
			
			curl_easy_perform(curl);
			curl_slist_free_all(slist);
		}
		curl_easy_cleanup(curl);
		
		return data;
	}
}
