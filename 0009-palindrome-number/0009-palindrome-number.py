class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: 
            return False
        add = 0
        ans = x
        while x > 0:
            rem = x % 10 # 1, 2, 1
            add = add*10 + rem # 1, 12, 121
            x = int (x/10) # 12, 1, 0
        if ans == add:
            return True
        return False


        


        