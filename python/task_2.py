print('Задание №2')
holiday = input('Праздник (1 или 0): ')
temperature = input('Температура на улице: ')
age = input('Возраст: ')
temperature_limit = input('Предел температуры: ')
age_limit = input('Максимальный возраст начальной школы: ')
if holiday == 1:
    print('\nИдем к друзьям')
elif int(temperature) > int(temperature_limit):
    print('\nВ школу :(')
elif int(age) < int(age_limit):
    print('\nСидим дома :)')
else:
    print('\nТащимся в школу :(')
