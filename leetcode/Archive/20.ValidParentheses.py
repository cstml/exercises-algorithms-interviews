class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for x in s:
            if x in "({[" :
                stack.append(x)
            elif not len(stack) == 0 :
                top = stack.pop()
                if top != "(" and x == ")":
                    return False
                elif top != "[" and x == "]":
                    return False
                elif top != "{" and x == "}":
                    return False
            else:
                return False
        if len(stack) == 0:
            return True
        return False
                    
                
                
        
