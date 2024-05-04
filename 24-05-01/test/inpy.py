class A:
    value = 0
    
    def __init__(self, value: int):
        self.value = value
    
    def printit(self):
        print(f"A: ${self.value}")
        
class B (A):
    name = ""
    
    def __init__(self, value: int, name: str):
        super().__init__(value)
        self.name = name

    def printit(self):
        print(f"B: ${self.name}, ${self.value}")

    def getName(self) -> str:
        return self.name

def printA(a: A):
    a.printit()
    
b = B(23, "cool name")
b.printit()
printA(b)