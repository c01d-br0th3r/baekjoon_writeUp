from collections import deque

def solution(n, t, m, timetable):
    answer = ''
    q = deque()
    minutes = []
    for time in timetable:
        h = time.split(':')[0]
        mi = time.split(':')[1]
        minutes.append(int(h) * 60 + int(mi))
    minutes.sort()
    for minute in minutes:
        q.append(minute)
    bus = 540
    ret = 0
    while True:
        n -= 1
        # 기다리는 사람이 같거나 많은 경우
        if len(q) >= m:
            # 막차일 경우
            if n == 0:
                first = q.popleft()
                if first > bus:
                    ret = bus
                else:
                    for _ in range(m - 1):
                        if (len(q) == 0):
                            break
                        first = max(first, q.popleft())
                    ret = first - 1
                break
            else:
                for _ in range(m):
                    now = q.popleft()
                    if bus < now:
                        q.appendleft(now)
        # 기다리는 사람이 더 적은 경우
        else:
            # 막차일 경우
            if n == 0:
                # 버스 시간 맞춰오면 됨
                ret = bus
                break
        bus += t
        
    ans_h = ret // 60
    ans_m = ret - ans_h * 60
    ans_h = str(ans_h)
    ans_m = str(ans_m)
    if (len(ans_h) == 1):
        ans_h = '0' + ans_h
    if (len(ans_m) == 1):
        ans_m = '0' + ans_m
    answer = ans_h + ":" + ans_m
    return answer
