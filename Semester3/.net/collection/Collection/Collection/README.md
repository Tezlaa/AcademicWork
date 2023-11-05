#### Condition:
```
Комплект Collection

Завдання 1. Розв’яжіть задачу з використанням колекції
Dictionary<TKey, TValue>.
Заданий перелік з N ігор футбольних команд з результатами матчів у
вигляді масиву рядків. Формат кожного рядка такий:
Назва_1_команди;Голів_1_команди;Назва_2_команди;Голів_2_команди
Розробити програму, яка повертає зведену таблицю результатів усіх матчів,
якщо відомо, що за перемогу команді нараховується 3 очки, за поразку – 0 очок,
за нічию – 1 очко. Таблиця результатів повинна мати такий вигляд:
Назва_Команди: Усього_ігор Перемог Нічиїх Поразок Всього_очків
При створенні програми реалізувати наступний інтерфейс:
interface ILab8DictionaryPart
{
/// <summary>
/// Returns dictionary with stats of teams in current moment
/// </summary>
public Dictionary<string, TeamResult> Stats { get; }
/// <summary>
/// Add to the stats results of game. Method automatically chose the winner and update Stats
dictionary.
/// </summary>
public void AddGame(string firstTeamName, int firstTeamGoals, string secondTeamName,

int secondTeamGoals);

}
class TeamResult
{
public int NumberOfGames { get; set; }
public int Wins { get; set; }
public int Loses { get; set; }
public int Draws { get; set; }
public int SumOfPoints { get; set; }
}
Додаткове завдання (2 бали): Організуйте зчитування вхідних даних з
файлу, а також збереження результатів виконання роботи в інший файл у тій
самій директорії.
Завдання 2. Розв’яжіть задачу з використанням колекції Stack<T>
Заданий рядок символів, який закінчується “;”. Рядок може містити
відкриваючі та закриваючі фігурні, круглі, квадратні, кутові дужки. Розробити
програму, яка перевіряє, чи вірно розміщені дужки у рядку. При цьому необхідно,
щоб виконувались наступні правила:
1. Кожна відкриваюча дужка повинна мати справа таку саму закриваючу
дужку. Зворотне твердження також має бути вірним.

2. Відкриваючі та закриваючі пари дужок різних типів мають бути
правильно розташовані відповідно один одного.
Приклад коректного рядка: ({x-y-z}*[x+2y]-(z+4x));
Приклад некоректного рядка: ([x-y-z}*[x+2y)-{z+4x)].
Розв'язок оформити у вигляді окремого методу IsCorrect, що приймає
введений рядок та повертає логічне значення, яке відповідає на питання – чи
коректний заданий рядок. Крім того, метод має повертати кількість вдало
оброблених символів рядка за допомогою параметра метода.
Завдання 3. Розв’яжіть задачу з використанням колекції Queue<T>.
Задана деяка послідовність натуральних чисел. Надрукувати в порядку
збільшення N таких чисел послідовності, в розкладання яких на прості множники
входять тільки прості числа A, B, C у будь якій комбінації.
Наприклад, якщо А = 2, В = 3, С = 5, то перші 10 чисел будуть 2, 3, 4, 5, 6, 8,
9, 10, 12, 15.
Підказка: оптимальним буде використання класу Queue<int> у якості
приватного поля (можливо кілька разів).
Розв'язок оформити у вигляді окремого класу, в який інкапсульовано
рішення. В конструктор класу передаються значення А, В, С. Наявний відкритий
метод, що приймає значення N та повертає список List<int>, який містить перші N
чисел послідовності.
При створенні програми реалізувати наступний інтерфейс.
interface ILab8QueuePartBasicLevel
{
public int A { get; set; }
public int B { get; set; }
public int C { get; set; }
/// <summary>
/// Method returns list of elements, that can be divided by A, B or C in ascending order
/// </summary>
/// <param name="N">Lenght of sequence (number of elements)</param>
/// <returns>List of elements, that can be divided by A, B or C in ascending order</returns>
public List<int> GetSequence(int N);
}
```

![screenshot](https://github.com/Tezlaa/AcademicWork/blob/main/Semester3/.net/collection/Collection/Collection/screenshots/Screenshot_1.png)