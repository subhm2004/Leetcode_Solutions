class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        forces = [0] * n
        
        # 'R' ka effect (Left to Right loop)
        force = 0
        for i in range(n):
            if dominoes[i] == 'R':
                force = n  # Full rightward force start
            elif dominoes[i] == 'L':
                force = 0  # Left block kar deta hai, force khatam
            else:
                force = max(force - 1, 0)  # R se door jaane par force kam hota hai
            forces[i] += force
        
        # 'L' ka effect (Right to Left loop)
        force = 0
        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'L':
                force = n  # Full leftward force start
            elif dominoes[i] == 'R':
                force = 0  # R block karta hai left force ko
            else:
                force = max(force - 1, 0)  # L se door jaane pe force kam
            forces[i] -= force  # L ka force negative hota hai
        
        # Final ans Banao
        ans = []
        for force_value in forces:
            if force_value > 0:
                ans.append('R')
            elif force_value < 0:
                ans.append('L')
            else:
                ans.append('.')
        
        return ''.join(ans)
