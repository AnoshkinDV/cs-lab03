#include <iostream>
#include <vector>
#include "svg.h"
#include "histogram.h"
#include <curl/curl.h>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;
size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx) {

     auto data_size = item_size * item_count;
     stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
     buffer->write(reinterpret_cast<char*>(items), data_size);
      return data_size;

}

Input
download(const string& address)
{

    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if(curl)
    {
        CURLcode res;
        double connect;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        if(CURLE_OK == res)
        {
            res = curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &connect);
            if(CURLE_OK == res)
            {
                cerr <<"Connect: " << connect;
            }
        }
        curl_easy_cleanup(curl);

        if(res)
        {
            cout <<  curl_easy_strerror(res);
            exit(1);
        }
    }
        return read_input(buffer, false);
}



int main(int argc, char* argv[]) {

    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);
    }

   const auto bins = make_histogram(input);
   show_histogram_svg(bins);


    return 0;

}
