if __name__ == "__main__":
    #   args:
    #       value_tanker1, value_tanker2, value_tanker3 (int): max value for tanker
    #       tanker1, tanker2, tanker3 (float): how many filled tanker
    #       amount_all_gas(float): amount all gas (tanker1, tanker2, tanker3)
    #   raise:
    #       ValueError: if tanker more for his max value
    
    value_tanker1 = int(input('\nWrite value for first tanker: '))
    value_tanker2 = int(input('Write value for second tanker: '))
    value_tanker3 = int(input('Write value for third tanker: '))
    
    tanker1 = float(input(f'\nWrite how many filled first tanker (0-{value_tanker1}): '))
    tanker2 = float(input(f'Write how many filled second tanker (0-{value_tanker2}): '))
    tanker3 = float(input(f'Write how many filled third tanker (0-{value_tanker3}): '))
    
    if tanker1 > value_tanker1 or tanker2 > value_tanker2 or tanker3 > value_tanker3:
        raise ValueError('Error, write correct value')
    
    amount_all_gas = tanker1 + tanker2 + tanker3
    if amount_all_gas <= value_tanker1:
        print(f'\nTanker 1 holds all gas {amount_all_gas}/{value_tanker1}')
    elif amount_all_gas <= value_tanker2:
        print(f'\nTanker 2 holds all gas {amount_all_gas}/{value_tanker2}')
    elif amount_all_gas <= value_tanker3:
        print(f'\nTanker 3 holds all gas {amount_all_gas}/{value_tanker3}')
    else:
        print('\nNot possible!')