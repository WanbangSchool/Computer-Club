def calculate_stats(data):
    annual_salaries = []
    for years, contract_value in data:
        annual_salary = contract_value / years
        annual_salaries.append(annual_salary)

    # 1천만 달러 이상인 연봉의 개수
    more_than_10_million = len([salary for salary in annual_salaries if salary > 10000000])

    # 평균 연봉
    average_annual_salary = int(sum(annual_salaries) / len(annual_salaries))

    # 16경기 시즌 최저 경기당 급여
    lowest_salary_per_game_16 = int(min(annual_salaries) / 16)

    # 18경기 시즌 최고 경기당 급여
    highest_salary_per_game_18 = int(max(annual_salaries) / 18)

    # 16경기 시즌과 18경기 시즌의 평균 경기당 급여 차이
    average_salary_per_game_16 = int(sum(annual_salaries) / len(annual_salaries) / 16)
    average_salary_per_game_18 = int(sum(annual_salaries) / len(annual_salaries) / 18)
    difference = average_salary_per_game_16 - average_salary_per_game_18

    return more_than_10_million, average_annual_salary, lowest_salary_per_game_16, highest_salary_per_game_18, difference

# 입력 데이터
data = []
for _ in range(5):
    line = input().split()
    years = int(line[0])
    contract_value = float(line[1]) * 1000000
    data.append((years, contract_value))

# 결과 계산 및 출력
results = calculate_stats(data)
for result in results:
    print(result)