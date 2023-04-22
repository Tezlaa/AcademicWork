if __name__ == "__main__":
    """
    args:
        matrix_size(int): size of the matrix, matrix = matrix_size * matrix_size
        matrix( List[List[int]] ): matrix_size * matrix_size
        
        row/col(int, int): rows and columns to fill the matrix
        add_row/col(int, int): args to select direction to fill the matrix
        
        next_row/col(int): calculate next row index and next columns index
    """
    
    matix_size = int(input('Write the size of the table: '))

    # to fill matrix_size * matrix_size
    matrix = [[0 for _ in range(matix_size)] for _ in range(matix_size)]

    row, col = 0, 0
    
    # to select direction to fill the matrix
    # adding by columns
    add_row, add_col = 0, 1
    
    # cycle by all numbers (start = 0 , end = matrix_size^2)
    for number in range(matix_size**2):
        
        # adding by row and columns number + 1
        matrix[row][col] = number + 1
        
        # calculate next row and colum.in first cycle then
        # row/column + select direction row/column.
        # EXAMPLE: in first cycle:
        #         next_row = 0 (row(0) + add_row(0))
        #         next_col = 1 (col(0) + add_col(1))
        next_row = row + add_row
        next_col = col + add_col
        
        # if next_row and next_col are inside the matix boundaries
        # then: row = next_row and col = next_col
        # else: Reverse direction and adding in select direction for rows minus
        #       that to fill in vertically
        if 0 <= next_row < matix_size\
            and 0 <= next_col < matix_size\
                and matrix[next_row][next_col] == 0:
            
            row, col = next_row, next_col
        else:
            add_row, add_col = add_col, -add_row
            
            row, col = row + add_row, col + add_col
    
    print('\nSPIRAL MATRIX:')
    for col in matrix:
        print(*col)
