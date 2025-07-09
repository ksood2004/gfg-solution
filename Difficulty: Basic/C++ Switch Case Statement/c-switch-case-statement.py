class Solution:
    def isInRange(self, N):
        return (
            ['zero', 'one', 'two', 'three', 'four', 'five', 
             'six', 'seven', 'eight', 'nine', 'ten'][N]
            if 0 <= N <= 10 else 'not in range'
        )
