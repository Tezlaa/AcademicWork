if __name__ == "__main__":
    #   args:
    #       number1, number2, number3, number4(float): number for search max and calculate avarage
    #       max_number(float): max number, defualt is number1
    #       amount(float): sum 3 numbers
        
    number1 = float(input('Write number 1: '))
    number2 = float(input('Write number 2: '))
    number3 = float(input('Write number 3: '))
    number4 = float(input('Write number 4: '))

    max_number = number1
    amount = number1 + number2 + number3 + number4
    
    if number2 > max_number:
        max_number = number2
    if number3 > max_number:
        max_number = number3
    if number4 > max_number:
        max_number = number4
    
    print(f"\nMax number: {max_number}, Amount: {amount - max_number}, result avarage {('%.2f' % ((amount - max_number) / 3))}")

   
    
