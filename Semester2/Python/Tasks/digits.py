from collections import namedtuple
from typing import Dict, List


Student = namedtuple('Student',
                     'initials score_math score_physics score_literature')


def _get_value(element: Dict[str, float]) -> float:
    """Function to get the value in the sort method
    This function calls only the 'key' argument

    Args:
        element (Dict[str, float]): dict with name and avarage score

    Returns:
        float: return avarage score
    """
    return list(element.values())[0]


def select_by_passing_score(ranking: List[Dict[str, float]], score: float) -> List[Dict[str, float]]:
    """Function to search for students with available avarage score only

    Args:
        ranking (List[Dict[str, float]]): list with all ranking students
        score (float): What scort to write on the result list

    Returns:
        List[Dict[str, float]]: list with all students who have more score
    """
    
    result = []
    for student in ranking:
        if list(student.values())[0] > score:
            result.append(student)
    
    return result


def ranking_students(students: List[Student]) -> List[Dict[str, float]]:
    """Ranking student, take all students, give a sorted ranking list with all students

    Args:
        students (List[Student]): all student

    Returns:
        List[Dict[str, float]]: sorted list by avarage score
    """
    
    ranking = []
    for student in students:
        amount_score = 0
        quantity_object = 0
        
        for field in range(len(student)):
            # search by name with a score_ to add this score
            if student._fields[field].find('score_') != -1:
                amount_score += student[field]
                quantity_object += 1
                
        # add in list student initials and him avarage score by all search score
        # example list: [{'NAME': AVARAGE SCORE}]
        ranking.append({student.initials: float('%.2f' % (amount_score / quantity_object))})

    ranking.sort(key=_get_value, reverse=True)
    return ranking


def filling_student_info() -> List[Student]:
    """filling all list with students

    Returns:
        List[Student]: list with all student
            Example: [Student('NAME', 10, 9, 4, 5), ...]
    """
    
    students = []
    
    while True:
        students.append(
            Student(
                initials=input('\nWrite the initials of the student: '),
                score_math=float(input('Him score in math: ')),
                score_physics=float(input('Him score in physics: ')),
                score_literature=float(input('Him score in litetature: ')),
            ),
        )
        
        select_path = input('\nAdd next student?(y-Yes, n-No): ').lower()
        if select_path != 'y':
            return students
        
            
if __name__ == "__main__":
    students = filling_student_info()
    ranking = ranking_students(students)
    passing_ranking = select_by_passing_score(ranking, float(input('\nWrite passing score: ')))
    
    print(
        f'\nBest score average: {list(ranking[0].keys())[0]} - {list(ranking[0].values())[0]}\n'
        f'Lowest score average: {list(ranking[-1].keys())[0]} - {list(ranking[-1].values())[0]}\n'
    )
    for student in passing_ranking:
        print(f'{list(student.keys())[0]} - {list(student.values())[0]}')