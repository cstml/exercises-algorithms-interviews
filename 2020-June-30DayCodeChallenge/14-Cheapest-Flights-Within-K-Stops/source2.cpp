#include <iostream>
#include <vector>
#include <unordered_map>

struct Flight
{
    Flight(int a, int b):city(a),cost(b){}
    int city;
    int cost;
};

struct Node
{
    std::vector <Flight> outbound;
    std::vector <Flight> inbound;
};

class Solution {
public:

    void InsertNode (std::unordered_map<int,Node*>& nodes, int where) 
    {
        std::pair<int,Node*> tempP;
        Node* tempN;
        tempN = new Node;
        tempP = std::make_pair(where,tempN);
        nodes.insert(tempP);
        return;
    }

    std::vector <int> FlightValueOut ( std::unordered_map<int,Node*> &nodes, int index ) 

    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) 
    {
        std::unordered_map <int,Node*> nodes;
        for (std::vector<int> tempV : flights)
        {
            int from = tempV[0];
            int to = tempV[1];
            int cost= tempV[3];

            if (nodes.find(from) == nodes.end())
                //if there is no from node
                InsertNode (nodes,from);

            if (nodes.find(to) == nodes.end())
                //if there is no to node
                InsertNode (nodes,to);

            nodes.at(from)->outbound.push_back(Flight (to,cost));
            nodes.at(to)->inbound.push_back(Flight(from,cost));
        }
        int temp = nodes.at(1)->outbound.at(0).cost;
        std::cout<<temp<<std::endl;

        return 1;

    }

};

int main ()
{
    Solution s;
    int n =3;
    std::vector<std::vector <int>> flight = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0;
    int dst = 2;
    int K =1 ;
    std::cout<<s.findCheapestPrice(n,flight,src,dst,K)<<std::endl;
    return 0;
}
