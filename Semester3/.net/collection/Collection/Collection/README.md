#### Condition:
```
�������� Collection

�������� 1. �������� ������ � ������������� ��������
Dictionary<TKey, TValue>.
������� ������ � N ���� ���������� ������ � ������������ ������ �
������ ������ �����. ������ ������� ����� �����:
�����_1_�������;����_1_�������;�����_2_�������;����_2_�������
��������� ��������, ��� ������� ������� ������� ���������� ��� ������,
���� �����, �� �� �������� ������ ������������ 3 ����, �� ������� � 0 ����,
�� ���� � 1 ����. ������� ���������� ������� ���� ����� ������:
�����_�������: ������_���� ������� ͳ��� ������� ������_����
��� �������� �������� ���������� ��������� ���������:
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
��������� �������� (2 ����): ���������� ���������� ������� ����� �
�����, � ����� ���������� ���������� ��������� ������ � ����� ���� � ��
���� ��������.
�������� 2. �������� ������ � ������������� �������� Stack<T>
������� ����� �������, ���� ���������� �;�. ����� ���� ������
���������� �� ���������� ������, �����, ��������, ����� �����. ���������
��������, ��� ��������, �� ���� ������� ����� � �����. ��� ����� ���������,
��� ������������ ������� �������:
1. ����� ���������� ����� ������� ���� ������ ���� ���� ����������
�����. �������� ���������� ����� �� ���� �����.

2. ³��������� �� ���������� ���� ����� ����� ���� ����� ����
��������� ���������� �������� ���� ������.
������� ���������� �����: ({x-y-z}*[x+2y]-(z+4x));
������� ������������ �����: ([x-y-z}*[x+2y)-{z+4x)].
����'���� �������� � ������ �������� ������ IsCorrect, �� ������
�������� ����� �� ������� ������ ��������, ��� ������� �� ������� � ��
��������� ������� �����. ��� ����, ����� �� ��������� ������� �����
���������� ������� ����� �� ��������� ��������� ������.
�������� 3. �������� ������ � ������������� �������� Queue<T>.
������ ����� ����������� ����������� �����. ����������� � �������
��������� N ����� ����� �����������, � ����������� ���� �� ����� ��������
������� ����� ����� ����� A, B, C � ���� ��� ���������.
���������, ���� � = 2, � = 3, � = 5, �� ����� 10 ����� ������ 2, 3, 4, 5, 6, 8,
9, 10, 12, 15.
ϳ������: ����������� ���� ������������ ����� Queue<int> � �����
���������� ���� (������� ����� ����).
����'���� �������� � ������ �������� �����, � ���� ��������������
������. � ����������� ����� ����������� �������� �, �, �. ������� ��������
�����, �� ������ �������� N �� ������� ������ List<int>, ���� ������ ����� N
����� �����������.
��� �������� �������� ���������� ��������� ���������.
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