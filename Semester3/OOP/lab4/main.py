import os
from typing import Iterable


class FileHasBeenChanged(Exception):
    def __init__(self, file_name: str) -> None:
        super().__init__(f"The file {file_name} has been changed!")


class SampleStatistic:
    def __init__(self, file_name: str = 'file.txt') -> None:
        self.file_name = file_name
        self.sample = self._download_sample_from_file()
        self.__time_file_changes = self.__get_time_file_changes()
    
    def __get_time_file_changes(self) -> float:
        return os.stat(self.file_name).st_mtime
    
    def __read_file(self) -> list[float]:
        with open(self.file_name, 'r', encoding='utf-8') as file:
            return [float(number) for number in file.readline().split(', ')]
    
    def __write_file(self, __itarable: Iterable) -> None:
        with open(self.file_name, 'w', encoding='utf-8') as file:
            file.write(', '.join(map(str, __itarable)))
    
    def _download_sample_from_file(self) -> list:
        full_statistic = self.__read_file()
        self.__step = len(full_statistic) // 3
        
        return full_statistic[self.__step: -self.__step]

    def _download_sample_to_file(self) -> None:
        if self.__time_file_changes != self.__get_time_file_changes():
            raise FileHasBeenChanged(self.file_name)
        
        full_statistic = self.__read_file()
        full_statistic[self.__step: -self.__step] = self.sample

        self.__write_file(full_statistic)
        self.__time_file_changes = self.__get_time_file_changes()

    def save_sample(self) -> None:
        self._download_sample_to_file()
    
    def display_sample(self) -> None:
        for i, number in enumerate(self.sample):
            print(f'№ {i} - {number}')
    
    def change_sample_element(self, index, new_element) -> None:
        self.sample[index] = new_element
    
    def mean(self) -> float:
        return self.sum_elements() / len(self)
    
    def variance(self) -> float:
        mean = self.mean()
        return sum((x - mean) ** 2 for x in self.sample) / len(self.sample)
    
    def standard_deviation(self) -> float:
        return self.variance() ** 0.5
    
    def sum_elements(self) -> float:
        return sum(self.sample)

    def min_element(self) -> float:
        return min(self.sample)
    
    def max_element(self) -> float:
        return max(self.sample)

    def __len__(self) -> int:
        return len(self.sample)


if __name__ == "__main__":
    filename = input("Введіть ім'я файлу для завантаження вибірки: ")
    statistics = SampleStatistic(filename)
    
    while True:
        print("1. Display the selection on the screen")
        print("2. Replace a selection item and save to file")
        print("3. Calculate and display the sample size")
        print("4. Calculate and display the sum of sample items")
        print("5. Calculate and display the maximum and minimum values of the sample")
        print("6. Calculate and display the average value of the sample items")
        print("7. Calculate and display the variance of the sample")
        print("8. Calculate and display the standard deviation of the sample")
        
        choice = input("Select the option: ")
        match choice:
            case '1':
                statistics.display_sample()
            case '2':
                index = int(input("Enter the index of the item to replace: "))
                value = float(input("Enter a new value: "))
                
                statistics.change_sample_element(index, value)
                statistics.save_sample()
            case '3':
                print("Sample size:", len(statistics))
            case '4':
                print("Sum of sample items:", statistics.sum_elements())
            case '5':
                max_value, min_value = statistics.max_element(), statistics.min_element()
                print("Maximum value:", max_value)
                print("Minimum value:", min_value)
            case '6':
                print("Average value:", statistics.mean())
            case '7':
                statistics.variance()
            case '8':
                print('Standard deviation: ', statistics.standard_deviation())