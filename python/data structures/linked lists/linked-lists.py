######### singly linked lists in Python #########

# ADT for linked list node
class Node:
    def __init__(self, value, linker) -> None:
        self.data = value
        self.link = linker


# global variables
headPointer = 0
endPointer = 0


# function to add node in list
def addNode(node):
    global headPointer, endPointer
    if headPointer != 0:
        endPointer.link = node
        endPointer = endPointer.link
    else:
        headPointer = node
        endPointer = node


# function to take input
def createList():
    print("Enter Nubers: -")
    ip = input(": ")
    while ip != 'exit' and ip != 'e' and ip != 'done' and ip != 'd':
        try:
            ip = int(ip)
            node = Node(ip, None)
            addNode(node)
        except ValueError:
            print('sorting can be done with numbers only')
        ip = input(': ')
    if ip == 'e' or ip == 'exit':
        print()
        exit(0)
    elif ip == 'd' or ip == 'done':
        return
    else:
        print('\nsomething went wrong while taking input\n')
        exit(1)


# function to display list
def displayList():
    traversePointer = headPointer
    print("\nContents of List are: -")
    while traversePointer:
        print(": ", traversePointer.data)
        traversePointer = traversePointer.link


# driver code
print("linked list in Python")
print("*tip: type -> (done/d) to done giving input, (exit/e) to exit")
createList()
displayList()
