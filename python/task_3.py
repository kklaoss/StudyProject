distance = int(input('Введите расстояние между друзьями (в м.): '))
speed_friend_1 = int(input('Введите скорость первого друга (в м./с.): '))
speed_friend_2 = int(input('Введите скорость второго друга (в м./с.): '))
speed_dog = int(input('Введите скорость собаки (в м./с.): '))
distance_limit = int(input('Введите минимальное расстояние между друзьями (в м.): '))
dog_direction = int(input('К кому из друзей бежит собака (к 1 или к 2): '))
dog_move_count = 0
while distance_limit < distance:
    if dog_direction == 1:
        speed = speed_friend_1 + speed_dog
        dog_direction = 2
    else:
        speed = speed_friend_2 + speed_dog
        dog_direction = 1
    meet_time = distance / speed
    distance -= meet_time * (speed_friend_1 + speed_friend_2)
    dog_move_count += 1
print('\nКоличество встреч собаки с друзьями:', dog_move_count)
