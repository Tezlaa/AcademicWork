class Matrix:
    def __init__(self):
        self.size = (3, 3)
        self.data = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

    def load_from_file(self, filename):
        with open(filename, 'r') as file:
            for i in range(3):
                row = file.readline().strip().split()
                for j in range(3):
                    self.data[i][j] = int(row[j])

    def display(self):
        for row in self.data:
            print(' '.join(map(str, row)))

    def replace_element(self, row, col, value):
        self.data[row][col] = value

    def get_matrix_size(self):
        return self.size

    def get_element(self, row, col):
        return self.data[row][col]

    def calculate_determinant(self):
        a, b, c = self.data[0]
        d, e, f = self.data[1]
        g, h, i = self.data[2]
        return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g)

    def find_max_min_elements(self):
        elements = [element for row in self.data for element in row]
        max_element = max(elements)
        min_element = min(elements)
        return max_element, min_element

    def sum_diagonal_elements(self):
        diagonal = [self.data[i][i] for i in range(3)]
        return sum(diagonal)


if __name__ == "__main__":
    matrix = Matrix()
    matrix.load_from_file('matrix.txt')
    
    print("Matrix:")
    matrix.display()
    
    print("Matrix size:", matrix.get_matrix_size())
    
    row = 1
    col = 1
    value = 10
    matrix.replace_element(row, col, value)
    print(f"Replaced element at ({row}, {col}) with {value}:")
    matrix.display()
    
    determinant = matrix.calculate_determinant()
    print("Determinant:", determinant)
    
    max_element, min_element = matrix.find_max_min_elements()
    print("Max Element:", max_element)
    print("Min Element:", min_element)
    
    diagonal_sum = matrix.sum_diagonal_elements()
    print("Sum of Diagonal Elements:", diagonal_sum)