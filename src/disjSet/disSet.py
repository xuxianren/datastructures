class DisjSet:
    def __init__(self, size):
        self.array = [-1] * size
    
    def find(self, x):
        root = x
        while self.array[root] >= 0:
            root = self.array[root]
        while x != root:
            self.array[x], x = root, self.array[x]
        return root
    
    def union(self, a, b):
        # if (a == b):
        #     return 
        if self.array[a] < self.array[b]:
            self.array[a] += self.array[b]
            self.array[b] = a
        else:
            self.array[b] += self.array[a] 
            self.array[a] = b
