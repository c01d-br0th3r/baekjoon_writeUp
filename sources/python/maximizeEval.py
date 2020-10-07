from itertools import permutations

def splitExpression(str):
    ret = []
    num = ''
    for s in str:
        if s.isdecimal():
            num += s
        else:
            ret.append(num)
            num = ''
            ret.append(s)
    ret.append(num)
    return ret

def solution(expression):
    answer = 0
    parse = splitExpression(expression)
    operators = ['+', '-', '*']
    for operator in permutations(operators, 3):
        cp_parse = parse[:]
        for ops in operator:
            idx = 0
            while idx < len(cp_parse):
                print(idx)
                if cp_parse[idx] == ops:
                    if ops == '+':
                        calc = int(cp_parse[idx-1]) + int(cp_parse[idx+1])
                    elif ops == '-':
                        calc = int(cp_parse[idx-1]) - int(cp_parse[idx+1])
                    else:
                        calc = int(cp_parse[idx-1]) * int(cp_parse[idx+1])
                    
                    cp_parse = cp_parse[:idx-1] + str(calc).split() + cp_parse[idx+2:]
                    
                else:
                    idx +=  1
                    
        answer = max(answer, abs(int(cp_parse[0])))
    
    return answer
