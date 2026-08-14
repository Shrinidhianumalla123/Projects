import random
import string

# pass gen
def generate_password(length):
    chars = string.ascii_letters + string.digits + string.punctuation
    password = ""
    
    for i in range(length):
        password += random.choice(chars)
    
    return password

# atrength check
def check_strength(password):
    score = 0

    if len(password) >= 8:
        score += 1
    if any(c.isupper() for c in password):
        score += 1
    if any(c.islower() for c in password):
        score += 1
    if any(c.isdigit() for c in password):
        score += 1
    if any(c in string.punctuation for c in password):
        score += 1

#check strengh
    if score <= 2:
        return "Weak"
    elif score == 3 or score == 4:
        return "Medium"
    else:
        return "Strong"

print("1. Generate Password")
print("2. Check Password Strength")

choice = input("Enter choice: ")

if choice == "1":
    length = int(input("Enter password length: "))
    pwd = generate_password(length)
    print("\nGenerated Password:", pwd)
    print("Strength:", check_strength(pwd))

elif choice == "2":
    pwd = input("Enter password: ")
    print("Strength:", check_strength(pwd))

else:
    print("Invalid choice!")
