#include <iostream>
#include <regex>

int main() {
    std::string s("http://www.msn.com/da-dk/img-resizer/tenant/amp/entityid/AAv396x.img");
    std::regex r("^http(s)?:\\/\\/([a-zA-Z0-9-]+.)+google(.[a-zA-Z0-9-]+)+\\/complete\\/search");
    if (std::regex_match(s, r))
        std::cout << "match" << std::endl;
    else
        std::cout << "no match" << std::endl;

    return 0;
}
