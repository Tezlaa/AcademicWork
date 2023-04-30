if __name__ == "__main__":
    """
    args:
        numbers(list): split user text by space
            example: user text - 1 4 3 -> ['1', '4', '3']
        similar_numbers(set): set for the similar numbers
            example: list - ['1', '1', '3'] -> {'1'}
        result(str): args for the print result
            example: set - {'1', '3'} -> '1 3'

    """
    numbers = input('Write the numbers with a space: \n').split()
   
    similar_numbers = set()
    for number in numbers:
        if numbers.count(number) > 1:
            similar_numbers.add(number)
    
    result = ''
    for number in similar_numbers:
        result += f'{number} '
        
    print(result)