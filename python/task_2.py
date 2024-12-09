print('Задание №2')
holiday = str(input('Праздник (да или нет): '))
temperature = int(input('Температура на улице: '))
age = int(input('Возраст: '))
temperature_limit = int(input('Предел температуры: '))
age_limit = int(input('Максимальный возраст начальной школы: '))
if holiday == 'да':
    print('\nИдем к друзьям')
elif temperature > temperature_limit:
    print('\nВ школу :(')
elif age < age_limit:
    print('\nСидим дома :)')
else:
    print('\nТащимся в школу :(')
