# Getting Data
with open("data.in") as file:
    data = [i for i in file.read().strip().split("\n")]
print(data)
