
class Hesitate(int):
    def __mul__(self,other):
        return max(self,other)
    
    def __truediv__(self,other):
        return min(self,other)

import re

s = input()

s = re.sub(r"(\d+)",r"Hesitate(\1)",s)
s = s.replace("<?","/")
s = s.replace(">?","*")
print(eval(s))