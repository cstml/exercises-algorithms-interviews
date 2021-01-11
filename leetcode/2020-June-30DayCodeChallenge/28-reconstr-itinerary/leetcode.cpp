#include <iostream>
#include <string>
#include <vector>
#include <map>

#define log(A) std::cout<<A<<std::endl

class  Node {
    
    std::string m_name ;
    std::vector <std::string> n;
    Node (std::string name): m_name(name){}

};

class Solution
{
public:

    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) 
    {
    std::map <std::string, Node> map;
    for (std::vector<std::string> ticket : tickets)
    {
        std::pair<std::map<std::string,Node>::iterator, bool> it;
        it= map.insert(std::make_pair(ticket[0],Node(ticket[0])));
    }
}

};

int main()
{

	log("Hello World");

	return 1;
}
