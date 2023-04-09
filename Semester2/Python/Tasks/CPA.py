if __name__ == "__main__":
    #   args:
    #       data_driver([[str, int, int, int], ]): all info about driver,
    #                                              index1 - number driver,
    #                                              index2 - ton
    #                                              index3 - distance
    #                                              index4 - payment
    #       cost_per_ton_km(int): cost per ton on km
    
    data_driver = [
        ['12311', 14, 2000],
        ['21233', 16, 2300],
        ['19900', 12, 1200],
        ['82332', 20, 700],
        ['65543', 15, 1900],
    ]
    cost_per_ton_km = 5
    
    for person in data_driver:
        person.append(person[1] * person[2] * cost_per_ton_km)  # append payment into info driver

        print(f'Driver №{person[0]} receive {person[3]}$')