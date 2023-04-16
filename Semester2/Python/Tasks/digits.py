from collections import namedtuple
from typing import Dict, List


Student = namedtuple('Student',
                     'initials score_math score_physics score_literature')


def get_value(element) -> float:
    """_summary_

    Args:
        element (_type_): _description_

    Returns:
        float: _description_
    """
    return list(element.values())[0]


def select_by_passing_score(ranking: List[Dict[str, float]], score: float) -> List[Dict[str, float]]:
    """_summary_

    Args:
        ranking (List[Dict[str, float]]): _description_
        score (float): _description_

    Returns:
        List[Dict[str, float]]: _description_
    """
    
    result = []
    for student in ranking:
        if list(student.values())[0] > score:
            result.append(student)
    
    return result


def ranking_students(students: List[Student]) -> List[Dict[str, float]]:
    """_summary_

    Args:
        students (List[Student]): _description_

    Returns:
        List[Dict[str, float]]: _description_
    """
    
    ranking = []
    for student in students:
        amount_score = 0
        quantity_object = 0
        
        for field in range(len(student)):
            if student._fields[field].find('score_') != -1:
                amount_score += student[field]
                quantity_object += 1
        
        ranking.append({student.initials: float('%.2f' % (amount_score / quantity_object))})

    ranking.sort(key=get_value, reverse=True)
    return ranking


def filling_student_info() -> List[Student]:
    """_summary_

    Returns:
        List[Student]: _description_
    """
    
    students = []
    
    while True:
        students.append(
            Student(
                initials=input('Write the initials of the student: '),
                score_math=int(input('Him score in math: ')),
                score_physics=int(input('Him score in physics: ')),
                score_literature=int(input('Him score in litetature: ')),
            )
        )
        
        select_path = input('Add next student?(y-Yes, n-No): ').lower()
        if select_path != 'y':
            return students
        
            
if __name__ == "__main__":
    students = filling_student_info()
    ranking = ranking_students(students)
    passing_ranking = select_by_passing_score(ranking, float(input('Write passing score: ')))
    
    print(
        f'\nBest score average: {list(ranking[0].keys())[0]} - {list(ranking[0].values())[0]}\n'
        f'Lowest score average: {list(ranking[-1].keys())[0]} - {list(ranking[-1].values())[0]}\n'
    )
    for student in passing_ranking:
        print(f'{list(student.keys())[0]} - {list(student.values())[0]}')
        
    print()