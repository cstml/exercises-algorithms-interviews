class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        for i in tickets:
            print(i)
            if i[0] not in uList:
                uList.append(i[0])
            print (uList)

if __name__ == '__main__' :        
    List[List[str]]
    List = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    print (findItinerary(List))
