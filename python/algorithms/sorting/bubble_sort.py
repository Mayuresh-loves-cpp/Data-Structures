def takeInput():
    print('Enter numbers: -')
    print('type (exit/e) to exit, (done/d) after you done entering numbersn\n')
    numbers = []
    ip = input(": ")
    while ip != 'exit' and ip != 'e' and ip != 'done' and ip != 'd':
        try:
            ip = int(ip)
            numbers.append(ip)
        except ValueError:
            print('sorting can be done with numbers only')
        ip = input(': ')
    if ip == 'e' or ip == 'exit':
        print()
        exit(0)
    elif ip == 'd' or ip == 'done':
        return numbers
    else:
        print('\nsomething went wrong while taking input\n')
        exit(1)


def sortList(list, type):
    if type == 'a':
        for i in range(len(list)):
            for j in range(len(list) - 1 - i):
                if list[j] > list[j + 1]:
                    (list[j], list[j + 1]) = (list[j + 1], list[j])
    elif type == 'd':
        for i in range(len(list)):
            for j in range(len(list) - 1 - i):
                if list[j] < list[j + 1]:
                    (list[j], list[j + 1]) = (list[j + 1], list[j])
    else:
        print('something went wrong! [wrong sorting type]')
    return list


def displayList(message, list):
    print(message, list)


def opeartions():
    print('\nBUBBLE SORT IN PYTHON\n')
    list = takeInput()
    ip = input('\nchoose sorting order ascending or descending (enter a or d) : ')
    while ip != "a" and ip != "d":
        ip = input('choose sorting order ascending or descending (enter a or d) : ')
    list = sortList(list, ip)
    print()
    displayList('sorted list', list)
    print()


opeartions()
