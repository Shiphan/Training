import time

HEIGHT = 26
WIDTH = 58

aliveCellsIndex = [[0, 32], [1, 30], [1, 32], [2, 28], [2, 29], [2, 48], [2, 49], [3, 22], [3, 23], [3, 28], [3, 29], [3, 47], [3, 51], [4, 22], [4, 23], [4, 28], [4, 29], [4, 46], [4, 52], [5, 30], [5, 32], [5, 37], [5, 46], [5, 50], [5, 52], [5, 53], [5, 56], [5, 57], [6, 32], [6, 36], [6, 46], [6, 52], [6, 56], [6, 57], [7, 36], [7, 37], [7, 38], [7, 41], [7, 47], [7, 51], [8, 48], [8, 49]]

cells = [([0 for _ in range(WIDTH)]) for _ in range(HEIGHT)]

for aliveCellIndex in aliveCellsIndex:
    try:
        cells[aliveCellIndex[0]][aliveCellIndex[1]] = 1
    except:
        pass


def aliveNext(cells: list[list[int]], row: int, column: int):
    numAroundAliveCells = 0
    checking = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
    for idx in checking:
        try:
            if row+idx[0] >= 0 and column+idx[1] >= 0 and cells[row+idx[0]][column+idx[1]]:
                numAroundAliveCells += 1
        except:
            pass

    if cells[row][column]:
        if numAroundAliveCells > 1 and numAroundAliveCells < 4:
            return 1
        else:
            return 0
    else:
        if numAroundAliveCells == 3:
            return 1
        else:
            return 0

def newCells(cells: list[list[int]]):
    newCells = []
    for row, cellsRow in enumerate(cells):
        newCells.append([])
        for column, cell in enumerate(cellsRow):
            newCells[row].append(aliveNext(cells=cells, row=row, column=column))
    return newCells

def printCells(cells: list[bool]):
    outCells = ''
    for cellsRow in cells:
        for cell in cellsRow:
            outCells += '●' if cell else '  '
        outCells += '\n'
    print(outCells)

print('start with:')
printCells(cells=cells)
while True:
    time.sleep(0.5)
    print('', '×'*len(cells[0]), '', sep='\n')
    cells = newCells(cells=cells)
    printCells(cells=cells)