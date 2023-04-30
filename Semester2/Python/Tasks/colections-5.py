from collections import namedtuple
from typing import Tuple, List


def split_on_two_team(text: List[str]) -> Tuple[dict]:
    """split on two tuple

    Args:
        text(List[str]): user input split by ';'

    Returns:
        Tuple[dict]: tuple with result dict
    """
    first_team = {'name': user_info[0],
                  'scored': user_info[1],
                  'win': 0, 'draw': 0, 'lose': 0, 'score': 0}
    second_team = {'name': user_info[2],
                   'scored': user_info[3],
                   'win': 0, 'draw': 0, 'lose': 0, 'score': 0}

    return first_team, second_team


def set_scored(first_team: dict, second_team: dict) -> Tuple[dict]:
    """calculate score
        if scored first team = scored second team:
            for first_team in 'draw' and 'score' +1
            for second_team in 'draw' and 'score' +1
        if team win:
            win team 'win' +3 and +1 in 'score'
            lose team 'lose' +1
    Args:
        first_team (dict)
        second_team (dict)

    Returns:
        Tuple[dict]: tuple with result dict where calculate result
    """
    
    if first_team['scored'] == second_team['scored']:
        first_team['draw'], first_team['score'] = 1, 1
        second_team['draw'], second_team['score'] = 1, 1
    else:
        if first_team['scored'] > second_team['scored']:
            first_team['win'], first_team['score'] = 1, 3
            second_team['lose'] = 1
        else:
            second_team['win'], second_team['score'] = 1, 3
            first_team['lose'] = 1

    return first_team, second_team


if __name__ == "__main__":
    how_many_matches = int(input("How many matches: "))
    team_info = {}
    
    print('How to write(First team;scored;Second team;scored)')
    for i in range(how_many_matches):
        user_info = input(f'Matches {i + 1}: ').split(';')
        
        first_team, second_team = set_scored(*split_on_two_team(user_info))

        for team in [first_team, second_team]:
            try:
                team_list = team_info[team['name']]
                
                team_list[0] += 1
                team_list[1] += team['win']
                team_list[2] += team['draw']
                team_list[3] += team['lose']
                team_list[4] += team['score']
            except KeyError:
                team_info[team['name']] = [1,
                                           team['win'],
                                           team['draw'],
                                           team['lose'],
                                           team['score']]
    
    for team in team_info.items():
        print(team[0], *team[1])