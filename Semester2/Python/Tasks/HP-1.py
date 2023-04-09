if __name__ == "__main__":
    #   args:
    #       x(float): number that input
    #       number_for_cycle(int): number for the cycle that minus the number 'x'
    #       number_first(float): amount top
    #       number_second(float): amount down
    
    x = float(input("Write 'X': "))
    
    number_for_cycle = 1
    number_first = 1
    number_second = 1
    
    while number_for_cycle < 64:
        number_first *= (x - (number_for_cycle + 1))
        number_second *= (x - number_for_cycle)
        
        number_for_cycle += number_for_cycle + 1

    print(number_first / number_second)