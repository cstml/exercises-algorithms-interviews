class Solution(object):
    def twoCitySchedCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        n = len(costs)
        value = [0]*n
        for i in range(len(costs)):
            value[i] = costs[i][0]-costs[i][1]
                
        escape = False
        n = len(costs)
        totalCost = 0
        cL = 0
        cR = 0
        
        while (escape == False):
            minV = 0
            minPos = 0
            for i in range(len(value)):
                if abs(minV) <= abs(value[i]):
                    minV = value[i]
                    minPos = i
            
            if (minV < 0):
                totalCost += costs[minPos][0]
                cL += 1
                value.pop(minPos)
                costs.pop(minPos)
            else:
                totalCost += costs[minPos][1]
                cR += 1
                value.pop(minPos)
                costs.pop(minPos)
                
            if (cL == n/2) :
                while (len(costs)!=0):
                    totalCost += costs[0][1]
                    costs.pop(0)
                    escape = True
            elif (cR == n/2):
                 while (len(costs)!=0):
                    totalCost += costs[0][0]
                    costs.pop(0)
                    escape = True
            elif (cR+cL == n):
                escape = True
        return (totalCost)
                
            
