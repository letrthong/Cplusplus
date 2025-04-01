class Animal:
    def speak(self):
        print("Animal speaks")

class Dog(Animal):
    def speak(self):
        print("Dog barks")

# Create instances
animal = Animal()
dog = Dog()

# Call the speak method
animal.speak()  # Output: Animal speaks
dog.speak()     # Output: Dog barks
