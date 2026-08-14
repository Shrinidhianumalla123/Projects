tasks = []

while True:
    print("\n--- TO-DO LIST ---")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Mark Task as Done")
    print("4. Delete Task")
    print("5. Exit")

    choice = input("Enter your choice: ")

    #add
    if choice == "1":
        title = input("Enter task: ")
        task = {"title": title, "done": False}
        tasks.append(task)
        print("Task added!")

    # view
    elif choice == "2":
        if len(tasks) == 0:
            print("No tasks yet!")
        else:
            print("\nYour Tasks:")
            for i in range(len(tasks)):
                status = "✔" if tasks[i]["done"] else "✘"
                print(f"{i+1}. {tasks[i]['title']} [{status}]")

    elif choice == "3":
        num = int(input("Enter task number to mark as done: "))
        if 1 <= num <= len(tasks):
            tasks[num-1]["done"] = True
            print("Task marked as done!")
        else:
            print("Invalid task number!")

    #delete
    elif choice == "4":
        num = int(input("Enter task number to delete: "))
        if 1 <= num <= len(tasks):
            tasks.pop(num-1)
            print("Task deleted!")
        else:
            print("Invalid task number!")

    #exit
    elif choice == "5":
        print("Exiting To-Do List...")
        break

    else:
        print("Invalid choice! Try again.")
