import random

MAX_LEVEL = 7

class Node:
    def __init__(self, value, level):
        self.value = value
        self.forward = [None] * (level + 1)

class SkipList:
    def __init__(self):
        self.probability = 0.5
        self.level = 0
        self.head = Node(None, MAX_LEVEL)

    def is_empty(self):
        return self.level == 0 and self.head.forward[0] is None

    def random_level_generator(self):
        level = 0
        while random.random() < self.probability and level < MAX_LEVEL:
            level += 1
        return level

    def insert_data(self, value):
        current = self.head
        update = [None] * (MAX_LEVEL + 1)

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < value:
                current = current.forward[i]
            update[i] = current

        current = current.forward[0]

        if current is None or current.value != value:
            random_level = self.random_level_generator()

            if random_level > self.level:
                for i in range(self.level + 1, random_level + 1):
                    update[i] = self.head
                self.level = random_level

            new_node = Node(value, random_level)

            for i in range(random_level + 1):
                new_node.forward[i] = update[i].forward[i]
                update[i].forward[i] = new_node

            print(f"Successfully Inserted value: {value}")

    def search_data(self, search_data):
        if self.is_empty():
            print("\n---Skip list is Empty, Kindly Insert Data to Search---")
            return None

        current = self.head
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < search_data:
                current = current.forward[i]

        current = current.forward[0]

        if current and current.value == search_data:
            print(f"\nFound key: {current.value}")
            return current
        else:
            print(f"\n---This Value [{search_data}] Does Not Exist in the Skip List---")
            return None

    def remove_data(self, delete_data):
        if self.is_empty():
            print("\n---Skip list is Empty, Kindly Insert Data to Delete---")
            return

        current = self.head
        update = [None] * (MAX_LEVEL + 1)

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].value < delete_data:
                current = current.forward[i]
            update[i] = current

        current = current.forward[0]

        if current and current.value == delete_data:
            for i in range(self.level + 1):
                if update[i].forward[i] != current:
                    break
                update[i].forward[i] = current.forward[i]

            print(f"\nKey Deleted: {current.value}")

            while self.level > 0 and self.head.forward[self.level] is None:
                print(f"\n--Empty Level [{self.level}] Vanished--")
                self.level -= 1
        else:
            print(f"\n---This Value [{delete_data}] Does Not Exist in the Skip List---")
            self.display_data()

    def display_data(self):
        if self.is_empty():
            print("\n---Skip list is Empty, Kindly Insert Data to Display---")
        else:
            print("\n<-----Displaying Whole Skip List----->")
            for i in range(self.level + 1):
                print(f"\nLevel {i}: ", end="")
                node = self.head.forward[i]
                while node:
                    print(node.value, end="\t")
                    node = node.forward[i]
                print()

def main():
    skip_list = SkipList()
    quit = False

    print("\n----------Skip List Program----------\n")

    while not quit:
        print("\n==============================")
        print("----Functions of Skip List----")
        print("==============================")
        print("\n1-> Insert Data")
        print("2-> Delete Data")
        print("3-> Search Data")
        print("4-> Display List")
        print("5-> Exit")

        option = input("\nEnter Option: ")

        if option == '1':
            value = int(input("\nEnter Value: "))
            skip_list.insert_data(value)
        elif option == '2':
            value = int(input("\nEnter Value To Delete: "))
            skip_list.remove_data(value)
        elif option == '3':
            value = int(input("\nEnter Value to be Searched: "))
            skip_list.search_data(value)
        elif option == '4':
            skip_list.display_data()
        elif option == '5':
            print("\n--Thank You, You can Leave---")
            quit = True
        else:
            print("\n---Invalid Option---")

if __name__ == "__main__":
    main()