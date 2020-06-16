
// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/
//
// Really enjoyed this
//
// And enjoyed creating the RegEX
//

class Solution {
public:
    string validIPAddress(string IP) {
    
        std::regex IPV4("(^[0-9]|^[1-9][0-9]|^1[0-9][0-9]|^2[0-5][0-5])\."
                       "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5])\.){2}"
                       "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5])");
        
        
        std::regex IPV6("(((((^[1-9]|^[a-f]|^[A-F])([0-9]|[a-f]|[A-F]){0,3})|(^0{4})|((^[0-9]|^[a-f]|^[A-F])([1-9]|[a-f]|[A-F]){0,1}([0-9]|[a-f]|[A-F]){0,2}))\:)(((([1-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F]){0,3})|(0{4})|(([0-9]|[a-f]|[A-F])([1-9]|[a-f]|[A-F]){0,1}([0-9]|[a-f]|[A-F]){0,2}))\:){0,6}(((([1-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F]){0,3})|(0{4})|(([0-9]|[a-f]|[A-F])([1-9]|[a-f]|[A-F]){0,1}([0-9]|[a-f]|[A-F]){0,2}))))");
                
        if (std::regex_match(IP,IPV4))
        {
            return "IPv4";
        }
        else
            if (std::regex_match(IP,IPV6))
                return "IPv6";
            
        return "Neither";
    }
};
